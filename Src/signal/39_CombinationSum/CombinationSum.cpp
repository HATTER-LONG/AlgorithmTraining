#include <catch2/catch.hpp>
#include <string>
#include <tuple>

using namespace Catch;
using namespace std;

// 回溯

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        int sum = 0;
        size_t n = candidates.size();
        function<void(int)> dfs = [&](int back) {
            if(sum == target) {
                ans.emplace_back(combine.begin(), combine.end());
            } else if(sum > target) {
                return;
            } else {
                for(size_t i = back; i != n; i++) {
                    combine.push_back(candidates[i]);
                    sum += candidates[i];
                    dfs(i);
                    sum -= candidates[i];
                    combine.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};

TEST_CASE("Check Solution combinationSum method work successfully") {
    Solution solution;

    vector<int> inputParm;
    int target = 0;
    vector<vector<int>> resultParm;

    tie(inputParm, target, resultParm) = GENERATE(table<vector<int>, int, vector<vector<int>>>({
        make_tuple(vector<int>{2, 3, 6, 7}, 7, vector<vector<int>>{{7}, {2, 2, 3}}),
        make_tuple(vector<int>{2, 3, 5}, 8, vector<vector<int>>{{2, 2, 2, 2}, {2, 3, 3}, {3, 5}}),
    }));

    CAPTURE(inputParm, target, resultParm);
    REQUIRE_THAT(solution.combinationSum(inputParm, target), Contains(resultParm));
}