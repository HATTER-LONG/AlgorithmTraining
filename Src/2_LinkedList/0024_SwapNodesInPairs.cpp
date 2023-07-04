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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* dummyhead = new ListNode(0);   // 设定一个虚拟头节点
        dummyhead->next = head;   // 将虚拟头节点指向head，这样方便后面要做的删除操作
        ListNode* cur = dummyhead;

        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp1 = cur->next;   // 记录间隔的临时节点
            ListNode* tmp2 = cur->next->next->next;

            cur->next = cur->next->next;    // 步骤一
            cur->next->next = tmp1;         // 步骤二
            cur->next->next->next = tmp2;   // 步骤三

            cur = cur->next->next;   // cur 向后移动两位，准备下一轮交换
        }
        return dummyhead->next;
    }
};

TEST_CASE("Check Solution swapPairs method work successfully")
{
    Solution solution;

    vector<int> param, result;
    tie(param, result) = GENERATE(table<vector<int>, vector<int>>({
        make_tuple(vector<int> { 1, 2, 3, 4 }, vector<int> { 2, 1, 4, 3 }),
        make_tuple(vector<int> { 1 }, vector<int> { 1 }),
        make_tuple(vector<int> {}, vector<int> {}),
    }));
    auto* Left = initListNode(param);
    auto* resultNode = initListNode(result);
    auto* ans = solution.swapPairs(Left);
    checkListNode(ans, resultNode);
}
