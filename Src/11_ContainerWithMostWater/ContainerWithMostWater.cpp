#include <catch2/catch.hpp>
#include <cstddef>
#include <string>
#include <tuple>

using namespace std;
using namespace Catch;

//双指针
class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int left = 1;
        int right = height.size();
        int area = 0;
        while (left < right && left > 0 && right > 0)
        {
            int newArea = (min(height[left - 1], height[right - 1]) * (right - left));

            if (newArea > area)
            {
                area = newArea;
            }

            if (height[left - 1] < height[right - 1])
            {
                left = findeLeftNextIndex(height, left, right);
            }
            else if (height[left - 1] > height[right - 1])
            {
                right = findRightNextIndex(height, left, right);
            }
            else if (height[left - 1] == height[right - 1])
            {
                left++;
                right--;
            }
        }
        return area;
    }

    int findeLeftNextIndex(vector<int>& height, int left, int right)
    {
        int heightNum = height[left - 1];
        for (int i = left - 1; i < right; i++)
        {
            if (height[i] > heightNum)
                return i + 1;
        }
        return -1;
    }
    int findRightNextIndex(vector<int>& height, int left, int right)
    {
        int heightNum = height[right - 1];
        for (int i = right - 1; i > left - 1; i--)
        {
            if (height[i] > heightNum)
                return i + 1;
        }
        return -1;
    }
};



TEST_CASE("Check Solution isMatch method work successfully ")
{
    Solution solution;

    vector<int> inputStr;
    int result;

    tie(inputStr, result) = GENERATE(table<vector<int>, int>({
        make_tuple(vector<int> { 1, 8, 6, 2, 5, 4, 8, 3, 7 }, 49),
        make_tuple(vector<int> { 1, 8, 6, 2, 5, 4, 9, 8, 2 }, 48),
        make_tuple(vector<int> { 1, 1 }, 1),
        make_tuple(vector<int> { 4, 3, 2, 1, 4 }, 16),
        make_tuple(vector<int> { 1, 2, 1 }, 2),
    }));
    CAPTURE(inputStr, result);
    REQUIRE(solution.maxArea(inputStr) == result);
}