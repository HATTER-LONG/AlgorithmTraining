#pragma once

#include <string>
#include <vector>
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
            : val(0)
            , left(nullptr)
            , right(nullptr)
    {
    }
    TreeNode(int x)
            : val(x)
            , left(nullptr)
            , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
            : val(x)
            , left(left)
            , right(right)
    {
    }
};

// TODO ：待完成
inline std::string transBinTreeNode2Str(const TreeNode& /*TreeNodeParm*/)
{
    return "";
}
