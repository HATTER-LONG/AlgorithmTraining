#include "Tools/Tools.hpp"

/*
 * 题目描述
 *   一个原本增序的数组被首尾相连后按某个位置断开
 *   (如 [1,2,2,3,4,5] →
 * [2,3,4,5,1,2]，在第一位和第二位断开)，我们称其为旋转数组。
 *   给定一个值，判断这个值是否存在于这个旋转数组中。
 *
 * 输入输出样例
 *   输入是一个数组和一个值，输出是一个布尔值，表示数组中是否存在该值。
 *
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 */

bool search(vector<int>& nums, int target)
{
    int l = 0, r = nums.size() - 1, mid = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] == target)
        {
            return true;
        }
        if (nums[mid] == nums[l])
        {
            ++l;
            continue;
        }
        if (nums[mid] <= nums[r])
        {
            if (target > nums[mid] && target <= nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        else
        {
            if (target < nums[mid] && target >= nums[l])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    return false;
}

TEST_CASE("test search func")
{
    VecInt nums;
    int target;
    bool result;

    tie(nums, target, result) = GENERATE(table<VecInt, int, bool>(
        { make_tuple(VecInt { 2, 5, 6, 0, 0, 2, 3 }, 0, true),
            make_tuple(VecInt { 1, 0, 1, 1, 1 }, 0, true) }));

    CAPTURE(nums, target, result);
    REQUIRE(search(nums, target) == result);
}
