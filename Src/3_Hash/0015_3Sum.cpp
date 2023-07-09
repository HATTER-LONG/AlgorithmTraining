#include <catch2/catch_all.hpp>
#include <unordered_map>
using namespace Catch;
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出 a+b+c=0
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            // 排序后第一个元素已经大于 0，没有必要继续
            if (nums[i] > 0) {
                return result;
            }
            // 去重
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = static_cast<int>(nums.size()) - 1;
            while (right > left) {
                // 注意不要先去重，可能导致 0，0，0 这种情况被漏掉
                if (nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else if (nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else {
                    // 存入结果
                    result.push_back({ nums[i], nums[left], nums[right] });

                    // 左右去重
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;
                    // 由于去重是指向了最后一个相同的元素，所以这里还要再移动一次
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};

TEST_CASE("Check Solution threeSum method work successfully")
{
    Solution solution;

    vector<int> param;
    vector<vector<int>> result;
    tie(param, result) = GENERATE(table<vector<int>, vector<vector<int>>>({
        make_tuple(vector<int> { -1, 0, 1, 2, -1, -4 },
                   vector<vector<int>> { { -1, -1, 2 }, { -1, 0, 1 } }),
        make_tuple(vector<int> { 0, 1, 1 }, vector<vector<int>> {}),
        make_tuple(vector<int> { 0, 0, 0 }, vector<vector<int>> { { 0, 0, 0 } }),
    }));

    CAPTURE(param, result);
    REQUIRE_THAT(solution.threeSum(param), Matchers::Equals(result));
}
