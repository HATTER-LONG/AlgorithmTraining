#include "Tools/ListNodeTools.h"

#include <algorithm>
#include <catch2/catch.hpp>
#include <climits>
#include <cstddef>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace Catch;
using namespace std;

// 快慢指针

class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        if (!head || !head->next)
            return false;

        ListNode* fastPtr = head->next;
        ListNode* slowPtr = head;
        while (fastPtr != nullptr)
        {
            if (fastPtr == slowPtr)
                return true;

            fastPtr = fastPtr->next;
            if (fastPtr)
                fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
        return false;
    }
};


TEST_CASE("Check Solution hasCycle method work successfully")
{
    Solution solution;

    vector<int> inputParm;
    int inputParm2;
    bool resultParm = 0;

    tie(inputParm, inputParm2, resultParm) = GENERATE(table<vector<int>, int, bool>({
        make_tuple(vector<int> { 3, 2, 0, -4 }, 1, true),
        make_tuple(vector<int> { 1, 2 }, 0, true),
        make_tuple(vector<int> { 1 }, -1, false),
    }));

    auto listNodeHead = initListNode(inputParm, inputParm2);
    auto listStr = transListNode2Str(*listNodeHead.get());
    CAPTURE(listStr, resultParm);

    REQUIRE(solution.hasCycle(listNodeHead.get()) == (resultParm));
}