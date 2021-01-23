#include "HeadFiles.h"

using namespace Catch;
using namespace std;

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* leftPtr, ListNode* rightPtr)
    {
        int pushNext = 0;
        ListNode* beginPtr = nullptr;
        ListNode* endPtr = nullptr;

        initBeginWithEndPtr(&beginPtr, &endPtr, getNodeValueAndUpdateNextPush(leftPtr, rightPtr, pushNext));
        leftPtr = getNextNode(leftPtr);
        rightPtr = getNextNode(rightPtr);

        while (isComplete(leftPtr, rightPtr))
        {
            int nodeValue = getNodeValueAndUpdateNextPush(leftPtr, rightPtr, pushNext);

            updateEndPtr(&endPtr, nodeValue);

            leftPtr = getNextNode(leftPtr);
            rightPtr = getNextNode(rightPtr);
        }
        if (pushNext != 0)
        {
            updateEndPtr(&endPtr, pushNext);
        }

        return beginPtr;
    }

    void updateEndPtr(ListNode** endPtr, int nodeValue)
    {
        (*endPtr)->next = new ListNode(nodeValue);
        (*endPtr) = (*endPtr)->next;
    }

    void initBeginWithEndPtr(ListNode** beginPtr, ListNode** endPtr, int nodeValue)
    {
        (*endPtr) = new ListNode(nodeValue);
        (*beginPtr) = (*endPtr);
    }

    int getNodeValueAndUpdateNextPush(ListNode* leftPtr, ListNode* rightPtr, int& pushNext)
    {
        int nodeValue = (getNodeValue(leftPtr) + getNodeValue(rightPtr) + pushNext);

        pushNext = nodeValue / 10;
        return nodeValue % 10;
    }

    bool isComplete(ListNode* leftPtr, ListNode* rightPtr) const
    {
        return leftPtr != nullptr || rightPtr != nullptr;
    }

    int getNodeValue(ListNode* Node)
    {
        if (Node != nullptr)
        {
            return Node->val;
        }
        return 0;
    }

    ListNode* getNextNode(ListNode* Node)
    {
        if (Node != nullptr)
        {
            return Node->next;
        }
        return nullptr;
    }
};

// TODO: 重构下这部分重复代码
TEST_CASE("Check Solution addTwoNumbers method work successfully")
{
    Solution solution;

    SECTION("default data")
    {
        ListNode* LeftVal = initListNode({ 2, 4, 3 });
        ListNode* RightVal = initListNode({ 5, 6, 4 });
        ListNode* ResultVal = initListNode({ 7, 0, 8 });

        REQUIRE_THAT(*(solution.addTwoNumbers(LeftVal, RightVal)), IsEqualListNode(*ResultVal));

        releaseListNode(LeftVal);
        releaseListNode(RightVal);
        releaseListNode(ResultVal);
    }

    SECTION("Unmatched data")
    {
        ListNode* LeftVal = initListNode({ 9, 9, 9, 9, 9, 9, 9 });
        ListNode* RightVal = initListNode({ 9, 9, 9, 9 });
        ListNode* ResultVal = initListNode({ 8, 9, 9, 9, 0, 0, 0, 1 });

        ListNode* Answer = solution.addTwoNumbers(LeftVal, RightVal);

        REQUIRE_THAT(*(Answer), IsEqualListNode(*ResultVal));

        releaseListNode(LeftVal);
        releaseListNode(RightVal);
        releaseListNode(ResultVal);
    }
}