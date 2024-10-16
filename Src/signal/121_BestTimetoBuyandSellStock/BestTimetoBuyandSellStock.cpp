#include <catch2/catch.hpp>
#include <climits>
#include <cstddef>
#include <string>
#include <tuple>

using namespace Catch;
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPrices = 0;
        int minPrices = INT_MAX;

        for(auto price : prices) {
            maxPrices = max(maxPrices, price - minPrices);
            minPrices = min(price, minPrices);
        }
        return maxPrices;
    }
};

TEST_CASE("Check Solution maxProfit method work successfully") {
    Solution solution;

    vector<int> inputParm;
    int resultParm = 0;

    tie(inputParm, resultParm) = GENERATE(table<vector<int>, int>({
        make_tuple(vector<int>{7, 1, 5, 3, 6, 4}, 5),
        make_tuple(vector<int>{7, 6, 4, 3, 1}, 0),
    }));

    CAPTURE(inputParm, resultParm);

    REQUIRE(solution.maxProfit(inputParm) == (resultParm));
}