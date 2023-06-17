#include <catch2/catch.hpp>
#include <cstddef>
#include <cstdint>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace Catch;
using namespace std;

//回溯

class Solution
{
public:
    void dfs(size_t cur, vector<int>& nums)
    {
        if (cur == nums.size())
        {
            return ans.push_back(t);
        }

        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        t.pop_back();
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        dfs(0, nums);
        return ans;
    }

private:
    vector<int> t;
    vector<vector<int>> ans;
};

TEST_CASE("Check Solution subsets method work successfully")
{
    Solution solution;

    vector<int> inputParm;
    vector<vector<int>> resultParm;

    tie(inputParm, resultParm) = GENERATE(table<vector<int>, vector<vector<int>>>({
        make_tuple(vector<int> { 1, 2, 3 },
            vector<vector<int>> { {}, { 1 }, { 2 }, { 1, 2 }, { 3 }, { 1, 3 }, { 2, 3 }, { 1, 2, 3 } }),
        make_tuple(vector<int> { 0 }, vector<vector<int>> { {}, { 0 } }),
    }));

    CAPTURE(inputParm, resultParm);

    REQUIRE_THAT(solution.subsets(inputParm), UnorderedEquals(resultParm));
}