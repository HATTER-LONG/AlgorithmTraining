#include "Tools/Tools.hpp"

/*
 * 题目描述
 *   判断两个字符串包含的字符是否完全相同。
 *
 * 输入输出样例
 *   输入两个字符串，输出一个布尔值，表示两个字符串是否满足条件。
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 */

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) {
        return false;
    }

    vector<int> counts(26, 0);
    int sSize = s.length();
    for(int i = 0; i < sSize; i++) {
        ++counts[s[i] - 'a'];
        --counts[t[i] - 'a'];
    }

    for(int i : counts) {
        if(i != 0) {
            return false;
        }
    }
    return true;
}

TEST_CASE("test isAnagram func") {
    string s, t;
    bool res;

    tie(s, t, res) =
        GENERATE(table<string, string, bool>({make_tuple("anagram", "nagaram", true)}));

    CAPTURE(s, t, res);
    REQUIRE(isAnagram(s, t) == res);
}
