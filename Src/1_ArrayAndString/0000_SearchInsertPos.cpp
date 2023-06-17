#include <catch2/catch_all.hpp>
using namespace Catch;
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] < target)
                lo = mid + 1;
            else if (nums[mid] > target)
                hi = mid - 1;
            else
                return mid;
        }
        return lo;
    }
};

TEST_CASE("Check Solution searchInsert method work successfully")
{
    Solution solution;

    vector<int> param;
    int target = -1;
    int result = -1;
    tie(param, target, result) = GENERATE(table<vector<int>, int, int>({
        make_tuple(vector<int> { 1, 3, 5, 6 }, 5, 2),
        make_tuple(vector<int> { 1, 3, 5, 6 }, 2, 1),
        make_tuple(vector<int> { 1, 3, 5, 6 }, 0, 0),
        make_tuple(vector<int> { 1, 3, 5, 6 }, 7, 4),
    }));

    REQUIRE(solution.searchInsert(param, target) == result);
}
