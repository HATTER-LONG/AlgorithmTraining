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

    string imputParm;
    vector<vector<int>> result;
    tie(imputParm, result) = GENERATE(table<string, vector<vector<int>>>({
        make_tuple("3(9,20(15,7))", vector<vector<int>> { { 3 }, { 9, 20 }, { 15, 7 } }),
    }));
    auto* treeNode = createTreeNode(imputParm);

    REQUIRE(solution.levelOrder(treeNode) == result);
}