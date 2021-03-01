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

// 动态规划

// 将其分解为：遍历根节点，左子树为 G(i-1) 右子树为 G(n-i)，进行笛卡尔乘积算出总和 G(i-1) * G(n-i)

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};

TEST_CASE("Check Solution numTrees method work successfully")
{
    Solution solution;
    int inputParm = 0, result = 0;


    tie(inputParm, result) = GENERATE(table<int, int>({
        make_tuple(3, 5),
    }));

    CAPTURE(inputParm, result);
    REQUIRE(solution.numTrees(inputParm) == (result));
}