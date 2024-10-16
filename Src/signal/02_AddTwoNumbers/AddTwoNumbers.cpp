#include "Tools/ListNodeTools.h"

#include <tuple>

using namespace Catch;
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* leftPtr, ListNode* rightPtr) {
        int pushNext = 0;
        ListNode* beginPtr = nullptr;
        ListNode* endPtr = nullptr;

        initBeginWithEndPtr(&beginPtr, &endPtr,
                            getNodeValueAndUpdateNextPush(leftPtr, rightPtr, pushNext));
        leftPtr = getNextNode(leftPtr);
        rightPtr = getNextNode(rightPtr);

        while(isComplete(leftPtr, rightPtr)) {
            int nodeValue = getNodeValueAndUpdateNextPush(leftPtr, rightPtr, pushNext);

            updateEndPtr(&endPtr, nodeValue);

            leftPtr = getNextNode(leftPtr);
            rightPtr = getNextNode(rightPtr);
        }
        if(pushNext != 0) {
            updateEndPtr(&endPtr, pushNext);
        }

        return beginPtr;
    }
    // TODO 此处内存泄漏问题待修改
    void updateEndPtr(ListNode** endPtr, int nodeValue) {
        (*endPtr)->next = new ListNode(nodeValue);
        (*endPtr) = (*endPtr)->next;
    }

    void initBeginWithEndPtr(ListNode** beginPtr, ListNode** endPtr, int nodeValue) {
        (*endPtr) = new ListNode(nodeValue);
        (*beginPtr) = (*endPtr);
    }

    int getNodeValueAndUpdateNextPush(ListNode* leftPtr, ListNode* rightPtr, int& pushNext) {
        int nodeValue = (getNodeValue(leftPtr) + getNodeValue(rightPtr) + pushNext);

        pushNext = nodeValue / 10;
        return nodeValue % 10;
    }

    bool isComplete(ListNode* leftPtr, ListNode* rightPtr) const {
        return leftPtr != nullptr || rightPtr != nullptr;
    }

    int getNodeValue(ListNode* Node) {
        if(Node != nullptr) {
            return Node->val;
        }
        return 0;
    }

    ListNode* getNextNode(ListNode* Node) {
        if(Node != nullptr) {
            return Node->next;
        }
        return nullptr;
    }
};

TEST_CASE("Check Solution addTwoNumbers method work successfully") {
    Solution solution;

    vector<int> LeftParm, RightParm, ResultParm;
    // clang-format off
        tie(LeftParm, RightParm, ResultParm) = 
            GENERATE(table<vector<int>, vector<int>, vector<int>>
                (
                    {
                        make_tuple(vector<int> { 2, 4, 3 }, vector<int> { 5, 6, 4 }, vector<int> { 7, 0, 8 }),

                        make_tuple(vector<int> { 9, 9, 9, 9, 9, 9, 9 }, 
                                   vector<int> { 9, 9, 9, 9 }, 
                                   vector<int> { 8, 9, 9, 9, 0, 0, 0, 1 }),
                    }
                    
                )
            );
    // clang-format on
    ListNodePtr LeftVal = initListNode(LeftParm);
    ListNodePtr RightVal = initListNode(RightParm);
    ListNodePtr ResultVal = initListNode(ResultParm);
    REQUIRE_THAT(*(solution.addTwoNumbers(LeftVal.get(), RightVal.get())),
                 IsEqualListNode(*ResultVal));
}
