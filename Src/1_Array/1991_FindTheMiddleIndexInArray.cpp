#include <catch2/catch_all.hpp>
using namespace Catch;
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int>& numsL)
    {
        int total = accumulate(numsL.begin(), numsL.end(), 0);
        int leftSum = 0;
        for (size_t i = 0; i < numsL.size(); i++) {
            leftSum += numsL[i];
            if (total - leftSum == leftSum - numsL[i])
                return static_cast<int>(i);
        }
        return -1;
    }
};

TEST_CASE("Check Solution test method work successfully")
{
    Solution solution;

    vector<int> LeftParm;
    double result = -1;
    tie(LeftParm, result) = GENERATE(table<vector<int>, int>({
        make_tuple(vector<int> { 1, 7, 3, 6, 5, 6 }, 3),
        make_tuple(vector<int> { 1, 2, 3 }, -1),
    }));

    REQUIRE(solution.pivotIndex(LeftParm) == result);
}
