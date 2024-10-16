#pragma once
#include <cstddef>
#include <functional>
#include <glog/logging.h>
#include <stack>
#include <string>
#include <vector>

struct TreeNode {
    int m_val;
    TreeNode* m_left;
    TreeNode* m_right;
    TreeNode() : m_val(0), m_left(nullptr), m_right(nullptr) {}
    TreeNode(int x) : m_val(x), m_left(nullptr), m_right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : m_val(x), m_left(left), m_right(right) {}
};

inline std::string transBinTreeNode2Str(const TreeNode& treeNodeParm) {
    std::function<std::string(const TreeNode* const treeNode)> dfs =
        [&](const TreeNode* const treeNode) -> std::string {
        if(treeNode == nullptr)
            return "";
        std::string left = dfs(treeNode->m_left);
        std::string right = dfs(treeNode->m_right);
        if(left.empty() && right.empty()) {
            return std::to_string(treeNode->m_val);
        }
        std::string res;
        res += std::to_string(treeNode->m_val);
        res += "(" + left + ",";
        if(!right.empty())
            res += right;
        res += ")";
        return res;
    };
    return dfs(&treeNodeParm);
}

// TODO: 智能指针管理 New 出的内存
inline TreeNode* createTreeNode(std::string str) {
    enum UPDATEMOD { LEFT = 1, RIGHT };
    auto getValue = [](const std::string& str, size_t& j) -> int {
        int tmp = j - 1;
        char tmpCh = 0;
        int num = 0;
        while((tmpCh = str[tmp++])) {
            if(tmpCh == ')' || tmpCh == '(' || tmpCh == ',') {
                j = tmp - 1;
                break;
            }
            if(tmpCh < '0' || tmpCh > '9') {
                LOG(WARNING) << "Input Error char " << tmpCh << ", only number";
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
    while((ch = str[pos++]) != '\0') {
        switch(ch) {
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
            if(num == -1)
                return nullptr;
            node->m_val = num;
            if(root == nullptr) {
                root = node;
            } else {
                switch(direction) {
                case LEFT:
                    nodeStack.top()->m_left = node;
                    break;
                case RIGHT:
                    nodeStack.top()->m_right = node;
                    break;
                }
            }
            break;
        }
    }
    return root;
}

inline bool compareTreeNode( // NOLINT
    const TreeNode* const t1,
    const TreeNode* const t2) {
    if(t1 && t2 && (t1->m_val == t2->m_val)) {
        if(compareTreeNode(t1->m_left, t2->m_left) && compareTreeNode(t1->m_right, t2->m_right))
            return true;
        return false;
    }
    if(t1 == nullptr && t2 == nullptr)
        return true;
    return false;
}

#undef CATCH_CONFIG_FALLBACK_STRINGIFIER
#define CATCH_CONFIG_FALLBACK_STRINGIFIER(value) transBinTreeNode2Str(value)

#include <catch2/catch.hpp>

class IsEqualTreeNode : public Catch::MatcherBase<TreeNode> {
public:
    IsEqualTreeNode(TreeNode& treeNodeParam) : m_treeNode(treeNodeParam) {}
    bool match(TreeNode const& arg) const override {
        const TreeNode* leftPtr = &arg;
        const TreeNode* rightPtr = &m_treeNode;

        return compareTreeNode(leftPtr, rightPtr);
    }

    virtual std::string describe() const override {
        std::string leftValue = transBinTreeNode2Str(m_treeNode);
        leftValue = "\nThe TreeNode mismatching\n" + leftValue;
        return leftValue;
    }

private:
    const TreeNode& m_treeNode;
};
