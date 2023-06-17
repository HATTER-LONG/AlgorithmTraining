#include <catch2/catch.hpp>
#include <string>
#include <tuple>
using namespace Catch;
using namespace std;

//动态规划

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        if (n == 0)
            return {};
        if (n == 1)
            return { "()" };

        vector<vector<string>> dp(n + 1);
        dp[0] = { "" };                // 0 组括号为空
        dp[1] = { "()" };              // 1 组括号只有一种情况
        for (int i = 2; i <= n; i++)   // 开始计算 i 组括号时括号的组合
        {
            for (int j = 0; j < i; j++)   // 开始遍历 p q , 其中 p + q = i - 1， j 为索引
            {
                for (string p : dp[j])   // p = j 括号时的组合情况 与 q 组合情况进行全排列
                {
                    for (string q : dp[i - j - 1])
                    {
                        string str = "(" + p + ")" + q;
                        dp[i].push_back(str);
                    }
                }
            }
        }
        return dp[n];
    }
};


TEST_CASE("Check Solution generateParenthesis method work successfully")
{
    Solution solution;

    int n;

    vector<string> ResultParm;

    tie(n, ResultParm) = GENERATE(table<int, vector<string>>({
        make_tuple(3, vector<string> { "()()()", "()(())", "(())()", "(()())", "((()))" }),
        make_tuple(1, vector<string> { "()" }),
    }));

    REQUIRE_THAT(solution.generateParenthesis(n), Equals(ResultParm));
}