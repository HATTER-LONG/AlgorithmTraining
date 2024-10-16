#include "Tools/Tools.hpp"

/*
 * 题目描述
 * 给定一个二维矩阵，已知每行和每列都是增序的，尝试设计一个快速搜索一个数字是否在矩
 * 阵中存在的算法。
 *
 * 输入输出样例
 * 输入是一个二维整数矩阵，和一个待搜索整数。输出是一个布尔值，表示这个整数是否存在
 * 于矩阵中。
 * Input: matrix =
 * [ [1, 4, 7, 11, 15],
 *   [2, 5, 8, 12, 19],
 *   [3, 6, 9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]], target = 5 Output: true
 */

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if(m == 0) {
        return false;
    }

    int n = matrix[0].size();
    int i = 0, j = n - 1;
    while(i < m && j >= 0) {
        if(matrix[i][j] == target) {
            return true;
        }
        if(matrix[i][j] > target) {
            j--;
        } else {
            i--;
        }
    }
    return false;
}

TEST_CASE("test search matrix") {
    vector<vector<int>> input;
    int target;

    bool result;

    tie(input, target, result) = GENERATE(
        table<vector<vector<int>>, int, bool>({make_tuple(vector<vector<int>>{{1, 4, 7, 11, 15},
                                                                              {2, 5, 8, 12, 19},
                                                                              {3, 6, 9, 16, 22},
                                                                              {10, 13, 14, 17, 24},
                                                                              {18, 21, 23, 26, 30}},
                                                          5, true)}));
}
