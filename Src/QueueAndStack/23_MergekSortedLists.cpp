#include "Tools/ListNodeTools.h"
#include "Tools/Tools.hpp"

#include <queue>
/*
 * 题目描述
 * 给定 k 个增序的链表，试将它们合并成一条增序链表。 输入输出样例
 *   输入是一个一维数组，每个位置存储链表的头节点;输出是一条链表。
 * Input:
 * [1->4->5,
 * 1->3->4,
 *  2->6]
 * Output: 1->1->2->3->4->4->5->6
 */

struct Comp {
    bool operator()(ListNode* l1, ListNode* l2) { return l1->val > l2->val; }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty())
        return nullptr;

    priority_queue<ListNode*, vector<ListNode*>, Comp> q; // 最小堆

    for(ListNode* list : lists) {
        if(list)
            q.push(list);
    }

    ListNode *dummy = new ListNode(0), *cur = dummy;
    while(!q.empty()) {
        cur->next = q.top();
        q.pop();
        cur = cur->next;
        if(cur->next)

        {
            q.push(cur->next);
        }
    }
    return dummy->next;
}

TEST_CASE("Check Solution mergeKLists method work successfully") {
    vector<vector<int>> list;
    vector<int> resultParm;

    tie(list, resultParm) = GENERATE(table<vector<vector<int>>, vector<int>>({
        make_tuple(vector<vector<int>>{{1, 4, 5}, {1, 3, 4}, {2, 6}},
                   vector<int>{1, 1, 2, 3, 4, 4, 5, 6}),
        make_tuple(vector<vector<int>>{{}}, vector<int>{}),
        make_tuple(vector<vector<int>>{}, vector<int>{}),
    }));

    vector<ListNodePtr> listVar(list.size());
    vector<ListNode*> listInputParam(list.size());
    for(size_t i = 0; i < list.size(); i++) {
        listVar[i] = initListNode(list[i]);
        listInputParam[i] = listVar[i].get();
    }

    ListNodePtr resultVal = initListNode(resultParm);
    // NOTE 由于自定义比对器入参必须是 T const& 导致 nullptr
    // 无法传入，因此这里分支处理
    if(!resultVal.get()) {
        REQUIRE((mergeKLists(listInputParam)) == nullptr);
    } else {
        REQUIRE_THAT(*(mergeKLists(listInputParam)), IsEqualListNode(*resultVal));
    }
}
