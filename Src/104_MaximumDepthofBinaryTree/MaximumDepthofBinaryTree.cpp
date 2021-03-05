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
    int maxDepth(TreeNode* root)
    {
        if (!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
TEST_CASE("Check Solution maxDepth method work successfully")
{
    Solution solution;

    TreeNode TreeNode9(9);
    TreeNode TreeNode15(15);
    TreeNode TreeNode7(7);

    TreeNode TreeNode20(20, &TreeNode15, &TreeNode7);
    TreeNode TreeNode3(3, &TreeNode9, &TreeNode20);

    REQUIRE(solution.maxDepth(&TreeNode3) == 3);
}