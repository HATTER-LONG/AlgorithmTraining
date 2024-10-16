#include "Tools/Tools.hpp"

#include <stack>

/*
 * 题目描述
 * 给定一个二维的 0-1 矩阵，其中 0 表示海洋，1 表示陆地。
 * 单独的或相邻的陆地可以形成岛屿，每个格子只与其上下左右四个格子相邻。求最大的岛屿面积。
 *
 * 输入输出样例
 *   输入是一个二维数组，输出是一个整数，表示最大的岛屿面积。
 * Input:
 * [[1,0,1,1,0,1,0,1],
 *  [1,0,1,1,0,1,1,1],
 *  [0,0,0,0,0,0,0,1]]
 * Output: 6
 * 最大的岛屿面积为 6，位于最右侧。
 *
 */

vector<int> dir{-1, 0, 1, 0, -1};

int dfs(vector<vector<int>>& grid, int y, int x) {
    if(y < 0 || y >= static_cast<int>(grid.size()) || x < 0 ||
       x >= static_cast<int>(grid[0].size()) || grid[y][x] == 0) {
        return 0;
    }

    grid[y][x] = 0;
    return 1 + dfs(grid, y + 1, x) + dfs(grid, y - 1, x) + dfs(grid, y, x + 1) +
           dfs(grid, y, x - 1);
}
int dfsFirstCheck(vector<vector<int>>& grid, int y, int x) {
    if(grid[y][x] == 0)
        return 0;
    grid[y][x] = 0;
    int searchX, searchY, area = 1;
    for(int i = 0; i < 4; i++) {
        searchX = x + dir[i + 1], searchY = y + dir[i];
        if(searchX >= 0 && searchX < static_cast<int>(grid[0].size()) && searchY >= 0 &&
           searchY < static_cast<int>(grid.size())) {
            {
                area += dfs(grid, searchY, searchX);
            }
        }
    }
    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    if(grid.empty() || grid.empty())
        return 0;
    int maxArea = 0, m = grid.size(), n = m ? grid[0].size() : 0;
    for(int y = 0; y < m; y++) {
        for(int x = 0; x < n; x++) {
            if(grid[y][x] == 1) {
                maxArea = max(maxArea, dfs(grid, y, x));
            }
        }
    }
    return maxArea;
}

int maxAreaOfIslandStack(vector<vector<int>>& grid) {
    int m = grid.size(), n = m ? grid[0].size() : 0, localArea = 0, searchX = 0, searchY = 0,
        area = 0;
    for(int y = 0; y < m; y++) {
        for(int x = 0; x < n; x++) {
            if(grid[y][x]) {
                localArea = 1;
                grid[y][x] = 0;
                stack<pair<int, int>> island;
                island.push({y, x});
                while(!island.empty()) {
                    auto [ty, tx] = island.top();
                    island.pop();

                    for(int k = 0; k < 4; k++) {
                        searchX = tx + dir[k + 1]; // 遵循上、右、下、左
                        searchY = ty + dir[k];

                        if(searchX >= 0 && searchX < n && searchY >= 0 && searchY < m &&
                           grid[searchY][searchX] == 1) {
                            grid[searchY][searchX] = 0;
                            localArea++;
                            island.push({searchY, searchX});
                        }
                    }
                }
                area = max(area, localArea);
            }
        }
    }
    return area;
}

TEST_CASE("test max area of island func") {
    vector<vector<int>> input;
    int result;

    tie(input, result) = GENERATE(table<vector<vector<int>>, int>({make_tuple(
        vector<vector<int>>{
            {1, 0, 1, 1, 0, 1, 0, 1}, {1, 0, 1, 1, 0, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 1}},
        6)}));

    CAPTURE(input, result);
    REQUIRE(maxAreaOfIsland(input) == result);
}
