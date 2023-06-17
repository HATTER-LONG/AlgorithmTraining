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

//右向遍历，反向思维

class Solution
{
public:
    TreeNode* last = nullptr;
    void flatten(TreeNode* root)
    {
        if (root == nullptr)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = last;
        root->left = nullptr;
        last = root;
    }
};

TEST_CASE("Check Solution flatten method work successfully")
{
    Solution solution;

    string imputParm;
    string result;
    tie(imputParm, result) = GENERATE(table<string, string>({
        make_tuple("1(2(3,4),5(,6))", "1(,2(,3(,4(,5(,6)))))"),
    }));
    auto* inputTreeNode = createTreeNode(imputParm);
    auto* resultTreeNode = createTreeNode(result);

    solution.flatten(inputTreeNode);

    if (inputTreeNode == nullptr || resultTreeNode == nullptr)
        REQUIRE(inputTreeNode == resultTreeNode);
    else
        REQUIRE_THAT(*inputTreeNode, IsEqualTreeNode(*resultTreeNode));
}