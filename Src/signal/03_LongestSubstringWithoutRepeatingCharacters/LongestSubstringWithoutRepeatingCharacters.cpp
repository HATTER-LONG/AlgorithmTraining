#include <catch2/catch.hpp>
#include <string>
#include <tuple>

using namespace std;
using namespace Catch;

// 滑动窗口
// 时间复杂度: O(len(s))
// 空间复杂度: O(len(charset))
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int freq[256] = { 0 };
        int l = 0, r = -1;   //滑动窗口为s[l...r]
        int res = 0;
        // 整个循环从 l == 0; r == -1 这个空窗口开始
        // 到l == s.size(); r == s.size()-1 这个空窗口截止
        // 在每次循环里逐渐改变窗口, 维护freq, 并记录当前窗口中是否找到了一个新的最优值
        while (l < static_cast<int>(s.size()))
        {
            if (r + 1 < static_cast<int>(s.size()) && freq[static_cast<int>(s[r + 1])] == 0)
            {
                r++;
                freq[static_cast<int>(s[r])]++;
            }
            else
            {   // r已经到头 || freq[s[r+1]] == 1
                freq[static_cast<int>(s[l])]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};

TEST_CASE("Check Solution lengthOfLongestSubstring method work successfully ")
{
    Solution solution;

    string inputString;
    long result = -1;
    // clang-format off
    tie(inputString, result) = 
        GENERATE(table<string, long>
            (
                {
                    make_tuple("abcdxdefghj", 7),
                    make_tuple("abcabcbb", 3),
                    make_tuple("bbbbb", 1),
                    make_tuple("pwwkew", 3),
                    make_tuple("vqblqcb", 4),
                    make_tuple("jbpnbwwd", 4),
                    make_tuple("ggububgvfk", 6),
                    make_tuple("iuonzyzlclfudgrr", 7),
                }
                
            )
        );
    // clang-format on;

    REQUIRE(solution.lengthOfLongestSubstring(inputString) == result);
}