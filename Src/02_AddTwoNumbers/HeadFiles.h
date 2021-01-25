#pragma once
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

inline std::string transListNode2Str(const ListNode& ListNodeParam)
{
    std::string retStr;
    const ListNode* tmpNode = &ListNodeParam;
    while (tmpNode != nullptr)
    {
        retStr += std::to_string(tmpNode->val);
        if (tmpNode->next)
            retStr += " -> ";
        tmpNode = tmpNode->next;
    }
    return retStr;
}

inline std::unique_ptr<ListNode> initListNode(std::vector<int> param)
{
    ListNode* retVal = nullptr;
    for (int i = param.size() - 1; i >= 0; i--)
    {
        retVal = new ListNode(param[i], retVal);
    }

    return std::make_unique<ListNode>(*retVal);
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
