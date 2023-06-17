#include <algorithm>
#include <catch2/catch.hpp>
#include <climits>
#include <cstddef>
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
    int rob(vector<int>& nums)
    {
        size_t n = nums.size();
        if (n == 0)
            return 0;
        if (n < 2)
            return nums[0];
        if (n < 3)
            return max(nums[0], nums[1]);


        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        int res = max(dp[0], dp[1]);
        for (size_t i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            res = max(dp[i], res);
        }
        return res;
    }
};

TEST_CASE("Check Solution rob method work successfully")
{
    Solution solution;
    vector<int> inputParmA;
    int result = 0;
    tie(inputParmA, result) = GENERATE(table<vector<int>, int>({
        make_tuple(vector<int> { 1, 2, 3, 1 }, 4),
        make_tuple(vector<int> { 2, 7, 9, 3, 1 }, 12),
        make_tuple(vector<int> { 2, 1, 1, 2 }, 4),
    }));

    REQUIRE(solution.rob(inputParmA) == result);
}