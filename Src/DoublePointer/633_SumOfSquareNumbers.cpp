#include "Tools/Tools.hpp"
/*
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。
 *
 * 示例 1：
 *
 * 输入：c = 5
 * 输出：true
 * 解释：1 * 1 + 2 * 2 = 5
 * 示例 2：
 *
 * 输入：c = 3
 * 输出：false
 *
 */

bool judgeSquareSum(int c)
{
    int l = 0, r = sqrt(c), sum = 0;
    while (l <= r)
    {
        sum = l * l + r * r;
        if (sum == c)
        {
            return true;
        }
        if (sum < c)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return false;
}

TEST_CASE("test judge square sum func")
{
    int input;
    bool result;

    tie(input, result) = GENERATE(table<int, bool>({ make_tuple(5, true),
        make_tuple(3, false), make_tuple(2, true), make_tuple(1, true) }));

    REQUIRE(judgeSquareSum(input) == result);
}
