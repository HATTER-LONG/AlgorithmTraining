#pragma once
#include <functional>
#include <memory>
#include <string>
#include <vector>

struct ListNode
{
    int m_val;
    ListNode* m_next;
    // NOTE 用于删除链表释放内存
    ListNode* m_nextback;
    ListNode()
            : m_val(0)
            , m_next(nullptr)
            , m_nextback(m_next)
    {
    }
    ListNode(int x)
            : m_val(x)
            , m_next(nullptr)
            , m_nextback(m_next)
    {
    }
    ListNode(int x, ListNode* next)
            : m_val(x)
            , m_next(next)
            , m_nextback(next)
    {
    }
};

inline std::string transListNode2Str(const ListNode& listNodeParam)
{
    std::string retStr;
    const ListNode* tmpNode = &listNodeParam;
    const int deepth = 1000;
    int i = 0;
    while (tmpNode != nullptr && i++ < deepth)
    {
        retStr += std::to_string(tmpNode->m_val);
        if (tmpNode->m_next)
            retStr += " -> ";
        tmpNode = tmpNode->m_next;
    }
    return retStr;
}

inline void releaseListNode(ListNode* node)
{
    while (node != nullptr)
    {
        ListNode* nextPtr = node->m_nextback;
        delete node;
        node = nextPtr;
    }
}

using ListNodePtr = std::unique_ptr<ListNode, std::function<void(ListNode*)>>;
inline ListNodePtr initListNode(std::vector<int> param, int loop = -1)
{
    ListNode* retVal = nullptr;
    ListNode* loopNode = nullptr;
    ListNode* lastNode = nullptr;
    for (int i = param.size() - 1; i >= 0; i--)
    {
        retVal = new ListNode(param[i], retVal);
        if (loop == i)
            loopNode = retVal;
        if (i == static_cast<int>(param.size() - 1))
            lastNode = retVal;
    }
    if (lastNode)
        lastNode->m_next = loopNode;
    return ListNodePtr(retVal, std::function<void(ListNode*)>(releaseListNode));
}

inline ListNode* findLinstNode(ListNode* headList, int pos)
{
    ListNode* res = pos == -1 ? nullptr : headList;

    for (int i = 0; i < pos; i++)
    {
        if (res == nullptr)
            break;
        res = res->m_next;
    }
    return res;
}

#undef CATCH_CONFIG_FALLBACK_STRINGIFIER
#define CATCH_CONFIG_FALLBACK_STRINGIFIER(value) transListNode2Str(value)

#include <catch2/catch.hpp>

class IsEqualListNode : public Catch::MatcherBase<ListNode>
{
public:
    IsEqualListNode(ListNode& listNodeParam)
            : m_listNode(listNodeParam)
    {
    }
    bool match(ListNode const& arg) const override
    {
        const ListNode* leftPtr = &arg;
        const ListNode* rightPtr = &m_listNode;
        while (leftPtr != nullptr && rightPtr != nullptr)
        {
            if (leftPtr->m_val != rightPtr->m_val)
            {
                return false;
            }
            leftPtr = leftPtr->m_next;
            rightPtr = rightPtr->m_next;
        }
        if (leftPtr != nullptr || rightPtr != nullptr)
        {
            return false;
        }
        return true;
    }

    virtual std::string describe() const override
    {
        std::string leftValue = transListNode2Str(m_listNode);
        leftValue = "\nThe ListNode mismatching\n" + leftValue;
        return leftValue;
    }

private:
    const ListNode& m_listNode;
};
