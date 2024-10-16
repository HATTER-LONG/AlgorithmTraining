#include <catch2/catch.hpp>
#include <cstddef>
#include <string>
#include <tuple>
#include <unordered_map>

using namespace Catch;
using namespace std;

// 动态规划
// 动态方程：dp[i][j] = dp[i-1][j] + dp[i][j-1]
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            f[i][0] = 1;
        }
        for(int j = 0; j < n; ++j) {
            f[0][j] = 1;
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};
;

TEST_CASE("Check Solution uniquePaths method work successfully") {
    Solution solution;

    int param1 = 0, param2 = 0;
    int result = 0;

    tie(param1, param2, result) = GENERATE(table<int, int, int>(
        {make_tuple(3, 7, 28), make_tuple(3, 2, 3), make_tuple(7, 3, 28), make_tuple(3, 3, 6)}));

    CAPTURE(param1, param2, result);
    REQUIRE(solution.uniquePaths(param1, param2) == result);
}