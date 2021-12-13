#pragma once

#include <condition_variable>
#include <functional>
#include <future>
#include <memory>
#include <mutex>
#include <queue>
#include <stdexcept>
#include <thread>
#include <unistd.h>
#include <vector>

class ThreadCompetition
{
public:
    ThreadCompetition(size_t threads);
    template <class F, class... Args>
    auto enqueue(F&& func, Args&&... paramArgs, const size_t& threadId)
        -> std::future<typename std::result_of<F(Args...)>::type>;
    void notifyAllThreads();
    ~ThreadCompetition();

private:
    // need to keep track of threads so we can join them
    std::vector<std::thread> m_workers;
    // the task queue
    std::vector<std::queue<std::function<void()>>> m_tasks;
    std::vector<std::mutex> m_queueMutex;

    std::condition_variable m_condition;
    std::atomic<bool> m_stop;
    std::atomic<bool> m_startWork;
};

// the constructor just launches some amount of workers
inline ThreadCompetition::ThreadCompetition(size_t threads)
        : m_tasks(threads)
        , m_queueMutex(threads)
        , m_stop(false)
        , m_startWork(false)
{
    for (size_t i = 0; i < threads; ++i)
    {
        m_workers.emplace_back(
            [this, i]
            {
                const auto threadid = i;
                for (;;)
                {
                    std::function<void()> task;
                    {
                        bool taskempty = true;
                        // 未使用条件锁 可以模拟线程乱序
                        // this->m_condition.wait(lock, [this]
                        // { return this->m_stop || !this->m_tasks.empty(); });
                        while (!this->m_startWork || taskempty)
                        {
                            usleep(1);
                            std::unique_lock<std::mutex> lock(
                                m_queueMutex[threadid]);
                            taskempty = this->m_tasks[threadid].empty();
                            if (this->m_stop)
                                break;
                        }
                        std::unique_lock<std::mutex> lock(
                            m_queueMutex[threadid]);
                        if (this->m_stop && this->m_tasks[threadid].empty())
                            return;

                        task = std::move(this->m_tasks[threadid].front());
                        this->m_tasks[threadid].pop();
                    }

                    task();
                }
            });
    }
}

// add new work item to the pool
template <class F, class... Args>
auto ThreadCompetition::enqueue(
    F&& func, Args&&... paramArgs, const size_t& threadId)
    -> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;

    auto task = std::make_shared<std::packaged_task<return_type()>>(
        std::bind(std::forward<F>(func), std::forward<Args>(paramArgs)...));

    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(m_queueMutex[threadId]);

        // don't allow enqueueing after stopping the pool
        if (m_stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");

        m_tasks[threadId].emplace([task]() { (*task)(); });
    }
    return res;
}

inline void ThreadCompetition::notifyAllThreads()
{
    m_startWork = true;
}

// the destructor joins all threads
inline ThreadCompetition::~ThreadCompetition()
{
    m_stop = true;
    m_condition.notify_all();
    for (std::thread& worker : m_workers)
        worker.join();
}
