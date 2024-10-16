#include <catch2/catch.hpp>
#include <string>
#include <tuple>

using namespace Catch;
using namespace std;

// 回溯

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        auto len = nums.size();
        vector<vector<int>> res;
        if(len == 0) {
            return res;
        }
        vector<bool> used(len, false);
        vector<int> path;

        function<void(size_t)> dfs = [&](size_t depth) {
            if(depth == len) {
                res.push_back(path);
                return;
            }
            // 在非叶子结点处，产生不同的分支，这一操作的语义是：
            // 在还未选择的数中依次选择一个元素作为下一个位置的元素，这显然得通过一个循环实现。

            for(size_t i = 0; i < len; i++) {
                if(!used[i]) {
                    path.push_back(nums[i]);
                    used[i] = true;

                    dfs(depth + 1);

                    // 注意：下面这两行代码发生 「回溯」，回溯发生在从 深层结点 回到 浅层结点
                    // 的过程，代码在形式上和递归之前是对称的
                    used[i] = false;
                    path.pop_back();
                }
            }
        };

        dfs(0);
        return res;
    }
};

TEST_CASE("Check Solution permute method work successfully") {
    Solution solution;

    vector<int> inputParm;

    vector<vector<int>> resultParm;

    tie(inputParm, resultParm) = GENERATE(table<vector<int>, vector<vector<int>>>({
        make_tuple(
            vector<int>{1, 2, 3},
            vector<vector<int>>{{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}}),
    }));

    CAPTURE(inputParm, resultParm);
    REQUIRE_THAT(solution.permute(inputParm), Contains(resultParm));
}