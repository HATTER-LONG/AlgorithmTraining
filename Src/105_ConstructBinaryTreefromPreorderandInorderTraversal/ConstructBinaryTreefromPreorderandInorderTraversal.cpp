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
 *  对于任意一颗树而言，前序遍历的形式总是
    [ 根节点, [左子树的前序遍历结果], [右子树的前序遍历结果] ]
    即根节点总是前序遍历中的第一个节点。而中序遍历的形式总是
    [ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]
 *
 */
class Solution
{
public:
    unordered_map<int, int> keymap;
    TreeNode* buildTreeImp(const vector<int>& preorder, const vector<int>& inorder, int preorder_left,
        int preorder_right, int inorder_left, int inorder_right)
    {
        if (preorder_left > preorder_right)
        {
            return nullptr;
        }

        //前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;
        //在中序遍历中定位根节点
        int inorder_root = keymap[preorder[preorder_root]];

        // 先把根节点建立出来
        TreeNode* root = new TreeNode(preorder[preorder_root]);

        //得到左子树中的节点数目
        int size_left_subtree = inorder_root - inorder_left;

        //递归构造左子树中的节点，并链接根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到
        ///根节点定位-1」的元素
        root->left = buildTreeImp(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree,
            inorder_left, inorder_root - 1);

        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到
        // 右边界」的元素
        root->right = buildTreeImp(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right,
            inorder_root + 1, inorder_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int preLen = preorder.size();
        int inLen = inorder.size();

        if (preLen != inLen)
            return nullptr;
        for (int i = 0; i < inLen; i++)
        {
            keymap.insert(pair<int, int> { inorder[i], i });
        }
        return buildTreeImp(preorder, inorder, 0, preLen - 1, 0, inLen - 1);
    }
};
TEST_CASE("Check Solution maxDepth method work successfully")
{
    Solution solution;
    vector<int> imputParm1, imputParm2;
    string result;
    tie(imputParm1, imputParm2, result) = GENERATE(table<vector<int>, vector<int>, string>({
        make_tuple(vector<int> { 3, 9, 20, 15, 7 }, vector<int> { 9, 3, 15, 20, 7 }, "3(9,20(15,7))"),
    }));
    auto* resultTreeNode = createTreeNode(result);
    auto* ans = solution.buildTree(imputParm1, imputParm2);
    if (ans == nullptr || resultTreeNode == nullptr)
        REQUIRE(ans == resultTreeNode);
    else
        REQUIRE_THAT(*ans, IsEqualTreeNode(*resultTreeNode));
}