#include "Tools/Tools.hpp"

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        size_t rows = matrix.size(), cols = matrix[0].size();
        // 记录哪些行和列需要置零
        vector<bool> row(rows, false), col(cols, false);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0)
                    row[i] = col[j] = true;
            }
        }

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j)
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
        }
    }
};

TEST_CASE("Check Solution setZeroes method work successfully")
{
    Solution solution;
    vector<vector<int>> inputParm;

    vector<vector<int>> resultParm;

    tie(inputParm, resultParm) =
        GENERATE(table<vector<vector<int>>, vector<vector<int>>>({
            make_tuple(
                vector<vector<int>> {
                    { 1, 1, 1 },
                    { 1, 0, 1 },
                    { 1, 1, 1 },
                },
                vector<vector<int>> {
                    { 1, 0, 1 },
                    { 0, 0, 0 },
                    { 1, 0, 1 },
                }),
            make_tuple(
                vector<vector<int>> {
                    { 0, 1, 9, 0 },
                    { 2, 4, 8, 10 },
                    { 13, 3, 6, 7 },
                    { 15, 14, 12, 16 },
                },
                vector<vector<int>> {
                    { 0, 0, 0, 0 },
                    { 0, 4, 8, 0 },
                    { 0, 3, 6, 0 },
                    { 0, 14, 12, 0 },
                }),
        }));

    CAPTURE(inputParm, resultParm);
    solution.setZeroes(inputParm);
    REQUIRE_THAT(inputParm, Catch::Matchers::Equals(resultParm));
}
