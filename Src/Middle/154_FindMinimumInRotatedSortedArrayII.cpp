#include "Tools/Tools.hpp"

#include <tuple>

/*
 * 已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转
 * 后，得到输入数组。例如，原数组 nums = [0,1,4,4,5,6,7] 在变化后可能得到：
 * 若旋转 4 次，则可以得到 [4,5,6,7,0,1,4]
 * 若旋转 7 次，则可以得到 [0,1,4,4,5,6,7]
 * 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1],
 * a[0], a[1], a[2], ..., a[n-2]] 。
 *
 * 给你一个可能存在 重复 元素值的数组 nums
 * ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的
 * 最小元素 。
 *
 *  
 *
 * 示例 1：
 *
 * 输入：nums = [1,3,5]
 * 输出：1
 * 示例 2：
 *
 * 输入：nums = [2,2,2,0,1]
 * 输出：0
 *
 */

int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, mid = 0;
    while(l < r) {
        mid = l + (r - l) / 2;
        /* LOG(INFO) << "l = " << l << " mid = " << mid << " r = " << r; */
        // mid != l 避免当计算mid == l 时导致 l++
        if(nums[mid] == nums[l] && mid != l) {
            ++l;
            continue;
        }
        if(nums[mid] <= nums[r]) {
            r = mid;
        } else {
            l = mid + 1;
        }
        /* LOG(INFO) << "l = " << l << " mid = " << mid << " r = " << r; */
    }
    /* LOG(INFO) << "l = " << l; */
    return nums[l];
}
int findMinRight(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, mid = 0;
    while(l < r) {
        mid = l + (r - l) / 2;
        if(nums[mid] < nums[r]) {
            r = mid;
        } else if(nums[mid] > nums[r]) {
            l = mid + 1;
        } else {
            r--;
        }
    }
    return nums[l];
}

TEST_CASE("test find Min") {
    VecInt input;
    int result;

    tie(input, result) = GENERATE(
        table<VecInt, int>({make_tuple(VecInt{1, 3, 5}, 1), make_tuple(VecInt{2, 2, 2, 0, 1}, 0),
                            make_tuple(VecInt{4, 4, 4, 4, 4, 4, 0, 1, 2, 3, 4}, 0),
                            make_tuple(VecInt{3, 3, 1, 3}, 1), make_tuple(VecInt{3, 1}, 1)}));

    CAPTURE(input, result);
    REQUIRE(findMin(input) == result);
}
