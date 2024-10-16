#include "Tools/Tools.hpp"

/*
 * 给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary
 * 中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。
 *
 * 如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。
 *
 *
 * 示例 1：
 *
 * 输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
 * 输出："apple"
 * 示例 2：
 *
 * 输入：s = "abpcplea", dictionary = ["a","b","c"]
 * 输出："a"
 *
 */

string findLongestWord(string s, vector<string>& dictionary) {
    string res;
    for(auto& x : dictionary) {
        size_t cnt = 0;
        for(size_t i = 0; i < s.length(); i++) {
            if(s[i] == x[cnt]) {
                cnt++;
            }
        }
        if(cnt == x.length()) {
            if(x.length() == res.length()) {
                res = res < x ? res : x;
            } else {
                res = res.length() < x.length() ? x : res;
            }
        }
    }
    return res;
}

TEST_CASE("test find longest word func") {
    string input;
    vector<string> dic;

    string result;

    tie(input, dic, result) = GENERATE(table<string, vector<string>, string>(
        {make_tuple("abpcplea", vector<string>{"ale", "apple", "monkey", "plea"}, "apple")}));

    CAPTURE(input, dic, result);
    REQUIRE(findLongestWord(input, dic) == result);
}
