#include "Tools/ListNodeTools.h"

#include <glog/logging.h>

using namespace Catch;
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* fast = dummyhead;
        ListNode* slow = dummyhead;
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }
        fast = fast->next;   // fast 在提前走一步，这样 slow 将停到需要删除节点的上一个节点
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        return dummyhead->next;
    }
};

TEST_CASE("Check Solution removeNthFromEnd method work successfully")
{
    Solution solution;

    vector<int> param, result;
    int val = 0;
    tie(param, val, result) = GENERATE(table<vector<int>, int, vector<int>>({
        make_tuple(vector<int> { 1, 2, 3, 4, 5 }, 2, vector<int> { 1, 2, 3, 5 }),
    }));
    auto* Left = initListNode(param);
    auto* resultNode = initListNode(result);
    auto* ans = solution.removeNthFromEnd(Left, val);
    checkListNode(ans, resultNode);
}
