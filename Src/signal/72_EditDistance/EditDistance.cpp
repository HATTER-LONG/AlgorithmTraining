#include <catch2/catch.hpp>
#include <cstddef>
#include <string>
#include <tuple>

using namespace Catch;
using namespace std;

// 动态规划：

/*
 * 抽象动作为：
 * 在单词 A 中插入一个字符；
 * 在单词 B 中插入一个字符；
 * 修改单词 A 的一个字符
 *
 * 执行动作：
 *   1. 执行插入操作，那么比较 word1[0 ... i] 和 word2[0 ... j-1]的结果
 *   2. 执行删除操作，那么比较 word1[0 ... i-1] 和 word2[0 ... j]的结果
 *   3. 执行替换操作，那么比较 word1[0 ... i-1] 和 word2[0 ... j-1]的结果
 *
 * 状态转移方程：
 *   1. 如果 word1[i] == word2[j]，那么 op[i][j] = op[i-1][j-1]
 *   2. 否则，op[i][j] = 1 + min(op[i][j-1], op[i-1][j], op[i-1][j-1])
 */

/*
 *  E   5   4   4   3   < 分解为将 HORSE 转到 R/RO/ROS 分别需要的步数
 *  S   4   3   3   2   < 分解为将 HORS 转到 R/RO/ROS 分别需要的步数
 *  R   3   2   2   2   < 分解为将 HOR 转到 R/RO/ROS 分别需要的步数
 *  O   2   2   1   2   < 分解为将 HO 转到 R/RO/ROS 分别需要的步数
 *  H   1   1   2   3   < 分解为将 H 转到 R/RO/ROS 分别需要的步数
 *  #   0   1   2   3
 *      #   R   O   S
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // 有空串的情况
        if(n * m == 0)
            return n + m;

        // DP 数组
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        // 边界初始化
        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for(int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        // 计算所有 DP 值
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                int left = dp[i - 1][j] + 1;
                int down = dp[i][j - 1] + 1;
                int left_down = dp[i - 1][j - 1];
                if(word1[i - 1] != word2[j - 1])
                    left_down += 1;
                dp[i][j] = min(left, min(down, left_down));
            }
        }
        return dp[n][m];
    }
};

TEST_CASE("Check Solution minDistance method work successfully") {
    Solution solution;

    string inputParm1, inputParm2;

    int resultParm;

    tie(inputParm1, inputParm2, resultParm) = GENERATE(table<string, string, int>({
        make_tuple("horse", "ros", 3),
        make_tuple("intention", "execution", 5),
    }));

    CAPTURE(inputParm1, inputParm2, resultParm);
    REQUIRE(solution.minDistance(inputParm1, inputParm2) == resultParm);
}