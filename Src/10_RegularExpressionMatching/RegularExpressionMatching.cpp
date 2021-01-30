#include <catch2/catch.hpp>
#include <cstddef>
#include <string>
#include <tuple>

using namespace std;
using namespace Catch;

// https://leetcode-cn.com/problems/regular-expression-matching/solution/javadi-gui-yi-bu-yi-bu-de-you-hua-dao-ji-bai-100yi/
class Solution
{
public:
    //动态规划
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0)
            {
                return false;
            }
            if (p[j - 1] == '.')
            {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] == '*')
                {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1))
                    {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else
                {
                    if (matches(i, j))
                    {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }

    //递归方式
    bool isMatch_1Rev(string s, string p)
    {
        if (p.empty())
            return s.empty();
        bool match = !s.empty() && ((s[0] == p[0]) || p[0] == '.');
        if (p.length() >= 2 && p[1] == '*')
        {
            return isMatch_1Rev(s, p.substr(2)) || (match && isMatch_1Rev(s.substr(1), p));
        }
        return match && isMatch_1Rev(s.substr(1), p.substr(1));
    }
};



TEST_CASE("Check Solution isMatch method work successfully ")
{
    Solution solution;

    string inputStr;
    string inputStr2;
    bool result;

    tie(inputStr, inputStr2, result) = GENERATE(table<string, string, bool>({
        make_tuple("aa", "a", false),
        make_tuple("aa", "a*", true),
        make_tuple("ab", ".*", true),
        make_tuple("aab", "c*a*b", true),
        make_tuple("aaa", "ab*ac*a", true),
        make_tuple("aaa", "ab*a*c*a", true),
        make_tuple("mississippi", "mis*is*p*.", false),

        make_tuple("ab", ".*c", false),
    }));
    CAPTURE(inputStr, inputStr2, result);
    REQUIRE(solution.isMatch(inputStr, inputStr2) == result);
}