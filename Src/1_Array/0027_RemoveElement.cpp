#include "Tools/Tools.hpp"
using namespace std;
class Solution {
public:
    // 同方向双指针
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for(size_t fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if(nums[fastIndex] != val) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
    // 对向双指针
    int removeElement_over(vector<int>& nums, int val) {
        int leftIndex = 0, rightIndex = nums.size() - 1;
        while(leftIndex <= rightIndex) {
            // 左指针找到不等于 val 的值
            while(leftIndex <= rightIndex && nums[leftIndex] != val)
                leftIndex++;
            // 右指针找到等于 val 的值
            while(leftIndex <= rightIndex && nums[rightIndex] == val)
                rightIndex--;
            // 交换两个值
            if(leftIndex < rightIndex) {
                swap(nums[leftIndex], nums[rightIndex]);
                leftIndex++;
                rightIndex--;
            }
        }
        return leftIndex;
    }
    // 反向双指针
    int removeElement_revert(vector<int>& nums, int val) {
        int len = nums.size();
        int fast = len - 1, slow = len - 1;
        while(fast >= 0) {
            if(nums[fast] == val && nums[slow] != val) {
                nums[fast] = nums[slow];
                fast--;
                slow--;
            } else if(nums[fast] == val && fast == slow) {
                fast--;
                slow--;
            } else {
                fast--;
            }
        }
        return slow + 1;
    }
};

TEST_CASE("Check Solution removeElement method work successfully") {
    Solution solution;

    vector<int> param;

    int target, result;
    tie(param, target, result) = GENERATE(table<vector<int>, int, int>({
        make_tuple(vector<int>{3, 2, 2, 3}, 3, 2),
        make_tuple(vector<int>{0, 1, 2, 2, 3, 0, 4, 2}, 2, 5),
    }));
    CAPTURE(param, target, result);
    REQUIRE(solution.removeElement_revert(param, target) == result);
}
