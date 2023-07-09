#include <catch2/catch_all.hpp>

using namespace std;
using namespace Catch;

class Solution
{
public:
    string replaceSpace(string s)
    {
        int count = 0;
        for (auto c : s) {
            if (c == ' ')
                count++;
        }

        int oldSize = s.size();
        // 扩充字符串长度，每个空格替换成"%20"之后，长度增加2
        int newSize = oldSize + count * 2;
        s.resize(newSize);

        // 从后往前替换空格为"%20"，可以避免从前往后替换，需要多次移动元素
        for (int i = newSize - 1, j = oldSize - 1; j < i; i--, j--) {
            if (s[j] != ' ') {
                s[i] = s[j];
            } else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};


TEST_CASE("Check Solution replaceSpace method work successfully ")
{
    Solution solution;

    string input;
    string result;
    tie(input, result) = GENERATE(table<string, string>({
        make_tuple("We are happy.", "We%20are%20happy."),
    }));
    CAPTURE(input, result);
    REQUIRE(solution.replaceSpace(input) == (result));
}
