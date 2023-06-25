#include "Tools/Tools.hpp"

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int result = INT32_MAX;
        int sum = 0;            // 滑动窗口的和
        int i = 0;              // 滑动窗口的左边界
        int subArraySize = 0;   // 滑动窗口的大小

        for (size_t j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用 while，每次更新 i 之后都要判断一次是否满足条件
            while (sum >= target) {
                subArraySize = j - i + 1;   // 子序列的长度
                result = result < subArraySize ? result : subArraySize;
                sum -= nums[i++];   // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值，说明没有满足条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};

TEST_CASE("Check Solution minSubArrayLen method work successfully")
{
    Solution solution;
    vector<int> inputParm;
    int target = 0, resultParm = 0;

    tie(inputParm, target, resultParm) = GENERATE(table<vector<int>, int, int>({
        make_tuple(vector<int> { 2, 3, 1, 2, 4, 3 }, 7, 2),
        make_tuple(vector<int> { 1, 4, 4 }, 4, 1),
    }));

    CAPTURE(target, inputParm, resultParm);
    REQUIRE(solution.minSubArrayLen(target, inputParm) == resultParm);
}
