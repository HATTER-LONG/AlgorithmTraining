#include <catch2/catch.hpp>
#include <glog/logging.h>
#include <set>

using namespace std;

/*
 * 给你一个长度为 n 的整数数组，请你判断在最多改变 1 个元素的情况下，
 * 该数组能否变成一个非递减数列。
 *
 * 我们是这样定义一个非递减数列的：
 * 对于数组中任意的i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。
 *
 * 示例 1:
 *
 * 输入: nums = [4,2,3]
 * 输出: true
 * 解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
 * 提示：
 * 1 <= n <= 10 ^ 4
 * - 10 ^ 5 <= nums[i] <= 10 ^ 5
 */

bool checkPossibility(vector<int>& nums) {
    int size = nums.size();
    int count = 0;
    for(int i = 1; i < size && count < 2; i++) {
        if(nums[i] >= nums[i - 1]) {
            continue;
        }

        count++;
        if(i >= 2 && nums[i] < nums[i - 2]) {
            nums[i] = nums[i - 1];
        } else {
            nums[i - 1] = nums[i];
        }
    }
    return count <= 1;
}

TEST_CASE("test check possibility func") {
    vector<int> input;
    bool result;

    tie(input, result) = GENERATE(table<vector<int>, bool>(
        {make_tuple(vector<int>{4, 2, 1}, false), make_tuple(vector<int>{4, 2, 3}, true),
         make_tuple(vector<int>{1, 1, 1}, true)}));

    REQUIRE(checkPossibility(input) == result);
}
