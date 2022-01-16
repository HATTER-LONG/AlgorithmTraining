#include "Tools/ThreadCompetition.hpp"
#include "Tools/Tools.hpp"

#include <future>
#include <mutex>
#include <shared_mutex>
/*
 问题：//评测题目:
// 编程模拟实现并发读写，写线程和读线程共享一个char[]
buffer，初始化值buffer="hello1"，
// 写线程有3个，读线程有10个。
// 写线程每隔1分钟，随机生成一个长度为10的字符串，并更新buffer的内容；
// 每个读线程每100毫秒读取一次buffer当前的内容，并且打印出来。
// 要求尽量考虑程序整体的性能最优，同时不允许出现脏读幻读。
*/



class ReadWriteBuffer
{
public:
    void write(const std::string& str)
    {
        std::vector<char> tmp(10);
        tmp.assign(str.begin(), str.end());
        {
            std::lock_guard<std::mutex> lk(m_mReadMutex);
            m_buf.swap(tmp);
        }
    }

    std::string read()
    {
        std::string str;
        {
            std::lock_guard<std::mutex> lk(m_mReadMutex);
            str.assign(m_buf.begin(), m_buf.end());
        }
        return str;
    }

private:
    std::vector<char> m_buf { 'h', 'e', 'l', 'l', 'o',   // NO_LINT
        ' ', ' ', ' ', ' ', ' ' };
    std::mutex m_mReadMutex;
};


class ReadWriteBufferII
{
public:
    void write(const std::string& str)
    {
        std::vector<char> tmp(10);
        tmp.assign(str.begin(), str.end());
        {
            std::lock_guard<std::shared_mutex> lk(m_mReadMutex);
            m_buf.swap(tmp);
        }
    }

    std::string read()
    {
        std::string str;
        {
            std::shared_lock<std::shared_mutex> lk(m_mReadMutex);
            str.assign(m_buf.begin(), m_buf.end());
        }
        return str;
    }

private:
    std::vector<char> m_buf { 'h', 'e', 'l', 'l', 'o',   // NO_LINT
        ' ', ' ', ' ', ' ', ' ' };
    std::shared_mutex m_mReadMutex;
};


TEST_CASE("test read write buffer", "[.]")
{
    /* ReadWriteBuffer buf; */
    ReadWriteBufferII buf;
    ThreadCompetition write(3);
    ThreadCompetition read(10);

    std::vector<std::future<bool>> result;
    auto randStr = [](std::string& str, const int len, uint64_t tid)
    {
        srand(time(nullptr) + tid);
        int i;
        for (i = 0; i < len; ++i)
        {
            switch ((rand() % 3))
            {
                case 1:
                    str[i] = 'A' + rand() % 26;
                    break;
                case 2:
                    str[i] = 'a' + rand() % 26;
                    break;
                default:
                    str[i] = '0' + rand() % 10;
                    break;
            }
        }
    };

    for (int i = 0; i < 3; i++)
    {
        result.emplace_back(write.enqueue(
            [&]
            {
                while (true)
                {
                    sleep(1);
                    std::string str = "1234567890";
                    uint64_t tid = 0;
                    pthread_threadid_np(0, &tid);
                    randStr(str, 10, tid);
                    buf.write(str);
                }
                return true;
            },
            i));
    }
    for (int i = 0; i < 10; i++)
    {
        result.emplace_back(read.enqueue(
            [&]
            {
                while (true)
                {
                    usleep(100);
                    std::string str = buf.read();
                    LOG(INFO) << "read = " << str;
                }
                return true;
            },
            i));
    }
    write.notifyAllThreads();
    read.notifyAllThreads();
}
