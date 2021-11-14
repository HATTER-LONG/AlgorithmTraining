#include <cassert>
#include <catch2/catch.hpp>
#include <glog/logging.h>
#include <memory>

using ElemType = int;
class SqQueue
{
public:
    SqQueue(size_t size, size_t inc)
            : m_elem((ElemType*)malloc(size * sizeof(ElemType)))
            , m_top(0)
            , m_size(size)
            , m_increment(inc)
    {
        if (m_increment == 0)
        {
            LOG(WARNING) << "inc is zero, mabe overflow";
        }
        assert(m_elem != NULL);
    }
    ~SqQueue()
    {
        free(m_elem);
        m_elem = NULL;
    }

    bool isEmpty()
    {
        if (0 == m_top)
            return true;
        return false;
    }
    void clear()
    {
        if (m_top == 0)
            return;
        m_size = 0;
        m_top = 0;
    }
    bool push(ElemType e)
    {
        ElemType* newbase = NULL;
        if (m_top >= m_size)
        {
            newbase = (ElemType*)realloc(m_elem, (m_size + m_increment) * sizeof(ElemType));
            assert(newbase != NULL);
            m_elem = newbase;
            m_size += m_increment;
        }
        m_elem[m_top++] = e;
        return true;
    }
    bool pop(ElemType& e)
    {
        if (0 == m_top)
            return false;
        e = m_elem[m_top - 1];
        m_top--;
        return true;
    }
    bool getTop(ElemType& e)
    {
        if (0 == m_top)
            return false;
        e = m_elem[m_top - 1];
        return true;
    }

private:
    ElemType* m_elem;
    size_t m_top;
    size_t m_size;
    size_t m_increment;
};

TEST_CASE("init", "[SqQueue]")
{
    SqQueue sq(1, 1);
}

TEST_CASE("Insert data to queue", "[SqQueue]")
{
    SqQueue sq(1, 1);
    ElemType data = 1;
    sq.push(data);
    REQUIRE(sq.isEmpty() == false);
    ElemType res;
    sq.getTop(res);
    REQUIRE(data == res);

    res = 0;
    sq.pop(res);
    REQUIRE(data == res);
    REQUIRE(sq.isEmpty() == true);
}
