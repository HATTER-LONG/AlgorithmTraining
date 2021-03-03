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
    SECTION("TRUE Branch")
    {
        TreeNode TreeNode3(3);
        TreeNode TreeNode4(4);
        TreeNode inputParm2(2, &TreeNode3, &TreeNode4);

        TreeNode TreeNoder3(3);
        TreeNode TreeNoder4(4);
        TreeNode inputParmar2(2, &TreeNoder4, &TreeNoder3);

        TreeNode inputParm(1, &inputParm2, &inputParmar2);
        CAPTURE(inputParm);
        REQUIRE(solution.isSymmetric(&inputParm));
    }
    SECTION("FALSE Branch")
    {
        TreeNode TreeNode2(2);
        TreeNode inputParm2(2, &TreeNode2, nullptr);

        TreeNode TreeNoder3(2);
        TreeNode inputParmar2(2, &TreeNoder3, nullptr);
        TreeNode inputParm(1, &inputParm2, &inputParmar2);
        REQUIRE_FALSE(solution.isSymmetric(&inputParm));
    }
}