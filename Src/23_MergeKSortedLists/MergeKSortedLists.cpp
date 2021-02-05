#include "CustomMatcher.h"
#include "HeadFiles.h"

#include <tuple>

using namespace Catch;
using namespace std;

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty())
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        if (lists.size() == 2)
            return mergeTwoLists(lists[0], lists[1]);
        //分治合并
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        if (l > r)
            return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    //  递归算法
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }

        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
};

TEST_CASE("Check Solution mergeTwoLists method work successfully")
{
    Solution solution;

    vector<vector<int>> List;
    vector<int> ResultParm;

    tie(List, ResultParm) = GENERATE(table<vector<vector<int>>, vector<int>>({
        make_tuple(vector<vector<int>> { { 1, 4, 5 }, { 1, 3, 4 }, { 2, 6 } },
            vector<int> { 1, 1, 2, 3, 4, 4, 5, 6 }),
        make_tuple(vector<vector<int>> { {} }, vector<int> {}),
        make_tuple(vector<vector<int>> {}, vector<int> {}),
    }));

    vector<ListNodePtr> ListVar(List.size());
    vector<ListNode*> ListInputParam(List.size());
    for (size_t i = 0; i < List.size(); i++)
    {
        ListVar[i] = initListNode(List[i]);
        ListInputParam[i] = ListVar[i].get();
    }

    ListNodePtr ResultVal = initListNode(ResultParm);
    // NOTE 由于自定义比对器入参必须是 T const& 导致 nullptr 无法传入，因此这里分支处理
    if (!ResultVal.get())
    {
        REQUIRE((solution.mergeKLists(ListInputParam)) == nullptr);
    }
    else
    {
        REQUIRE_THAT(*(solution.mergeKLists(ListInputParam)), IsEqualListNode(*ResultVal));
    }
}