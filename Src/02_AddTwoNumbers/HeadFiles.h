#pragma once
#include <functional>
#include <memory>
#include <spdlog/spdlog.h>
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
    while (tmpNode != nullptr) {
        retStr += std::to_string(tmpNode->val);
        if (tmpNode->next)
            retStr += " -> ";
        tmpNode = tmpNode->next;
    }
    return retStr;
}



inline void releaseListNode(ListNode* Node)
{
    while (Node != nullptr) {
        ListNode* nextPtr = Node->nextback;
        delete Node;
        Node = nextPtr;
    }
}

using ListNodePtr = std::unique_ptr<ListNode, std::function<void(ListNode*)>>;
inline ListNodePtr initListNode(std::vector<int> param)
{
    ListNode* retVal = nullptr;
    for (int i = param.size() - 1; i >= 0; i--) {
        retVal = new ListNode(param[i], retVal);
    }
    return ListNodePtr(retVal, std::function<void(ListNode*)>(releaseListNode));
}
