#include "Tools/Tools.hpp"

#include <tuple>

/*
 * 给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。
 *
 * 示例 1:
 *
 * 输入: nums = [1,1,2,3,3,4,4,8,8]
 * 输出: 2
 * 示例 2:
 *
 * 输入: nums =  [3,3,7,7,10,11,11]
 * 输出: 10
 */


int singleNonDuplicate(vector<int>& nums)
{
    int l = 0, r = nums.size() - 1, mid = 0;

    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] == nums[mid + 1])
        {
            if (mid % 2 != 0)
            {
                r = mid - 1;
            }
            else
            {
                l = mid;
            }
        }
        else if (nums[mid] == nums[mid - 1])
        {
            if (mid % 2 == 0)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            return nums[mid];
        }
    }
    return nums[l];
}

TEST_CASE("test single nonduplicate func")
{
    VecInt input;
    int result;

    tie(input, result) = GENERATE(table<VecInt, int>(
        { make_tuple(VecInt { 1, 1, 2, 3, 3, 4, 4, 8, 8 }, 2),
            make_tuple(VecInt { 3, 3, 7, 7, 10, 11, 11 }, 10),
            make_tuple(VecInt { 1, 1, 2, 2, 3 }, 3) }));

    CAPTURE(input, result);
    REQUIRE(singleNonDuplicate(input) == result);
}
