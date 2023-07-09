#include <catch2/catch_all.hpp>
#include <unordered_map>
using namespace Catch;
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < static_cast<int>(nums.size()); k++) {
            // 减枝
            if (nums[k] > target && nums[k] >= 0)
                break;

            // 重复元素
            if (k > 0 && nums[k] == nums[k - 1])
                continue;

            for (int i = k + 1; i < static_cast<int>(nums.size()); i++) {
                // 2 重减枝
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0)
                    break;
                // 重复元素
                if (i > k + 1 && nums[i] == nums[i - 1])
                    continue;
                int left = i + 1;
                int right = static_cast<int>(nums.size()) - 1;
                while (right > left) {
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target)
                        right--;
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target)
                        left++;
                    else {
                        result.push_back(vector<int> { nums[k], nums[i], nums[left], nums[right] });
                        while (right > left && nums[left] == nums[left + 1])
                            left++;
                        while (right > left && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

TEST_CASE("Check Solution fourSum method work successfully")
{
    Solution solution;

    vector<int> param;
    int target = 0;

    vector<vector<int>> result;
    tie(param, target, result) = GENERATE(table<vector<int>, int, vector<vector<int>>>({
        make_tuple(vector<int> { 1, 0, -1, 0, -2, 2 },
                   0,
                   vector<vector<int>> { { -2, -1, 1, 2 }, { -2, 0, 0, 2 }, { -1, 0, 0, 1 } }),
    }));

    CAPTURE(param, target, result);
    REQUIRE_THAT(solution.fourSum(param, target), Matchers::Equals(result));
}
