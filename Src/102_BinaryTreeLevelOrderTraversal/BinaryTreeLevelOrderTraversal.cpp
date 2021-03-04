#include "Tools/BinaryTreeNodeTools.h"

#include <algorithm>
#include <catch2/catch.hpp>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits.h>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace Catch;
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        pre(root, 0, ans);
        return ans;
    }

    void pre(TreeNode* root, int depth, vector<vector<int>>& ans)
    {
        if (!root)
            return;
        if (depth >= static_cast<int>(ans.size()))
            ans.push_back(vector<int> {});
        ans[depth].push_back(root->val);
        pre(root->left, depth + 1, ans);
        pre(root->right, depth + 1, ans);
    }
};
TEST_CASE("Check Solution levelOrder method work successfully")
{
    Solution solution;

    TreeNode TreeNode9(9);
    TreeNode TreeNode15(15);
    TreeNode TreeNode7(7);

    TreeNode TreeNode20(20, &TreeNode15, &TreeNode7);
    TreeNode TreeNode3(3, &TreeNode9, &TreeNode20);

    REQUIRE(solution.levelOrder(&TreeNode3) == vector<vector<int>> { { 3 }, { 9, 20 }, { 15, 7 } });
}