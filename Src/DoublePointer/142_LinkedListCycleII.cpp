#include "Tools/ListNodeTools.h"
#include "Tools/Tools.hpp"

ListNode* detectCycle(ListNode* head) {
    ListNode *fast = head, *slow = head;
    do {
        if(!fast || !fast->next)
            return nullptr;
        fast = fast->next->next;
        slow = slow->next;
    } while(fast != slow);

    fast = head;
    while(fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

TEST_CASE("Check detect cycle func") {
    VecInt inputParm;
    int inputParm2;

    tie(inputParm, inputParm2) = GENERATE(table<vector<int>, int>({
        make_tuple(vector<int>{3, 2, 0, -4}, 1),
        make_tuple(vector<int>{1, 2}, 0),
        make_tuple(vector<int>{1}, -1),
    }));

    auto listNodeHead = initListNode(inputParm, inputParm2);
    auto* resultParm = findListNode(listNodeHead.get(), inputParm2);
    REQUIRE(detectCycle(listNodeHead.get()) == (resultParm));
}
