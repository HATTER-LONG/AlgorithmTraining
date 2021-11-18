#include "Tools/Tools.hpp"

/*
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 *
 *
 * 示例 1:
 *
 * 输入: s = "aba"
 * 输出: true
 * 示例 2:
 *
 * 输入: s = "abca"
 * 输出: true
 * 解释: 你可以删除c字符。
 *
 */

bool check(string s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
bool validPalindrome(string s)
{
    int l = 0, r = s.length() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
            return check(s, l + 1, r) || check(s, l, r - 1);
        l++;
        r--;
    }
    return true;
}

TEST_CASE("test check palindrome func")
{
    string input;
    bool result;

    tie(input, result) = GENERATE(table<string, bool>({ make_tuple("aba", true),
        make_tuple("abca", true), make_tuple("ebcbbececabbacecbbcbe", true),
        make_tuple("abc", false), make_tuple("cbbcc", true) }));
    CAPTURE(input, result);
    REQUIRE(validPalindrome(input) == result);
}
