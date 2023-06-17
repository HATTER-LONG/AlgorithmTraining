#include <catch2/catch_all.hpp>
using namespace Catch;
using namespace std;

class Solution
{
public:
    int test(vector<int>& numsL, vector<int>& numsR)
    {
        return numsL[0] + numsR[0];
    }
};

TEST_CASE("Check Solution test method work successfully")
{
    Solution solution;

    vector<int> LeftParm, RightParm;
    double result = -1;
    // clang-format off
    tie(LeftParm, RightParm, result) = 
        GENERATE(table<vector<int>, vector<int>, double>
            (
                {
                    make_tuple(vector<int>{1, 3},vector<int>{2}, 3),
                    make_tuple(vector<int>{1, 2},vector<int>{3, 4}, 4),
                }
            )
        );
    // clang-format on;

    REQUIRE(solution.test(LeftParm, RightParm) == result);
}
