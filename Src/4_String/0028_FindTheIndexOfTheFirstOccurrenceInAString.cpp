#include <catch2/catch_all.hpp>

using namespace std;
using namespace Catch;

class Solution {
public:
    void getNext(vector<int>& next, const string& s) {
        // j 指向前缀末尾，i 指向后缀末尾
        int j = -1;
        next[0] = j;

        // 因为 next[0] 已经初始化为 -1，所以从 1 开始比较
        for(size_t i = 1; i < s.size(); i++) {
            while(j >= 0 && s[i] != s[j + 1]) // 前后缀不相同了
                j = next[j];                  // 向前回溯
            if(s[i] == s[j + 1])              // 找到相同的前后缀
                j++;
            next[i] = j; // 将 j（前缀的长度） 赋给 next[i]
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.length() == 0)
            return 0;
        vector<int> next(needle.length(), 0);
        getNext(next, needle);
        int j = -1; // 因为 next 数组里记录的起始位置为 -1
        for(size_t i = 0; i < haystack.length(); i++) {
            while(j >= 0 && haystack[i] != needle[j + 1]) // 不匹配
                j = next[j];                              // j 寻找之前匹配的位置
            if(haystack[i] == needle[j + 1])              // 匹配，j 和 i 同时向后移动
                j++;
            if(j == static_cast<int>(needle.length() - 1)) // 文本串 s 匹配完成
                return (i - needle.length() + 1);
        }
        return -1;
    }
};

TEST_CASE("Check Solution strStr method work successfully ") {
    Solution solution;

    string input, needle;
    int result;
    tie(input, needle, result) = GENERATE(table<string, string, int>({
        make_tuple("sadbutsad", "sad", 0),
        make_tuple("leetcode", "leeto", -1),
    }));
    REQUIRE(solution.strStr(input, needle) == result);
}
