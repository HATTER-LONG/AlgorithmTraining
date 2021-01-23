#pragma once
#include <catch2/catch.hpp>
#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode()
            : val(0)
            , next(nullptr)
    {
    }
    ListNode(int x)
            : val(x)
            , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
            : val(x)
            , next(next)
    {
    }
};

inline void printListNode(const ListNode* ListNodeParam)
{
    while (ListNodeParam != nullptr)
    {
        std::cout << ListNodeParam->val;
        if (ListNodeParam->next)
            std::cout << " -> ";
        ListNodeParam = ListNodeParam->next;
    }
    std::cout << std::endl;
}

inline ListNode* initListNode(std::vector<int> param)
{
    ListNode* retVal = nullptr;
    for (int i = param.size() - 1; i >= 0; i--)
    {
        retVal = new ListNode(param[i], retVal);
    }

    return retVal;
}

inline void releaseListNode(ListNode* Node)
{
    while (Node != nullptr)
    {
        ListNode* nextPtr = Node->next;
        delete Node;
        Node = nextPtr;
    }
}

class IsEqualListNode : public Catch::MatcherBase<ListNode>
{
public:
    IsEqualListNode(ListNode& ListNodeParam)
            : m_listNode(ListNodeParam)
    {
    }
    bool match(ListNode const& Arg) const override
    {
        const ListNode* tmpPtr = &Arg;
        const ListNode* tmpPtr2 = &m_listNode;

        while (tmpPtr != nullptr && tmpPtr2 != nullptr)
        {

            if (tmpPtr->val != tmpPtr2->val)
            {
                printListNode(&Arg);
                std::cout << " != " << std::endl;
                printListNode(&m_listNode);
                return false;
            }
            tmpPtr = tmpPtr->next;
            tmpPtr2 = tmpPtr2->next;
        }

        if (tmpPtr != nullptr || tmpPtr2 != nullptr)
        {
            return false;
        }
        return true;
    }

    virtual std::string describe() const override { return "is empty about  Address Info"; }

private:
    ListNode& m_listNode;
};
