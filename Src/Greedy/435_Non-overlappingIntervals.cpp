#include <algorithm>
#include <catch2/catch.hpp>

/*
 * 题目描述
 *   给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。
 *   起止相连不算重叠。
 *
 * 输入输出样例
 * 输入是一个数组，数组由多个长度固定为 2 的数组组成，
 * 表示区间的开始和结尾。输出一个整数，表示需要移除的区间数量。
 *
 * Input: [[1,2], [2,4], [1,3]]
 * Output: 1
 *
 * 在这个样例中，我们可以移除区间 [1,3]，使得剩余的区间 [[1,2], [2,4]]
 * 互不重叠。
 */

int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
{
    if (intervals.empty())
        return 0;
    size_t size = intervals.size();
    std::sort(intervals.begin(), intervals.end(),
        [](std::vector<int>& a, std::vector<int>& b)
        {
            return a[1] < b[1]; /* check right line */
        });
    int removed = 0, prev = intervals[0][1];
    for (size_t i = 1; i < size; i++)
    {
        if (intervals[i][0] < prev)
        {
            ++removed;
        }
        else
        {
            prev = intervals[i][1];
        }
    }
    return removed;
}

TEST_CASE("test erase overlap intervals")
{
    std::vector<std::vector<int>> intervals { { 1, 2 }, { 2, 3 }, { 3, 4 },
        { 1, 3 } };

    int result = 1;
    REQUIRE(eraseOverlapIntervals(intervals) == result);
}
