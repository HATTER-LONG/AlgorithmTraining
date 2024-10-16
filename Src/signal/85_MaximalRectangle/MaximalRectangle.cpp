#include <catch2/catch.hpp>
#include <cstddef>
#include <cstdint>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace Catch;
using namespace std;

// 栈
// 下边的答案将图转为了柱状图，可以使用 84 题中的栈来优化

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                }
            }
        }

        int ret = 0;
        for(int j = 0; j < n; j++) // 对于每一列使用基于柱状图的方法
        {
            vector<int> up(m, 0), down(m, 0);

            stack<int> stk;
            for(int i = 0; i < m; i++) {
                while(!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }

            stk = stack<int>();
            for(int i = m - 1; i >= 0; i--) {
                while(!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                down[i] = stk.empty() ? m : stk.top();
                stk.push(i);
            }

            for(int i = 0; i < m; i++) {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                ret = max(ret, area);
            }
        }
        return ret;
    }
};

// 将此提转化为柱状图进行暴力破解
// 计算每个元素左侧连续的 1 数量，这样就将其转化成为一个柱状图。

/*
      |1|1|1|1| 5 |
              | 0 |
            |1| 2 |
              | 1 |
            |1| 2 |
        |1|1|1| 4 |
          |1|1| 3 |
*/
class Solution_Break {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));
        // 以下循环计算每个元素左边连续的 1
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                }
            }
        }

        int ret = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '0') {
                    continue;
                }
                int width = left[i][j];
                int area = width;
                // 相当于对每个柱进行求值
                for(int k = i - 1; k >= 0; k--) {
                    width = min(width, left[k][j]);
                    area = max(area, (i - k + 1) * width);
                }
                ret = max(ret, area);
            }
        }
        return ret;
    }
};

TEST_CASE("Check Solution maximalRectangle method work successfully") {
    Solution solution;

    vector<vector<char>> inputParm;
    int resultParm = 0;
    tie(inputParm, resultParm) = GENERATE(table<vector<vector<char>>, int>({
        make_tuple(vector<vector<char>>{{'1', '0', '1', '0', '0'},
                                        {'1', '0', '1', '1', '1'},
                                        {'1', '1', '1', '1', '1'},
                                        {'1', '0', '0', '1', '0'}},
                   6),
        make_tuple(vector<vector<char>>{{}}, 0),
        make_tuple(vector<vector<char>>{{'0'}}, 0),
        make_tuple(vector<vector<char>>{{'1'}}, 1),
        make_tuple(vector<vector<char>>{{'0', '0'}}, 0),
    }));

    CAPTURE(inputParm, resultParm);

    REQUIRE(solution.maximalRectangle(inputParm) == resultParm);
}