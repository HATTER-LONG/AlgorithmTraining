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

// 归并排序与快排

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        auto* p = head;
        int length = 0;
        while(p) {
            ++length;
            p = p->next;
        }

        for(int size = 1; size < length; size <<= 1) {
            auto* cur = dummyHead.next;
            auto* tail = &dummyHead;
            while(cur) {
                auto* left = cur;
                auto* right = cut(left, size); // left->@->@ right->@->@->@...
                cur = cut(right, size);        // left->@->@ right->@->@  cur->@->...

                tail->next = merge(left, right);
                while(tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummyHead.next;
    }
    ListNode* cut(ListNode* head, int n) {
        auto* p = head;
        while(--n && p) {
            p = p->next;
        }

        if(!p)
            return nullptr;

        auto* next = p->next;
        p->next = nullptr;
        return next;
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        auto* p = &dummyHead;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};

class Solution_QuickSort {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode dummyHead(0);
        dummyHead.next = head;
        return quickSort(&dummyHead, nullptr);
    }

    ListNode* quickSort(ListNode* head, ListNode* end) {
        if(head == end || head->next == end || head->next->next == end)
            return head;
        // 将小于划分点的值存储在临时链表中
        ListNode dummyHead(0);
        // partition为划分点，p为链表指针，tp为临时链表指针
        ListNode* partition = head->next;
        ListNode* p = partition;
        ListNode* tp = &dummyHead;
        // 将小于划分点的节点放到临时链表中
        while(p->next != end) {
            if(p->next->val < partition->val) {
                tp->next = p->next;
                tp = tp->next;
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        // 合并临时链表和原链表，将原链表接到临时链表后即可
        tp->next = head->next;
        // 将临时链表插回原链表，注意是插回！（不做这一步在对右半部分处理时就断链了）
        head->next = dummyHead.next;
        quickSort(head, partition);
        quickSort(partition, end);
        // 题目要求不带头节点，返回结果时去除
        return head->next;
    }
};

TEST_CASE("Check Solution sortList method work successfully") {
    Solution solution;
    vector<int> inputParm;
    vector<int> result;

    tie(inputParm, result) = GENERATE(table<vector<int>, vector<int>>({
        make_tuple(vector<int>{4, 2, 1, 3}, vector<int>{1, 2, 3, 4}),
        make_tuple(vector<int>{-1, 5, 3, 4, 0}, vector<int>{-1, 0, 3, 4, 5}),
    }));

    auto listNodeHead = initListNode(inputParm);
    auto listResultNodeHead = initListNode(result);
    REQUIRE_THAT(*(solution.sortList(listNodeHead.get())),
                 IsEqualListNode(*listResultNodeHead.get()));
}