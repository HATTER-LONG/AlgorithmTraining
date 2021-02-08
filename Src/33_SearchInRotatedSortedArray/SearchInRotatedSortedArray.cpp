#include <catch2/catch.hpp>
#include <string>
#include <tuple>

using namespace Catch;
using namespace std;

// 二分法
class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int n = static_cast<int>(nums.size());
        if (!n)
        {
            return -1;
        }
        if (n == 1)
        {
            return nums[0] == target ? 0 : -1;
        }

        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[left] <= nums[mid])
            {
                if (nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};


TEST_CASE("Check Solution search method work successfully")
{
    Solution solution;

    vector<int> inputParm;
    int target = 0;
    int resultParm;

    tie(inputParm, target, resultParm) = GENERATE(table<vector<int>, int, int>({
        make_tuple(vector<int> { 4, 5, 6, 7, 0, 1, 2 }, 0, 4),
        make_tuple(vector<int> { 4, 5, 6, 7, 0, 1, 2 }, 3, -1),
        make_tuple(vector<int> { 4, 5, 6, 7, 8, 0, 1, 2 }, 0, 5),
        make_tuple(vector<int> { 1 }, 0, -1),
    }));

    REQUIRE(solution.search(inputParm, target) == resultParm);
}