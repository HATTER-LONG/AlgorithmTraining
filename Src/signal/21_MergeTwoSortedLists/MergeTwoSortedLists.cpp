#include "Tools/ListNodeTools.h"

#include <tuple>

using namespace Catch;
using namespace std;

//  递归算法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) {
            return l2;
        }
        if(l2 == nullptr) {
            return l1;
        }
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }

        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
};

TEST_CASE("Check Solution mergeTwoLists method work successfully") {
    Solution solution;

    vector<int> LeftList, rightList, ResultParm;

    tie(LeftList, rightList, ResultParm) = GENERATE(table<vector<int>, vector<int>, vector<int>>({
        make_tuple(vector<int>{1, 2, 4}, vector<int>{1, 3, 4}, vector<int>{1, 1, 2, 3, 4, 4}),
        make_tuple(vector<int>{}, vector<int>{}, vector<int>{}),
        make_tuple(vector<int>{}, vector<int>{0}, vector<int>{0}),
    }));

    ListNodePtr LeftListVal = initListNode(LeftList);
    ListNodePtr RightListVal = initListNode(rightList);
    ListNodePtr ResultVal = initListNode(ResultParm);

    // NOTE 由于自定义比对器入参必须是 T const& 导致 nullptr 无法传入，因此这里分支处理
    if(!ResultVal.get()) {
        REQUIRE((solution.mergeTwoLists(LeftListVal.get(), RightListVal.get())) == nullptr);
    } else {
        REQUIRE_THAT(*(solution.mergeTwoLists(LeftListVal.get(), RightListVal.get())),
                     IsEqualListNode(*ResultVal));
    }
}