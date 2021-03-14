#pragma once
#include <functional>
#include <memory>
#include <string>
#include <vector>

struct ListNode
{
    int val;
    ListNode* next;
    // NOTE 用于删除链表释放内存
    ListNode* nextback;
    ListNode()
            : val(0)
            , next(nullptr)
            , nextback(next)
    {
    }
    ListNode(int x)
            : val(x)
            , next(nullptr)
            , nextback(next)
    {
    }
    ListNode(int x, ListNode* next)
            : val(x)
            , next(next)
            , nextback(next)
    {
    }
};

inline std::string transListNode2Str(const ListNode& ListNodeParam)
{
    std::string retStr;
    const ListNode* tmpNode = &ListNodeParam;
    const int deepth = 1000;
    int i = 0;
    while (tmpNode != nullptr && i++ < deepth)
    {
        retStr += std::to_string(tmpNode->val);
        if (tmpNode->next)
            retStr += " -> ";
        tmpNode = tmpNode->next;
    }
    return retStr;
}

inline void releaseListNode(ListNode* Node)
{
    while (Node != nullptr)
    {
        ListNode* nextPtr = Node->nextback;
        delete Node;
        Node = nextPtr;
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
        lastNode->next = loopNode;
    return ListNodePtr(retVal, std::function<void(ListNode*)>(releaseListNode));
}

inline ListNode* findLinstNode(ListNode* headList, int pos)
{
    ListNode* res = pos == -1 ? nullptr : headList;

    for (int i = 0; i < pos; i++)
    {
        if (res == nullptr)
            break;
        res = res->next;
    }
    return res;
}

#undef CATCH_CONFIG_FALLBACK_STRINGIFIER
#define CATCH_CONFIG_FALLBACK_STRINGIFIER(value) transListNode2Str(value)

#include <catch2/catch.hpp>

class IsEqualListNode : public Catch::MatcherBase<ListNode>
{
public:
    IsEqualListNode(ListNode& ListNodeParam)
            : m_listNode(ListNodeParam)
    {
    }
    bool match(ListNode const& Arg) const override
    {
        const ListNode* LeftPtr = &Arg;
        const ListNode* RightPtr = &m_listNode;
        while (LeftPtr != nullptr && RightPtr != nullptr)
        {
            if (LeftPtr->val != RightPtr->val)
            {
                return false;
            }
            LeftPtr = LeftPtr->next;
            RightPtr = RightPtr->next;
        }
        if (LeftPtr != nullptr || RightPtr != nullptr)
        {
            return false;
        }
        return true;
    }

    virtual std::string describe() const override
    {
        std::string LeftValue = transListNode2Str(m_listNode);
        LeftValue = "\nThe ListNode mismatching\n" + LeftValue;
        return LeftValue;
    }

private:
    const ListNode& m_listNode;
};
