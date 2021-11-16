#include "Tools/Tools.hpp"

#include "Tools/ListNodeTools.h"

ListNode* detectCycle(ListNode* head)
{
    ListNode* fast = head, *slow = head;

    //判断是否存在环路
    do {
        if(!fast || !fast->next) return nullptr;
        fast = fast->next->next;
        slow = slow->next;
    }while(fast != slow);

    //查找环点
    fast = head;
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

TEST_CASE("Check detect cycle func")
{
    VecInt inputParm;
    int inputParm2;
    
    tie(inputParm, inputParm2) = GENERATE(table<vector<int>, int>({
        make_tuple(vector<int> { 3, 2, 0, -4 }, 1),
        make_tuple(vector<int> { 1, 2 }, 0),
        make_tuple(vector<int> { 1 }, -1),
    }));

    auto listNodeHead = initListNode(inputParm, inputParm2);
    auto* resultParm = findListNode(listNodeHead.get(), inputParm2);
    REQUIRE(detectCycle(listNodeHead.get()) == (resultParm));
}
