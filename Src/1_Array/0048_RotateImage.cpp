#include "Tools/Tools.hpp"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        n = matrix.size();

        // 上下对称 + 主对角线对称
        upDownSymmetry(matrix);
        mainDiagonalSymmetry(matrix);

        // 主对角线对称 + 左右对称
        // mainDiagonalSymmetry(matrix);
        // leftRightSymmetry(matrix);

        // 左右对称 + 副对角线对称
        // leftRightSymmetry(matrix);
        // subdiagSymmetry(matrix);

        // 副对角线对称 + 上下对称
        // subdiagSymmetry(matrix);
        // upDownSymmetry(matrix);
    }

private:
    size_t n;
    // 上下对称
    void upDownSymmetry(vector<vector<int>>& matrix) {
        for(size_t i = 0; i < n / 2; i++)
            for(size_t j = 0; j < n; j++)
                swap(matrix[i][j], matrix[n - i - 1][j]);
    }

    // 左右对称
    void leftRightSymmetry(vector<vector<int>>& matrix) {
        for(size_t i = 0; i < n; i++)
            for(size_t j = 0; j < n / 2; j++)
                swap(matrix[i][j], matrix[i][n - j - 1]);
    }

    // 主对角线对称
    void mainDiagonalSymmetry(vector<vector<int>>& matrix) {
        for(size_t i = 0; i < n; i++)
            for(size_t j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
    }

    // 副对角线对称
    void secondaryDiagonalSymmetry(vector<vector<int>>& matrix) {
        for(size_t i = 0; i < n; i++)
            for(size_t j = 0; j < n - i - 1; j++)
                swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
    }
};

TEST_CASE("Check Solution rotate method work successfully") {
    Solution solution;
    vector<vector<int>> inputParm;

    vector<vector<int>> resultParm;

    tie(inputParm, resultParm) = GENERATE(table<vector<vector<int>>, vector<vector<int>>>({
        make_tuple(
            vector<vector<int>>{
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9},
            },
            vector<vector<int>>{
                {7, 4, 1},
                {8, 5, 2},
                {9, 6, 3},
            }),
        make_tuple(
            vector<vector<int>>{
                {5, 1, 9, 11},
                {2, 4, 8, 10},
                {13, 3, 6, 7},
                {15, 14, 12, 16},
            },
            vector<vector<int>>{
                {15, 13, 2, 5},
                {14, 3, 4, 1},
                {12, 6, 8, 9},
                {16, 7, 10, 11},
            }),
    }));

    CAPTURE(inputParm, resultParm);
    solution.rotate(inputParm);
    REQUIRE_THAT(inputParm, Catch::Matchers::Equals(resultParm));
}
