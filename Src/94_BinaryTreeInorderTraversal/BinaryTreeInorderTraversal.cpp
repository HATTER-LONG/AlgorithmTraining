#include "Tools/BinaryTreeNodeTools.h"

#include <catch2/catch.hpp>
#include <cstddef>
#include <cstdint>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace Catch;
using namespace std;


// 迭代，递归隐式的维护了栈，迭代则显示实现
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty())
        {
            while (root != nullptr)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};

// 递归
class Solution_Deep
{
public:
    void inorder(TreeNode* root, vector<int>& res)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};

TEST_CASE("Check Solution inorderTraversal method work successfully")
{
    Solution solution;
    TreeNode tmp1(3);
    TreeNode tmp2(2, &tmp1, nullptr);
    TreeNode inputParm(1, nullptr, &(tmp2));

    vector<int> result { 1, 3, 2 };

    CAPTURE(inputParm, result);
    REQUIRE_THAT(solution.inorderTraversal(&inputParm), Equals(result));
}