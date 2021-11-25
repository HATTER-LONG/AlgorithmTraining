#include "Tools/Tools.hpp"

class UpQueue
{
    vector<int> m_heap;

public:
    //上浮
    void swim(int pos)
    {
        while (pos > 1 && m_heap[pos / 2] < m_heap[pos])
        {
            swap(m_heap[pos / 2], m_heap[pos]);
            pos /= 2;
        }
    }

    //下沉
    void sink(int pos)
    {
        while (2 * pos <= static_cast<int>(m_heap.size()))
        {
            int i = 2 * pos;
            if (i < static_cast<int>(m_heap.size())
                && m_heap[i] < m_heap[i + 1])
            {
                i++;
            }
            if (m_heap[pos] >= m_heap[i])
            {
                break;
            }
            swap(m_heap[pos], m_heap[i]);
            pos = i;
        }
    }
    int top() { return m_heap[0]; }
    void push(int k)
    {
        m_heap.push_back(k);
        swim(m_heap.size() - 1);
    }
    void pop()
    {
        m_heap[0] = m_heap.back();
        m_heap.pop_back();
        sink(0);
    }
};
