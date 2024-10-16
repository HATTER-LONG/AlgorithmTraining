#include <catch2/catch.hpp>
#include <cstddef>
#include <string>
#include <tuple>

using namespace Catch;
using namespace std;

// 动态规划

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        size_t rows = grid.size(), columns = grid[0].size();
        auto dp = vector<vector<int>>(rows, vector<int>(columns));
        dp[0][0] = grid[0][0];
        for(size_t i = 1; i < rows; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for(size_t j = 1; j < columns; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for(size_t i = 1; i < rows; i++) {
            for(size_t j = 1; j < columns; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[rows - 1][columns - 1];
    }
};

TEST_CASE("Check Solution minPathSum method work successfully") {
    Solution solution;

    vector<vector<int>> inputParm;

    int resultParm;

    tie(inputParm, resultParm) = GENERATE(table<vector<vector<int>>, int>({
        make_tuple(vector<vector<int>>{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 7),
        make_tuple(vector<vector<int>>{{1, 2, 3}, {4, 5, 6}}, 12),
    }));

    CAPTURE(inputParm, resultParm);
    REQUIRE(solution.minPathSum(inputParm) == resultParm);
}