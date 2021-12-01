#include <Tools/Tools.hpp>

/*
 * 题目描述
 *   给定一个增序的整数数组和一个值，查找该值第一次和最后一次出现的位置。
 *
 * 输入输出样例
 * 输入是一个数组和一个值，输出为该值第一次出现的位置和最后一次出现的位置(从 0
 * 开 始);如果不存在该值，则两个返回值都设为-1。
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 数字 8 在第 3 位第一次出现，在第 4 位最后一次出现。
 */
int lowerBound(vector<int>& nums, int target)
{
    int l = 0, r = nums.size(), mid = 0;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] >= target)
        {

            r = mid;
        }
        else
        {
            l = mid + 1;
        }
        /* LOG(INFO) << "l = " << l << " | r = " << r << " | mid = " << mid; */
    }
    return l;
}
int upperBound(vector<int>& nums, int target)
{
    int l = 0, r = nums.size(), mid = 0;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] > target)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
        /* LOG(INFO) << "l = " << l << " | r = " << r << " | mid = " << mid; */
    }
    return l;
}
vector<int> searchRange(vector<int>& nums, int target)
{
    if (nums.empty())
    {
        return { -1, -1 };
    }
    int lower = lowerBound(nums, target);
    int upper = upperBound(nums, target) - 1;
    if (lower == static_cast<int>(nums.size()) || nums[lower] != target)
    {
        return { -1, -1 };
    }
    return { lower, upper };
}

TEST_CASE("test search range func")
{
    VecInt input;
    int target;

    VecInt result;


    tie(input, target, result) = GENERATE(table<VecInt, int, VecInt>(
        { make_tuple(VecInt { 5, 7, 7, 8, 8, 10 }, 8, VecInt { 3, 4 }),
            make_tuple(VecInt { 1 }, 1, VecInt { 0, 0 }) }));
    CAPTURE(input, target, result);
    REQUIRE_THAT(searchRange(input, target), Catch::Equals(result));
}
