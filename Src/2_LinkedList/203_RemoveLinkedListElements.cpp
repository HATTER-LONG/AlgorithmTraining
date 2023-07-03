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
    ListNode* removeElements(ListNode* head, int val)
    {
        while (head != nullptr && head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        if (head == nullptr)
            return nullptr;

        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }

        return head;
    }
};

TEST_CASE("Check Solution removeElements method work successfully")
{
    Solution solution;

    vector<int> LeftParm, result;
    int var = -1;
    tie(LeftParm, var, result) = GENERATE(table<vector<int>, int, vector<int>>({
        make_tuple(vector<int> { 1, 2, 6, 3, 4, 5, 6 }, 6, vector<int> { 1, 2, 3, 4, 5 }),
        make_tuple(vector<int> {}, 1, vector<int> {}),
        make_tuple(vector<int> { 7, 7, 7 }, 7, vector<int> {}),
    }));
    auto* Left = initListNode(LeftParm);
    auto* resultNode = initListNode(result);
    auto* ans = solution.removeElements(Left, var);
    checkListNode(ans, resultNode);
}
