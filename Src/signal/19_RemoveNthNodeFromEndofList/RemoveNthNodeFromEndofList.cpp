#include "Tools/ListNodeTools.h"

#include <tuple>

using namespace Catch;
using namespace std;

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* pre = head;
        ListNode* next = head;
        while (next)
        {
            if (n < 0)
            {
                pre = pre->next;
            }
            n--;
            next = next->next;
        }

        if (n == 0)
            return head->next;
        pre->next = pre->next->next;
        return head;
    }
};

TEST_CASE("Check Solution removeNthFromEnd method work successfully")
{
    Solution solution;

    vector<int> List, ResultParm;
    int n = 0;

    tie(List, n, ResultParm) = GENERATE(table<vector<int>, int, vector<int>>({
        make_tuple(vector<int> { 1, 2, 3, 4, 5 }, 2, vector<int> { 1, 2, 3, 5 }),
        make_tuple(vector<int> { 1 }, 1, vector<int> {}),
        make_tuple(vector<int> { 1, 2 }, 1, vector<int> { 1 }),
        make_tuple(vector<int> { 1, 2 }, 2, vector<int> { 2 }),
        make_tuple(vector<int> { 1, 2, 3 }, 3, vector<int> { 2, 3 }),
    }));

    ListNodePtr ListVal = initListNode(List);
    ListNodePtr ResultVal = initListNode(ResultParm);

    // NOTE 由于自定义比对器入参必须是 T const& 导致 nullptr 无法传入，因此这里分支处理
    if (!ResultVal.get())
    {
        REQUIRE((solution.removeNthFromEnd(ListVal.get(), n)) == nullptr);
    }
    else
    {
        REQUIRE_THAT(*(solution.removeNthFromEnd(ListVal.get(), n)), IsEqualListNode(*ResultVal));
    }
}