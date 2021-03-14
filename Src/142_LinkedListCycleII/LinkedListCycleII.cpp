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
/**
 * fast 指针走过的距离都为 slow 指针的 2 倍，这时从相遇点到入环点的距离加上 n−1
 * 圈的环长，恰好等于从链表头部到入环点的距离。
 *
 */
class Solution
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr)
        {
            slow = slow->next;
            if (fast->next == nullptr)
            {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow)
            {
                ListNode* ptr = head;
                while (ptr != slow)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};


TEST_CASE("Check Solution detectCycle method work successfully")
{
    Solution solution;

    vector<int> inputParm;
    int inputParm2;


    tie(inputParm, inputParm2) = GENERATE(table<vector<int>, int>({
        make_tuple(vector<int> { 3, 2, 0, -4 }, 1),
        make_tuple(vector<int> { 1, 2 }, 0),
        make_tuple(vector<int> { 1 }, -1),
    }));

    auto listNodeHead = initListNode(inputParm, inputParm2);
    auto* resultParm = findLinstNode(listNodeHead.get(), inputParm2);
    CAPTURE(resultParm);

    REQUIRE(solution.detectCycle(listNodeHead.get()) == (resultParm));
}