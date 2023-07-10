#include <catch2/catch_all.hpp>

using namespace std;
using namespace Catch;

class Solution
{
public:
    string reverseWords(string s)
    {
        removeExtraSpacesII(s);   // 去除多余空格
        reverse(s, 0, s.length() - 1);
        int start = 0;   // 去除空格后保证从零为起始
        // 注意这里 小于等于是因为最后一个单词后边没有空格了，需要按长度 == s.size() 来确认
        for (size_t i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {   // 快指针到达空格，单词结束
                reverse(s, start, i - 1);         // 反转单词
                start = i + 1;                    // 更新慢指针
            }
        }
        return s;
    }

    // 版本1
    void removeExtraSpaces(string& s)
    {
        size_t slowIndex = 0, fastIndex = 0;   // 快慢指针
        // 去掉字符串开头的空白字符
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }

        for (; fastIndex < s.size(); fastIndex++) {
            // 去掉字符串中间部分的冗余空白字符
            if (fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] && s[fastIndex] == ' ') {
                continue;
            }
            s[slowIndex++] = s[fastIndex];
        }

        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') {
            // 去掉末尾的空格
            s.resize(slowIndex - 1);
        } else {
            s.reserve(slowIndex);
        }
    }

    // 版本2
    // 去除所有空格并在相邻单词之间添加空格, 快慢指针。
    void removeExtraSpacesII(string& s)
    {
        int slow = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {   // 遇到非空格就处理，即删除所有空格。
                if (slow != 0)
                    s[slow++] = ' ';                    // 手动添加上空格
                while (i < s.size() && s[i] != ' ') {   // 补上单词，遇到空格说明结束
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);   // slow 就是最终字符串长度
    }

    // 反转指定区间的字符串
    void reverse(string& s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};


TEST_CASE("Check Solution reverseWords method work successfully ")
{
    Solution solution;

    string input;
    string result;
    tie(input, result) = GENERATE(table<string, string>({
        make_tuple("the sky is blue", "blue is sky the"),
        make_tuple("  hello world  ", "world hello"),
        make_tuple("a good   example", "example good a"),
    }));

    REQUIRE_THAT(solution.reverseWords(input), Matchers::Equals(result));
}
