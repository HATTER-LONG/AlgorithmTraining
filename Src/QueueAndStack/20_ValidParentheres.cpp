#include "Tools/Tools.hpp"

#include <stack>


/*
 * 题目描述
 * 给定一个只由左右原括号、花括号和方括号组成的字符串，求这个字符串是否合法。合法的
 * 定义是每一个类型的左括号都有一个右括号一一对应，且括号内的字符串也满足此要求。
 *
 * 输入输出样例
 *   输入是一个字符串，输出是一个布尔值，表示字符串是否合法。
 * Input: "{[]}()"
 * Output: true
 *
 */

bool isValid(string s)
{
    stack<char> parsed;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            parsed.push(s[i]);
        }
        else
        {
            if (parsed.empty())
                return false;
            char c = parsed.top();
            if ((s[i] == '}' && c == '{') || (s[i] == ']' && c == '[')
                || (s[i] == ')' && c == '('))
            {
                parsed.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

TEST_CASE("Check Solution isValid method work successfully ")
{
    string inputStr;
    bool result;

    tie(inputStr, result) = GENERATE(table<string, bool>({
        make_tuple("()", true),
        make_tuple("()[]{}", true),
        make_tuple("(]", false),
        make_tuple("([)]", false),
    }));
    CAPTURE(inputStr, result);
    REQUIRE(isValid(inputStr) == result);
}
