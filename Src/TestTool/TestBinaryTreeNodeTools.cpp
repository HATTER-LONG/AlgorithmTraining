#include "Tools/BinaryTreeNodeTools.h"

#include <catch2/catch.hpp>

TEST_CASE("Test binary tree node tool") {
    TreeNode TreeNode0(0);
    TreeNode TreeNode9(9, nullptr, &TreeNode0);
    TreeNode TreeNode15(15);
    TreeNode TreeNode7(7);

    TreeNode TreeNode20(20, &TreeNode15, &TreeNode7);
    TreeNode TreeNode3(3, &TreeNode9, &TreeNode20);
    auto originTreeNodeStr = transBinTreeNode2Str(TreeNode3);

    auto* treeNodeLeft = createTreeNode("3(9(,0),20(15,7))");
    auto customNodeStr = transBinTreeNode2Str(*treeNodeLeft);
    REQUIRE(originTreeNodeStr == customNodeStr);
    auto* treeNoderight = createTreeNode("3(9(,0),20(15,7))");
    REQUIRE_THAT(*treeNodeLeft, IsEqualTreeNode(*treeNoderight));
}