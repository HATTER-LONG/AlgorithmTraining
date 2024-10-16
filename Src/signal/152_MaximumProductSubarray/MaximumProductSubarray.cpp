#include "Tools/ListNodeTools.h"

#include <algorithm>
#include <catch2/catch.hpp>
#include <climits>
#include <cstddef>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace Catch;
using namespace std;

// DP

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = INT_MIN, iMax = 1, iMin = 1;
        for(auto& num : nums) {
            if(num < 0) {
                swap(iMax, iMin);
            }

            iMax = std::max(iMax * num, num);
            iMin = std::min(iMin * num, num);

            max = std::max(max, iMax);
        }
        return max;
    }
};

TEST_CASE("Check Solution maxProduct method work successfully") {
    Solution solution;
    vector<int> inputParm;
    int result;

    tie(inputParm, result) = GENERATE(table<vector<int>, int>({
        make_tuple(vector<int>{2, 3, -2, 4}, 6),
        make_tuple(vector<int>{-2, 0, -1}, 0),
    }));

    REQUIRE(solution.maxProduct(inputParm) == result);
}