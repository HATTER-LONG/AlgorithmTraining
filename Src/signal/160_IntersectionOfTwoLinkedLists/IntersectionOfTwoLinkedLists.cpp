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

// 双指针

class Solution
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        /**
        定义两个指针, 第一轮让两个到达末尾的节点指向另一个链表的头部,
        最后如果相遇则为交点(在第一轮移动中恰好抹除了长度差) 两个指针等于移动了相同的距离, 有交点就返回,
        无交点就是各走了两条指针的长度
        **/
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        auto* pA = headA;
        auto* pB = headB;
        // 在这里第一轮体现在pA和pB第一次到达尾部会移向另一链表的表头, 而第二轮体现在如果pA或pB相交就返回交点,
        // 不相交最后就是null==null
        while (pA != pB)
        {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};

TEST_CASE("Check Solution maxProduct method work successfully")
{
    Solution solution;
    vector<int> inputParmA, inputParmB, inputParmC;

    tie(inputParmA, inputParmB, inputParmC) = GENERATE(table<vector<int>, vector<int>, vector<int>>({
        make_tuple(vector<int> { 4, 1 }, vector<int> { 5, 0, 1, 8, 4, 5 }, vector<int> { 8, 4, 5 }),
        make_tuple(vector<int> { 0, 9, 1 }, vector<int> { 3 }, vector<int> { 2, 4 }),
        make_tuple(vector<int> { 0, 9, 1, 2, 4 }, vector<int> { 3, 2, 4 }, vector<int> {}),
    }));

    auto ListNodeA = initListNode(inputParmA);
    auto ListNodeB = initListNode(inputParmB);
    auto ListNodeC = initListNode(inputParmC);

    ListNodeA.get()->next = ListNodeC.get();
    ListNodeB.get()->next = ListNodeC.get();

    auto* ans = solution.getIntersectionNode(ListNodeA.get(), ListNodeB.get());

    REQUIRE(ans == ListNodeC.get());
}