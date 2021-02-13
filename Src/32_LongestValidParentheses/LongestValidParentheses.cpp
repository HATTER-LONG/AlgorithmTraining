#include <catch2/catch.hpp>
#include <stack>
#include <string>
#include <tuple>

using namespace Catch;
using namespace std;

class Solution
{
public:
    // 动态规划
    int longestValidParentheses(string s)
    {
        int maxans = 0, n = static_cast<int>(s.length());
        vector<int> dp(n, 0);
        for (int index = 1; index < n; index++)
        {
            if (s[index] == ')')
            {
                if (s[index - 1] == '(')
                {
                    // 将 'x'()  X位置的括号长度加入 在加上当前 index 所匹配的 2
                    dp[index] = (index > 2 ? dp[index - 2] : 0) + 2;
                }
                else if (index - dp[index - 1] > 0 && s[index - dp[index - 1] - 1] == '(')
                {
                    // index - dp[index - 1] - 1 表示查找前一个有效括号串的前一个是否为多出的 `(`
                    // 正好可以与当前的 `)` 组合，
                    // 类似 (  )  (  (  )  (  )  )
                    //     0  2  0  0  2  0  4  8
                    //        ↑                 ↑
                    //  lastDpCount           dp[index]
                    int lastDpCount = ((index - dp[index - 1]) >= 2 ? dp[index - dp[index - 1] - 2] : 0);
                    dp[index] = dp[index - 1] + lastDpCount + 2;
                }
                maxans = max(maxans, dp[index]);
            }
        }
        return maxans;
    }
    // 栈
    int longestValidParenthesesStack(string s)
    {
        int maxans = 0, n = static_cast<int>(s.length());
        stack<int> stk;
        stk.push(-1);   //栈底
        for (int index = 0; index < n; index++)
        {
            if (s[index] == '(')
            {
                stk.push(index);
            }
            else
            {
                stk.pop();
                if (stk.empty())
                {
                    stk.push(index);
                }
                else
                {
                    maxans = max(maxans, index - stk.top());
                }
            }
        }
        return maxans;
    }
};


TEST_CASE("Check Solution longestValidParentheses and longestValidParenthesesStack method work successfully")
{
    Solution solution;

    string inputStr;

    int ResultParm;

    tie(inputStr, ResultParm) = GENERATE(table<string, int>({
        make_tuple("(()", 2),
        make_tuple(")()())", 4),
        make_tuple("", 0),
    }));

    REQUIRE(solution.longestValidParentheses(inputStr) == ResultParm);
    REQUIRE(solution.longestValidParenthesesStack(inputStr) == ResultParm);
}