#include "Tools/Tools.hpp"

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
    {
        // 1. 按照对角线的方向遍历
        // 2. 从左上角开始，每次遍历的方向都是向右上或者向左下
        // 3. 如果向右上，那么下一个位置是(i - 1, j + 1)
        // 4. 如果向左下，那么下一个位置是(i + 1, j - 1)
        size_t row = matrix.size();      // 行数
        size_t col = matrix[0].size();   // 列数
        vector<int> result;
        for (size_t i = 0; i < row + col - 1; i++) {   // 对角线的个数
            if (i % 2 == 0) {   // 偶数对角线，向右上
                for (size_t j = 0; j <= i; j++) {   // 对角线上的元素个数
                    if (j < row && i - j < col)     // 判断是否越界
                        result.push_back(matrix[j][i - j]);
                }
            } else {   // 奇数，向左下
                for (size_t j = i; j >= 0; j--) {
                    if (j < row && i - j < col)
                        result.push_back(matrix[j][i - j]);
                }
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

    tie(inputParm, resultParm) =
        GENERATE(table<vector<vector<int>>, vector<int>>({
            make_tuple(
                vector<vector<int>> {
                    { 1, 2, 3 },
                    { 4, 5, 6 },
                    { 7, 8, 9 },
                },
                vector<int> { 1, 2, 4, 7, 5, 3, 6, 8, 9 }),
        }));

    CAPTURE(inputParm, resultParm);
    solution.findDiagonalOrder(inputParm);
    REQUIRE_THAT(inputParm, Catch::Matchers::Equals(resultParm));
}
