#include <catch2/catch.hpp>
#include <cstddef>
#include <limits.h>
#include <string>
#include <tuple>

using namespace std;
using namespace Catch;

//动态规划
class Solution
{
public:
    pair<int, int> expainStr(const string& s, int left, int right)
    {
        while (left >= 0 && right < static_cast<int>(s.length()) && s[left] == s[right])
        {
            left--;
            right++;
        }
        return { left + 1, right - 1 };   // left right 时已经不匹配的字符位置了  需要剪掉
    }
    string longestPalindrome(string s)
    {
        int begin = 0;
        int end = 0;
        for (size_t index = 0; index < s.length(); index++)
        {
            auto [left1, right1] = expainStr(s, index, index);
            auto [left2, right2] = expainStr(s, index, index + 1);

            if (right1 - left1 > end - begin)
            {
                begin = left1;
                end = right1;
            }
            if (right2 - left2 > end - begin)
            {
                begin = left2;
                end = right2;
            }
        }
        return s.substr(begin, end - begin + 1);
    }
};


TEST_CASE("Check Solution lengthOfLongestSubstring method work successfully ")
{
    Solution solution;

    string inputStr;
    string result;
    // clang-format off
    tie(inputStr, result) = 
        GENERATE(table<string, string>
            (
                {
                    make_tuple("babad","bab"),
                    make_tuple("cbbd", "bb"),
                    make_tuple("a", "a"),
                    make_tuple("ac", "a"),
                }
            )
        );
    // clang-format on;

    REQUIRE_THAT(solution.longestPalindrome(inputStr), Equals(result));
}