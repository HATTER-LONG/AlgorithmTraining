#include "Tools/ListNodeTools.h"

#include <algorithm>
#include <catch2/catch.hpp>
#include <climits>
#include <cstddef>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace Catch;
using namespace std;

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr)
        {
            ListNode* nextTemp = curr->next;   //临时节点，暂存当前节点的下一节点，用于后移
            curr->next = prev;                 //将当前节点指向它前面的节点
            prev = curr;                       //前指针后移
            curr = nextTemp;                   //当前指针后移
        }
        return prev;
    }
};
TEST_CASE("Check Solution reverseList method work successfully")
{
    Solution solution;
    vector<int> inputParmA, result;

    tie(inputParmA, result) = GENERATE(table<vector<int>, vector<int>>({
        make_tuple(vector<int> { 1, 2, 3, 4, 5 }, vector<int> { 5, 4, 3, 2, 1 }),
    }));
    auto listNodeIn = initListNode(inputParmA);
    auto listNodeResult = initListNode(result);

    REQUIRE_THAT(*solution.reverseList(listNodeIn.get()), IsEqualListNode(*listNodeResult.get()));
}