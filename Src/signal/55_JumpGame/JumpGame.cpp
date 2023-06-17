#include <catch2/catch.hpp>
#include <cstddef>
#include <string>
#include <tuple>
#include <unordered_map>

using namespace Catch;
using namespace std;

//貪心

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        auto n = nums.size();
        size_t rightmost = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (i <= rightmost)
            {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1)
                    return true;
            }
        }
        return false;
    }
};

TEST_CASE("Check Solution canJump method work successfully")
{
    Solution solution;

    vector<int> inputParm;

    bool resultParm;

    tie(inputParm, resultParm) = GENERATE(table<vector<int>, bool>({
        make_tuple(vector<int> { 2, 3, 1, 1, 4 }, true),
        make_tuple(vector<int> { 3, 2, 1, 0, 4 }, false),
    }));

    CAPTURE(inputParm, resultParm);
    REQUIRE(solution.canJump(inputParm) == resultParm);
}