#include <algorithm>
#include <catch2/catch.hpp>
#include <climits>
#include <cstddef>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace Catch;
using namespace std;

// DP 与 记忆递归

/**
 *
 * 遍历字符串，定位每一个可以与目标集合中词组匹配的点，找到其中一种可以再 n = size 的地方完美匹配所有词组
 *
 */

class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        auto n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (size_t i = 0; i < s.size(); i++)
        {
            // 只需匹配基于前一个有效的分割点
            if (dp[i])
            {
                for (auto& word : wordDict)
                {
                    if (i + word.size() <= n && word == s.substr(i, word.size()))
                    {
                        dp[i + word.size()] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};

class Solution_DFS
{
public:
    bool dfs(unordered_map<string, bool>& myMap, string s, vector<string>& wordDict)
    {
        if (myMap.find(s) != myMap.end())
            return myMap[s];
        if (s.empty())
            return true;
        bool res = false;
        for (auto& word : wordDict)
        {
            if (s.substr(0, word.size()) == word)
            {
                bool flag = dfs(myMap, s.substr(word.size()), wordDict);
                res = res || flag;
            }
        }
        myMap[s] = res;
        return myMap[s];
    }
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_map<string, bool> myMap;
        return dfs(myMap, s, wordDict);
    }
};


TEST_CASE("Check Solution wordBreak method work successfully")
{
    Solution solution;

    string inputParm;
    vector<string> inputParm2;
    bool resultParm = 0;

    tie(inputParm, inputParm2, resultParm) = GENERATE(table<string, vector<string>, bool>({
        make_tuple("leetcode", vector<string> { "leet", "code" }, true),
        make_tuple("applepenapple", vector<string> { "apple", "pen" }, true),
        make_tuple("catsandog", vector<string> { "cats", "dog", "sand", "and", "cat" }, false),
    }));

    CAPTURE(inputParm, inputParm2, resultParm);

    REQUIRE(solution.wordBreak(inputParm, inputParm2) == (resultParm));
}