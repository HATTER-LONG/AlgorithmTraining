#include <catch2/catch.hpp>
#include <string>
#include <tuple>

using namespace Catch;
using namespace std;

// 二分法
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        if(n == 0) {
            return {-1, -1};
        }
        int left = findTargetLeftPos(nums, target);
        int right = 0;
        if(left != -1)
            right = findTargetRightPos(nums, target);
        if(left != -1 && right != -1)
            return {left, right};
        return {-1, -1};
    }
    int findTargetLeftPos(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = (left + right) >> 1;
            if(nums[mid] < target) {
                // 下一轮搜索区间在 [mid + 1, right]
                left = mid + 1;
            } else if(nums[mid] == target) {
                // 下一轮搜索区间在 [left, mid]
                right = mid;
            } else {
                // 下一轮搜索区间在 [left, mid - 1]
                right = mid - 1;
            }
        }

        if(nums[left] == target)
            return left;
        return -1;
    }
    int findTargetRightPos(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = (left + right + 1) >> 1; // 上取整 否则 left = mid 永远小于 right
            if(nums[mid] < target) {
                // 下一轮搜索区间在 [mid + 1, right]
                left = mid + 1;
            } else if(nums[mid] == target) {
                // 下一轮搜索区间在 [mid, right]
                left = mid;
            } else {
                // 下一轮搜索区间在 [left, mid - 1]
                right = mid - 1;
            }
        }

        if(nums[right] == target)
            return right;
        return -1;
    }
};

TEST_CASE("Check Solution searchRange method work successfully") {
    Solution solution;

    vector<int> inputParm;
    int target = 0;
    vector<int> resultParm;

    tie(inputParm, target, resultParm) = GENERATE(table<vector<int>, int, vector<int>>({
        make_tuple(vector<int>{5, 7, 7, 8, 8, 10}, 8, vector<int>{3, 4}),
        make_tuple(vector<int>{5, 7, 7, 8, 8, 10}, 6, vector<int>{-1, -1}),
        make_tuple(vector<int>{1}, 1, vector<int>{0, 0}),
        make_tuple(vector<int>{2, 2}, 1, vector<int>{-1, -1}),
        make_tuple(vector<int>{}, 0, vector<int>{-1, -1}),
    }));

    REQUIRE_THAT(solution.searchRange(inputParm, target), Equals(resultParm));
}