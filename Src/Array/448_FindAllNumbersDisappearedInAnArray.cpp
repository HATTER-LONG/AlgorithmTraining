#include "Tools/Tools.hpp"

/*
 *
 * 给定一个长度为 n 的数组，其中包含范围为 1 到 n
 * 的整数，有些整数重复了多次，有些整数 没有出现，求 1 到 n 中没有出现过的整数。
 * 输入输出样例
 *   输入是一个一维整数数组，输出也是一个一维整数数组，表示输入数组内没出现过的数字。
 * Input: [4,3,2,7,8,2,3,1]
 * Output: [5,6]
 *
 */

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    vector<int> ans;

    for (const int& num : nums)
    {
        int pos = abs(num) - 1;
        if (nums[pos] > 0)
        {
            nums[pos] = -nums[pos];
        }
    }
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            ans.push_back(i + 1);
        }
    }
    return ans;
}

TEST_CASE("test find disappeared numbers")
{
    VecInt input;
    VecInt res;

    tie(input, res) = GENERATE(table<VecInt, VecInt>(
        { make_tuple(VecInt { 4, 3, 2, 7, 8, 2, 3, 1 }, VecInt { 5, 6 }) }));

    CAPTURE(input, res);

    REQUIRE_THAT(findDisappearedNumbers(input), Catch::Equals(res));
}
