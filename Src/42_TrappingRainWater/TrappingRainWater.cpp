#include <catch2/catch.hpp>
#include <string>
#include <tuple>

using namespace Catch;
using namespace std;
//双指针法
class Solution
{
public:
    int trap(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right)
        {
            if (height[left] < height[right])   //这里判断 left height 小于 right height
                                                //保证了当前指向与最高的 left 差值即存入的雨水
            {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else
            {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};


TEST_CASE("Check Solution trap method work successfully")
{
    Solution solution;

    vector<int> inputParm;

    int resultParm;

    tie(inputParm, resultParm) = GENERATE(table<vector<int>, int>({
        make_tuple(vector<int> { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }, 6),
        make_tuple(vector<int> { 4, 2, 0, 3, 2, 5 }, 9),
        make_tuple(vector<int> { 4, 0, 0, 1, 0, 2 }, 7),
        make_tuple(vector<int> { 5, 4, 1, 2 }, 1),
    }));

    CAPTURE(inputParm, resultParm);
    REQUIRE(solution.trap(inputParm) == resultParm);
}