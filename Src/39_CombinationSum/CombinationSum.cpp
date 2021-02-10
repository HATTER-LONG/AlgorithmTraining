#include <catch2/catch.hpp>
#include <string>
#include <tuple>

using namespace Catch;
using namespace std;

//回溯
class Solution
{
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, size_t idx)
    {
        if (idx == candidates.size())
        {
            return;
        }
        if (target == 0)
        {
            ans.emplace_back(combine);
            return;
        }
        dfs(candidates, target, ans, combine, idx + 1);
        if (target - candidates[idx] >= 0)
        {
            combine.emplace_back(candidates[idx]);   //选中当前 idx
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();   // 撤销当前选择
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> combine;

        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};


TEST_CASE("Check Solution combinationSum method work successfully")
{
    Solution solution;

    vector<int> inputParm;
    int target = 0;
    vector<vector<int>> resultParm;

    tie(inputParm, target, resultParm) = GENERATE(table<vector<int>, int, vector<vector<int>>>({
        make_tuple(vector<int> { 2, 3, 6, 7 }, 7, vector<vector<int>> { { 7 }, { 2, 2, 3 } }),
        make_tuple(vector<int> { 2, 3, 5 }, 8, vector<vector<int>> { { 2, 2, 2, 2 }, { 2, 3, 3 }, { 3, 5 } }),
    }));

    CAPTURE(inputParm, target, resultParm);
    REQUIRE_THAT(solution.combinationSum(inputParm, target), Contains(resultParm));
}