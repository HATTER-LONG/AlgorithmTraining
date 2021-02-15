#include <array>
#include <catch2/catch.hpp>
#include <cstddef>
#include <string>
#include <tuple>
#include <unordered_map>

using namespace Catch;
using namespace std;

// 哈希或质数相乘

class Solution
{
public:
    //哈希
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = hash<int> {}](const array<int, 26>& arr) -> size_t {
            return accumulate(
                arr.begin(), arr.end(), 0u, [&](size_t acc, int num) { return (acc << 1) ^ fn(num); });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str : strs)
        {
            array<int, 26> counts {};
            int length = str.length();
            for (int i = 0; i < length; ++i)
            {
                counts[str[i] - 'a']++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
    //使用质数相乘避免重复
    vector<vector<string>> groupAnagrams_mine(vector<string>& strs)
    {
        vector<vector<string>> ans;
        unordered_map<int, size_t> maps;
        for (auto& str : strs)
        {
            size_t sum = 1;
            for (const auto& c : str)
            {
                sum *= m_keyMap[c];
                sum %= m_Mod;
            }

            if (maps.count(sum))
            {
                size_t pos = maps[sum];
                ans[pos].push_back(str);
            }
            else
            {
                maps[sum] = ans.size();
                ans.emplace_back(vector<string> { str });
            }
        }
        return ans;
    }

private:
    size_t m_Mod = 1e9 + 7;
    unordered_map<char, int> m_keyMap = { { 'a', 2 }, { 'b', 3 }, { 'c', 5 }, { 'd', 7 }, { 'e', 11 },
        { 'f', 13 }, { 'g', 17 }, { 'h', 19 }, { 'i', 23 }, { 'j', 29 }, { 'k', 31 }, { 'l', 37 },
        { 'm', 41 }, { 'n', 43 }, { 'o', 47 }, { 'p', 53 }, { 'q', 59 }, { 'r', 61 }, { 's', 67 },
        { 't', 71 }, { 'u', 73 }, { 'v', 79 }, { 'w', 83 }, { 'x', 89 }, { 'y', 97 }, { 'z', 101 } };
};


TEST_CASE("Check Solution groupAnagrams method work successfully")
{
    Solution solution;

    vector<string> inputParm;

    vector<vector<string>> resultParm;

    tie(inputParm, resultParm) = GENERATE(table<vector<string>, vector<vector<string>>>({
        make_tuple(
            vector<string> {
                "eat",
                "tea",
                "tan",
                "ate",
                "nat",
                "bat",
            },
            vector<vector<string>> { { "eat", "tea", "ate" }, { "tan", "nat" }, { "bat" } }),
        make_tuple(
            vector<string> {
                "duh",
                "ill",
            },
            vector<vector<string>> { { "duh" }, { "ill" } }),
        make_tuple(
            vector<string> {
                "ac",
                "c",
            },
            vector<vector<string>> { { "c" }, { "ac" } }),

    }));

    CAPTURE(inputParm, resultParm);
    REQUIRE_THAT(solution.groupAnagrams(inputParm), UnorderedEquals(resultParm));
}