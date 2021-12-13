#include "Tools/ThreadPool.h"

using namespace Kangaroo::Util;

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(m_queueMutex);
        m_stop = true;
    }
    m_condition.notify_all();
    for (std::thread& worker : m_workers)
    {
        worker.join();
    }
}
