#include "Tools/Tools.hpp"

void rotate(vector<vector<int>>& matrix) {
    size_t n = matrix.size();
    for(size_t i = 0; i < n / 2; i++) {
        for(size_t j = 0; j < (n + 1) / 2; j++) {
            swap(matrix[i][j], matrix[n - j - 1][i]);
            swap(matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1]);
            swap(matrix[n - i - 1][n - j - 1], matrix[j][n - i - 1]);
        }
    }
}

TEST_CASE("Check Solution rotate method work successfully") {
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
    rotate(inputParm);
    REQUIRE_THAT(inputParm, Catch::Equals(resultParm));
}
