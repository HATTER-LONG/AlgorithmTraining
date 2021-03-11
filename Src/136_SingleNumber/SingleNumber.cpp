#include <algorithm>
#include <catch2/catch.hpp>
#include <climits>
#include <cstddef>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>
using namespace Catch;
using namespace std;

// 异或使用

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int ret = 0;
        for (auto& e : nums)
            ret ^= e;
        return ret;
    }
};

TEST_CASE("Check Solution singleNumber method work successfully")
{
    Solution solution;

    vector<int> inputParm;
    int resultParm = 0;

    tie(inputParm, resultParm) = GENERATE(table<vector<int>, int>({
        make_tuple(vector<int> { 2, 2, 1 }, 1),
        make_tuple(vector<int> { 4, 1, 2, 1, 2 }, 4),
    }));

    CAPTURE(inputParm, resultParm);

    REQUIRE(solution.singleNumber(inputParm) == (resultParm));
}