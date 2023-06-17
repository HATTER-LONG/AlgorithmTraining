#include "Tools/BinaryTreeNodeTools.h"

#include <catch2/catch.hpp>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits.h>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace Catch;
using namespace std;

//中序遍历
// 中序遍历必然有序，如无序则不符合
class Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        stack<TreeNode*> stack;
        long long inorder = LONG_MIN;

        while (!stack.empty() || root != nullptr)
        {
            while (root != nullptr)
            {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
            if (root->val <= inorder)
            {
                return false;
            }
            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};

//递归
// 注意其上界 下界如何保存
class Solution_Depth
{
public:
    bool helper(TreeNode* root, long long lower, long long upper)
    {
        if (root == nullptr)
            return true;

        if (root->val <= lower || root->val >= upper)
        {
            return false;
        }

        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }
    bool isValidBST(TreeNode* root) { return helper(root, LONG_MIN, LONG_MAX); }
};

TEST_CASE("Check Solution isValidBST method work successfully")
{
    Solution solution;

    string imputParm;
    bool result;
    tie(imputParm, result) = GENERATE(table<string, bool>({
        make_tuple("2(1,3)", true),
        make_tuple("5(1,4(3,6))", false),
    }));
    auto* treeNode = createTreeNode(imputParm);
    REQUIRE(solution.isValidBST(treeNode) == result);
}