#include <catch2/catch_all.hpp>
#include <glog/logging.h>
using namespace Catch;
using namespace std;

class Solution
{
public:
    // [left, right]
    int search(vector<int>& nums, int target)
    {
        int numsSize = nums.size();
        if (numsSize == 0) {
            return -1;
        }

        int left = 0;
        int right = numsSize - 1;
        while (left <= right) {   // 当left==right，区间[left, right]依然有效，所以用 <=
            int middle = left + (right - left) / 2;   // 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1;   // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1;   // target 在右区间，所以[middle + 1, right]
            } else {                 // nums[middle] == target
                return middle;
            }
        }
        return -1;
    }
    // [left, right)
    int search_close(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size();   // 定义target在左闭右开的区间里，即：[left, right)
        while (left < right) {   // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) {   // target 在左区间，在[left, middle)中
                right = middle;
            } else if (nums[middle] < target) {   // target 在右区间，在 [middle + 1, right)中
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
};

TEST_CASE("Check Solution search method work successfully")
{
    Solution solution;

    vector<int> param;

    int target, result;
    tie(param, target, result) = GENERATE(table<vector<int>, int, int>({
        make_tuple(vector<int> { -1, 0, 3, 5, 9, 12 }, 9, 4),
        make_tuple(vector<int> { -1, 0, 3, 5, 9, 12 }, 2, -1),
        make_tuple(vector<int> { -1, 0 }, 0, 1),
        make_tuple(vector<int> { 5 }, -5, -1),
    }));

    REQUIRE(solution.search(param, target) == result);
}
