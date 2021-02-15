#include <catch2/catch.hpp>
#include <cstddef>
#include <string>
#include <tuple>
#include <unordered_map>

using namespace Catch;
using namespace std;

// 动态规划 && 分治

class Solution
{
public:
    //动态规划
    int maxSubArray(vector<int>& nums)
    {
        int ans = nums[0];
        int pre = 0;

        for (const auto& x : nums)
        {
            pre = max(pre + x, x);
            ans = max(ans, pre);
        }
        return ans;
    }

    //分治
    struct Status
    {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r)
    {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return { lSum, rSum, mSum, iSum };
    };

    Status get(vector<int>& a, int l, int r)
    {
        if (l == r)
        {
            return { a[l], a[l], a[l], a[l] };
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray_dev(vector<int>& nums) { return get(nums, 0, nums.size() - 1).mSum; }
};


TEST_CASE("Check Solution maxSubArray method work successfully")
{
    Solution solution;

    vector<int> inputParm;

    int resultParm;

    tie(inputParm, resultParm) = GENERATE(table<vector<int>, int>({
        make_tuple(vector<int> { -2, 1, -3, 4, -1, 2, 1, -5, 4 }, 6),
        make_tuple(vector<int> { 1 }, 1),
        make_tuple(vector<int> { 0 }, 0),
        make_tuple(vector<int> { -1 }, -1),
    }));

    CAPTURE(inputParm, resultParm);
    REQUIRE(solution.maxSubArray_dev(inputParm) == resultParm);
}