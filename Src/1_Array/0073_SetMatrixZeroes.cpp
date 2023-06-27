#include "Tools/Tools.hpp"

#include <cmath>
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
    {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty())
            return result;
        size_t row = matrix.size();                    // 行数
        size_t col = matrix[0].size();                 // 列数
        for (size_t i = 0; i < row + col - 1; i++) {   // 对角线的个数
            if (i % 2 == 0) {                          // 偶数对角线，向右上
                for (int x = min(i, row - 1); x >= max(0, static_cast<int>(i - col + 1));
                     x--)   // 从下往上遍历
                    result.push_back(matrix[x][i - x]);
            } else {   // 奇数，向左下
                for (int x = max(0, static_cast<int>(i - col + 1));
                     x <= static_cast<int>(min(i, row - 1));
                     x++)   // 从上往下遍历
                    result.push_back(matrix[x][i - x]);
            }
        }
        return result;
    }
};

TEST_CASE("Check Solution findDiagonalOrder method work successfully")
{
    Solution solution;
    vector<vector<int>> inputParm;

    vector<int> resultParm;

    tie(inputParm, resultParm) = GENERATE(table<vector<vector<int>>, vector<int>>({
        make_tuple(
            vector<vector<int>> {
                { 1, 2, 3 },
                { 4, 5, 6 },
                { 7, 8, 9 },
            },
            vector<int> { 1, 2, 4, 7, 5, 3, 6, 8, 9 }),
    }));

    CAPTURE(inputParm, resultParm);
    REQUIRE_THAT(solution.findDiagonalOrder(inputParm), Catch::Matchers::Equals(resultParm));
}
