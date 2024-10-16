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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while(root != nullptr || !stk.empty()) {
            while(root != nullptr) {
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
class Solution_Deep {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if(!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};

TEST_CASE("Check Solution inorderTraversal method work successfully") {
    Solution solution;
    string imputParm;
    vector<int> result;
    tie(imputParm, result) = GENERATE(table<string, vector<int>>({
        make_tuple("1(,2(3,))", vector<int>{1, 3, 2}),
    }));
    auto* treenode = createTreeNode(imputParm);

    REQUIRE_THAT(solution.inorderTraversal(treenode), Equals(result));
}