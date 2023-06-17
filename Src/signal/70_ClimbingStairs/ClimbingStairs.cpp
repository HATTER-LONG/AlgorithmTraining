#include <catch2/catch.hpp>
#include <cstddef>
#include <string>
#include <tuple>

using namespace Catch;
using namespace std;

// 动态规划 f(x)=f(x−1)+f(x−2)

class Solution
{
public:
    int climbStairs(int n)
    {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; i++)
        {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }

    int climbStairsDP(int n)
    {
        if (n == 1)
            return n;
        vector<int> dp(n);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // 斐波那契，向前滚动结果总和
    int climbStairsFB(int n)
    {
        if (n == 1)
            return n;
        int first = 1;
        int second = 2;
        for (int i = 1; i <= n; i++)
        {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};


TEST_CASE("Check Solution climbStairs method work successfully")
{
    Solution solution;

    int inputParm;

    int resultParm;

    tie(inputParm, resultParm) = GENERATE(table<int, int>({
        make_tuple(2, 2),
        make_tuple(3, 3),
    }));

    CAPTURE(inputParm, resultParm);
    REQUIRE(solution.climbStairs(inputParm) == resultParm);
}