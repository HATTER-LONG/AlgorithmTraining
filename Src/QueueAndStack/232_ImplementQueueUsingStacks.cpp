#include "Tools/Tools.hpp"

#include <stack>

/*尝试使用栈(stack)来实现队列(queue)。*/

class MyQueue {
    stack<int> m_in;
    stack<int> m_out;

public:
    MyQueue() = default;
    void push(int i) { m_in.push(i); }

    int pop() {
        in2out();
        int x = m_out.top();
        m_out.pop();
        return x;
    }

    int peek() {
        in2out();
        return m_out.top();
    }

    void in2out() {
        if(m_out.empty()) {
            while(!m_in.empty()) {
                int x = m_in.top();
                m_in.pop();
                m_out.push(x);
            }
        }
    }

    bool empty() { return m_out.empty() && m_in.empty(); }
};
