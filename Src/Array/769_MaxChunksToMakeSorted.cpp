#include "Tools/Tools.hpp"

/*
 * 题目描述
 * 给定一个含有 0 到 n
 * 整数的数组，每个整数只出现一次，求这个数组最多可以分割成多少个
 * 子数组，使得对每个子数组进行增序排序后，原数组也是增序的。
 *
 *
 * 输入一个一维整数数组，输出一个整数，表示最多的分割数。
 * Input: [1,0,2,3,4]
 * Output: 4
 * 在这个样例中，最多分割是 [1, 0], [2], [3], [4]。
 */

int maxChunksToSorted(vector<int>& arr)
{
    int chunks = 0, curMax = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        curMax = max(curMax, arr[i]);
        if (curMax == static_cast<int>(i))
        {
            chunks++;
        }
    }
    return chunks;
}

TEST_CASE("test max chunks to sorted")
{
    VecInt input;
    int result;

    tie(input, result) =
        GENERATE(table<VecInt, int>({ make_tuple(VecInt { 1, 0, 2, 3, 4 }, 4),
            make_tuple(VecInt { 1, 2, 0, 3 }, 2) }));

    CAPTURE(input, result);

    REQUIRE(maxChunksToSorted(input) == result);
}
