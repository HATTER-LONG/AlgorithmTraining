#pragma once
#include <cstddef>
#include <functional>
#include <glog/logging.h>
#include <memory>
#include <string>
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

inline std::string transListNode2Str(const ListNode* listNodeParam)
{
    if (listNodeParam == nullptr)
        return std::string("nullptr");
    std::string retStr;
    const ListNode* tmpNode = listNodeParam;
    const int deepth = 1000;
    int i = 0;
    while (tmpNode != nullptr && i++ < deepth) {
        retStr += std::to_string(tmpNode->val);
        if (tmpNode->next)
            retStr += " -> ";
        tmpNode = tmpNode->next;
    }
    return retStr;
}

inline void releaseListNode(ListNode* node)
{
    while (node != nullptr) {
        ListNode* nextPtr = node->next;
        delete node;
        node = nextPtr;
    }
}

inline ListNode* initListNode(std::vector<int> param, int loop = -1)
{
    ListNode* retVal = nullptr;
    ListNode* loopNode = nullptr;
    ListNode* lastNode = nullptr;
    for (int i = param.size() - 1; i >= 0; i--) {
        retVal = new ListNode(param[i], retVal);
        if (loop == i)
            loopNode = retVal;
        if (i == static_cast<int>(param.size() - 1))
            lastNode = retVal;
    }
    if (lastNode)
        lastNode->next = loopNode;
    return retVal;
}

inline ListNode* findListNode(ListNode* headList, int pos)
{
    ListNode* res = pos == -1 ? nullptr : headList;

    for (int i = 0; i < pos; i++) {
        if (res == nullptr)
            break;
        res = res->next;
    }
    return res;
}


#include <catch2/catch_all.hpp>

class IsEqualListNode : public Catch::Matchers::MatcherBase<ListNode>
{
public:
    IsEqualListNode(ListNode* listNodeParam)
            : m_listNode(listNodeParam)
    {
    }
    bool match(ListNode const& arg) const override
    {
        const ListNode* leftPtr = &arg;
        const ListNode* rightPtr = m_listNode;
        while (leftPtr != nullptr && rightPtr != nullptr) {
            if (leftPtr->val != rightPtr->val) {
                return false;
            }
            leftPtr = leftPtr->next;
            rightPtr = rightPtr->next;
        }
        if (leftPtr != nullptr || rightPtr != nullptr) {
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
    const ListNode* m_listNode;
};


#define checkListNode(LEFT, RIGHT)                                                                 \
    CAPTURE(transListNode2Str(LEFT), transListNode2Str(RIGHT));                                    \
    if (LEFT != nullptr)                                                                           \
        REQUIRE_THAT(*LEFT, IsEqualListNode(RIGHT));                                               \
    else if (LEFT == nullptr)                                                                      \
        REQUIRE(LEFT == RIGHT);
