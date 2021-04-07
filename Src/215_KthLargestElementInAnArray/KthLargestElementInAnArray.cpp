#include <algorithm>
#include <catch2/catch.hpp>
#include <climits>
#include <cstddef>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace Catch;
using namespace std;

class Solution
{
public:
    int quickSelect(vector<int>& a, int l, int r, int index)
    {
        int q = randomPartition(a, l, r);
        if (q == index)
        {
            return a[q];
        }

        return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
    }

    inline int randomPartition(vector<int>& a, int l, int r)
    {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int>& a, int l, int r)
    {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j)
        {
            if (a[j] <= x)
            {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

TEST_CASE("Check Trie findKthLargest work successfully")
{
    Solution solution;
    vector<int> paramIn;
    int k, result;
    tie(paramIn, k, result) = GENERATE(table<vector<int>, int, int>({
        make_tuple(vector<int> { 3, 2, 1, 5, 6, 4 }, 2, 5),
        make_tuple(vector<int> { 3, 2, 3, 1, 2, 4, 5, 5, 6 }, 4, 4),
    }));

    REQUIRE(solution.findKthLargest(paramIn, k) == result);
}