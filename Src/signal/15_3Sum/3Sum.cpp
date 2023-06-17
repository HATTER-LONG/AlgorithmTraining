#include <catch2/catch.hpp>
#include <cstddef>
#include <string>
#include <tuple>

using namespace std;
using namespace Catch;

/**
    双指针方法
    nums.sort()
    for first = 0 .. n-1
        if first == 0 or nums[first] != nums[first-1] then
            // 第三重循环对应的指针
            third = n-1
            for second = first+1 .. n-1
                if second == first+1 or nums[second] != nums[second-1] then
                    // 向左移动指针，直到 a+b+c 不大于 0
                    while nums[first]+nums[second]+nums[third] > 0
                        third = third-1
                    // 判断是否有 a+b+c==0
                    check(first, second, third)
 */

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        const size_t NUMSSIZE = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (size_t first = 0; first < NUMSSIZE; first++)
        {
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            size_t third = NUMSSIZE - 1;
            int target = -nums[first];

            for (size_t second = first + 1; second < NUMSSIZE; second++)
            {
                if (second > first + 1 && nums[second] == nums[second - 1])
                {
                    continue;
                }
                while (second < third && nums[second] + nums[third] > target)
                {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third)
                {
                    break;
                }
                if (nums[second] + nums[third] == target)
                {
                    result.push_back({ nums[first], nums[second], nums[third] });
                }
            }
        }
        return result;
    }
};


TEST_CASE("Check Solution threeSum method work successfully ")
{
    Solution solution;

    vector<int> inputStr;
    vector<vector<int>> result;

    tie(inputStr, result) = GENERATE(table<vector<int>, vector<vector<int>>>({
        make_tuple(vector<int> { -1, 0, 1, 2, -1, -4 }, vector<vector<int>> { { -1, -1, 2 }, { -1, 0, 1 } }),
        make_tuple(vector<int> {}, vector<vector<int>> {}),
        make_tuple(vector<int> { 0 }, vector<vector<int>> {}),
    }));
    CAPTURE(inputStr, result);
    REQUIRE_THAT(solution.threeSum(inputStr), Equals(result));
}