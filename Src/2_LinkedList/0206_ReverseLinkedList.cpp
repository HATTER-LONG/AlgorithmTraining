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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while(cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

TEST_CASE("Check Solution reverseList method work successfully") {
    Solution solution;

    vector<int> param, result;
    tie(param, result) = GENERATE(table<vector<int>, vector<int>>({
        make_tuple(vector<int>{1, 2, 6, 3, 4, 5, 6}, vector<int>{6, 5, 4, 3, 6, 2, 1}),
    }));
    auto* Left = initListNode(param);
    auto* resultNode = initListNode(result);
    auto* ans = solution.reverseList(Left);
    checkListNode(ans, resultNode);
}
