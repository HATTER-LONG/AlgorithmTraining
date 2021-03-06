#pragma once

#include <cstddef>
#include <functional>
#include <spdlog/spdlog.h>
#include <stack>
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

inline std::string transBinTreeNode2Str(const TreeNode& TreeNodeParm)
{
    std::function<std::string(const TreeNode* const TreeNode)> dfs =
        [&](const TreeNode* const TreeNode) -> std::string {
        if (TreeNode == nullptr)
            return "";
        std::string left = dfs(TreeNode->left);
        std::string right = dfs(TreeNode->right);
        if (left.empty() && right.empty())
        {
            return std::to_string(TreeNode->val);
        }
        std::string res;
        res += std::to_string(TreeNode->val);
        res += "(" + left + ",";
        if (!right.empty())
            res += right;
        res += ")";
        return res;
    };
    return dfs(&TreeNodeParm);
}

// TODO: 智能指针管理 New 出的内存
inline TreeNode* createTreeNode(std::string str)
{
    enum UPDATEMOD
    {
        LEFT = 1,
        RIGHT
    };
    auto getValue = [](const std::string& str, size_t& j) -> int {
        int tmp = j - 1;
        char tmpCh = 0;
        int num = 0;
        while ((tmpCh = str[tmp++]))
        {
            if (tmpCh == ')' || tmpCh == '(' || tmpCh == ',')
            {
                j = tmp - 1;
                break;
            }
            if (tmpCh < '0' || tmpCh > '9')
            {
                spdlog::warn("Input Error char[{}], only number", tmpCh);
                return -1;
            }
            num = num * 10 + tmpCh - '0';
        }
        return num;
    };

    char ch = 0;
    std::stack<TreeNode*> nodeStack;
    TreeNode* root = nullptr;
    TreeNode* node = nullptr;
    size_t pos = 0;
    UPDATEMOD direction;
    while ((ch = str[pos++]) != '\0')
    {
        switch (ch)
        {
            case '(':
                nodeStack.push(node);
                direction = LEFT;
                break;
            case ',':
                direction = RIGHT;
                break;
            case ')':
                nodeStack.pop();
                break;
            default:
                node = new TreeNode();

                int num = getValue(str, pos);
                if (num == -1)
                    return nullptr;
                node->val = num;
                if (root == nullptr)
                {
                    root = node;
                }
                else
                {
                    switch (direction)
                    {
                        case LEFT:
                            nodeStack.top()->left = node;
                            break;
                        case RIGHT:
                            nodeStack.top()->right = node;
                            break;
                    }
                }
                break;
        }
    }
    return root;
}

inline bool compareTreeNode(const TreeNode* const T1, const TreeNode* const T2)
{
    if (T1 && T2 && (T1->val == T2->val))
    {
        if (compareTreeNode(T1->left, T2->left) && compareTreeNode(T1->right, T2->right))
            return true;
        return false;
    }
    if (T1 == nullptr && T2 == nullptr)
        return true;
    return false;
}


#undef CATCH_CONFIG_FALLBACK_STRINGIFIER
#define CATCH_CONFIG_FALLBACK_STRINGIFIER(value) transBinTreeNode2Str(value)

#include <catch2/catch.hpp>

class IsEqualTreeNode : public Catch::MatcherBase<TreeNode>
{
public:
    IsEqualTreeNode(TreeNode& TreeNodeParam)
            : m_treeNode(TreeNodeParam)
    {
    }
    bool match(TreeNode const& Arg) const override
    {
        const TreeNode* LeftPtr = &Arg;
        const TreeNode* RightPtr = &m_treeNode;

        return compareTreeNode(LeftPtr, RightPtr);
    }

    virtual std::string describe() const override
    {
        std::string LeftValue = transBinTreeNode2Str(m_treeNode);
        LeftValue = "\nThe TreeNode mismatching\n" + LeftValue;
        return LeftValue;
    }

private:
    const TreeNode& m_treeNode;
};
