#pragma once
#include "Noncopyable.h"

#include <functional>
#include <future>
#include <queue>

namespace Kangaroo
{
namespace Util
{
class ThreadPool : public Noncopyable
{
public:
    explicit ThreadPool(size_t);
    template <class F, class... Args>
    decltype(auto) enqueue(F&& f, Args&&... args);
    ~ThreadPool();

private:
    // need to keep track of threads so we can join them
    std::vector<std::thread> m_workers;
    // the task queue
    std::queue<std::packaged_task<void()> > m_tasks;

    // synchronization
    std::mutex m_queueMutex;
    std::condition_variable m_condition;
    bool m_stop;
};

// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t threads)
        : m_stop(false)
{
    for (size_t i = 0; i < threads; ++i)
        m_workers.emplace_back(
            [this]
            {
                for (;;)
                {
                    std::packaged_task<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(this->m_queueMutex);
                        this->m_condition.wait(lock, [this] { return this->m_stop || !this->m_tasks.empty(); });
                        if (this->m_stop && this->m_tasks.empty())
                            return;
                        task = std::move(this->m_tasks.front());
                        this->m_tasks.pop();
                    }

                    task();
                }
            });
}

// add new work item to the pool
template <class F, class... Args>
decltype(auto) ThreadPool::enqueue(F&& f, Args&&... args)
{
    using return_type = std::invoke_result_t<F, Args...>;

    std::packaged_task<return_type()> task(std::bind(std::forward<F>(f), std::forward<Args>(args)...));

    std::future<return_type> res = task.get_future();
    {
        std::unique_lock<std::mutex> lock(m_queueMutex);

        // don't allow enqueueing after stopping the pool
        if (m_stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");

        m_tasks.emplace(std::move(task));
    }
    m_condition.notify_one();
    return res;
}
}   // namespace Util
}   // namespace Kangaroo
