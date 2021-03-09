#include "Tools/BinaryTreeNodeTools.h"

#include <algorithm>
#include <catch2/catch.hpp>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits.h>
#include <queue>
#include <spdlog/spdlog.h>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace Catch;
using namespace std;

//递归

/**
    对于任意一个节点, 如果最大和路径包含该节点, 那么只可能是两种情况:
    1. 其左右子树中所构成的和路径值较大的那个，加上该节点的值后向父节点回溯构成最大路径
    2. 左右子树都在最大路径中, 加上该节点的值构成了最终的最大路径
**/

class Solution
{
public:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node)
    {
        if (node == nullptr)
            return 0;

        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        int priceNewpath = node->val + leftGain + rightGain;

        maxSum = max(maxSum, priceNewpath);

        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root)
    {
        maxGain(root);
        return maxSum;
    }
};
TEST_CASE("Check Solution maxPathSum method work successfully")
{
    Solution solution;

    string imputParm;
    int result;
    tie(imputParm, result) = GENERATE(table<string, int>({
        make_tuple("1(2,3)", 6),
        make_tuple("10(9,20(15,7))", 54),
    }));
    auto* inputTreeNode = createTreeNode(imputParm);

    REQUIRE(solution.maxPathSum(inputTreeNode) == (result));
}