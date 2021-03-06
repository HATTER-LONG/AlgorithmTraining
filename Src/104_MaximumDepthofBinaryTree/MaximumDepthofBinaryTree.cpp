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
    string imputParm;
    int result;
    tie(imputParm, result) = GENERATE(table<string, int>({
        make_tuple("3(9,20(15,7))", 3),
    }));
    auto* treeNode = createTreeNode(imputParm);

    REQUIRE(solution.maxDepth(treeNode) == 3);
}