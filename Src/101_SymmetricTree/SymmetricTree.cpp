#include "Tools/BinaryTreeNodeTools.h"

#include <algorithm>
#include <catch2/catch.hpp>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits.h>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace Catch;
using namespace std;

//迭代
class Solution
{
public:
    bool check(TreeNode* u, TreeNode* v)
    {
        queue<TreeNode*> q;
        q.push(u);
        q.push(v);
        while (!q.empty())
        {
            u = q.front();
            q.pop();
            v = q.front();
            q.pop();
            if (!u && !v)
                continue;
            if ((!u || !v) || (u->val != v->val))
                return false;

            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) { return check(root, root); }
};

//递归
class Solution_BackTrace
{
public:
    bool check(TreeNode* p, TreeNode* q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) { return check(root, root); }
};

TEST_CASE("Check Solution isSymmetric method work successfully")
{
    Solution solution;

    string imputParm;
    bool result;
    tie(imputParm, result) = GENERATE(table<string, bool>({
        make_tuple("1(2(3,4),2(4,3))", true),
        make_tuple("1(2(2,),2(2,))", false),
    }));
    auto* treeNode = createTreeNode(imputParm);
    REQUIRE(solution.isSymmetric(treeNode) == result);
}