#include <algorithm>
#include <catch2/catch.hpp>
#include <climits>
#include <cstddef>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace Catch;
using namespace std;

class Solution
{
public:
    void infect(vector<vector<char>>& grid, size_t i, size_t j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
        {
            return;
        }
        grid[i][j] = '2';
        infect(grid, i + 1, j);
        infect(grid, i - 1, j);
        infect(grid, i, j + 1);
        infect(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int islandNum = 0;
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    infect(grid, i, j);
                    islandNum++;
                }
            }
        }
        return islandNum;
    }
};

TEST_CASE("Check Solution numIslands method work successfully")
{
    Solution solution;
    vector<vector<char>> inputParmA;
    int result = 0;
    // clang-format off
    tie(inputParmA, result) = GENERATE(table<vector<vector<char>>, int>({
        make_tuple(vector<vector<char>> { 
            { '1', '1', '1', '1', '0' }, 
            { '1', '1', '0', '1', '0' },
            { '1', '1', '0', '0', '0' }, 
            { '0', '0', '0', '0', '0' } },
           1),
        make_tuple(vector<vector<char>> { 
            { '1','1','0','0','0' }, 
            { '1','1','0','0','0' },
            { '0','0','1','0','0' }, 
            { '0','0','0','1','1' } },
            3),
    }));
    //clang -format on
    REQUIRE(solution.numIslands(inputParmA) == result);
}