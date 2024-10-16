#include "Tools/ListNodeTools.h"

#include <glog/logging.h>

using namespace Catch;
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while(curA != nullptr) { // 求链表长度
            lenA++;
            curA = curA->next;
        }
        while(curB != nullptr) {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // 使 curA 为长链表
        if(lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }

        int gap = lenA - lenB;

        while(gap--) { // A-- 表示跳过 A 个节点指向 A+1，--A 表示跳过 A-1 个节点指向 A
            curA = curA->next;
        }

        while(curA != nullptr) {
            if(curA == curB)
                return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};

TEST_CASE("Check Solution getIntersectionNode method work successfully") {
    Solution solution;
    vector<int> inputParmA, inputParmB, inputParmC;

    tie(inputParmA, inputParmB, inputParmC) =
        GENERATE(table<vector<int>, vector<int>, vector<int>>({
            make_tuple(vector<int>{4, 1}, vector<int>{5, 0, 1, 8, 4, 5}, vector<int>{8, 4, 5}),
            make_tuple(vector<int>{0, 9, 1}, vector<int>{3}, vector<int>{2, 4}),
            make_tuple(vector<int>{0, 9, 1, 2, 4}, vector<int>{3, 2, 4}, vector<int>{}),
        }));

    auto* ListNodeA = initListNode(inputParmA);
    auto* ListNodeB = initListNode(inputParmB);
    auto* ListNodeC = initListNode(inputParmC);

    ListNodeA->next = ListNodeC;
    ListNodeB->next = ListNodeC;

    auto* ans = solution.getIntersectionNode(ListNodeA, ListNodeB);

    checkListNode(ans, ListNodeC);
}
