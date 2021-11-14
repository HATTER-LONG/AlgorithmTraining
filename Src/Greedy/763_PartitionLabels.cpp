#include <catch2/catch.hpp>
#include <glog/logging.h>
#include <unordered_map>
using namespace std;

/*
 * 字符串 S 由小写字母组成。
 * 我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
 * 返回一个表示每个字符串片段的长度的列表。
 *
 * 示例：
 *
 * 输入：S = "ababcbacadefegdehijhklij"
 * 输出：[9,7,8]
 * 解释：
 * 划分结果为 "ababcbaca", "defegde", "hijhklij"。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 *
 * 提示：
 *
 * S的长度在[1, 500]之间。
 * S只包含小写字母 'a' 到 'z' 。
 */

vector<int> partitionLabels(string s)
{
    vector<int> result;
    unordered_map<char, int> map;
    int start = 0, end = 0;
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        map[s[i]] = i;
    }
    for (int i = 0; i < length; i++)
    {
        end = max(end, map[s[i]]);
        if (i == end)
        {
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return result;
}

TEST_CASE("test partiton labels func")
{
    string ins;
    vector<int> result;
    tie(ins, result) = GENERATE(table<string, vector<int>>(
        { make_tuple("ababcbacadefegdehijhklij", vector<int> { 9, 7, 8 }) }));

    REQUIRE_THAT(partitionLabels(ins), Catch::Equals(result));
}
