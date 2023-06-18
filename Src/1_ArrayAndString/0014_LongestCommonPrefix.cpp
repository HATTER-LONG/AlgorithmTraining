#include <catch2/catch_all.hpp>
#include <glog/logging.h>
using namespace Catch;
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 0)
            return "";
        if (strs.size() == 1)
            return strs[0];

        // 从第一个字符串开始，逐个字符比较
        for (size_t i = 0; i < strs[0].size(); i++) {
            // 从第二个字符串开始，逐个字符比较
            for (size_t j = 1; j < strs.size(); j++) {
                if (strs[j].length() == i || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
            // 如果是最后一个字符串比对完成，说明所有的字符串都相同
            if (i == strs[0].size() - 1) {
                return strs[0];
            }
        }
        return "";
    }
};

TEST_CASE("Check Solution longestCommonPrefix method work successfully")
{
    Solution solution;

    vector<string> param;
    string result = "";
    tie(param, result) = GENERATE(table<vector<string>, string>({
        make_tuple(vector<string> { "flower", "flow", "flight" }, "fl"),
        make_tuple(vector<string> { "flower", "fl", "flow", "flight" }, "fl"),
        make_tuple(vector<string> { "flower", "flower", "flower" }, "flower"),
        make_tuple(vector<string> { "dog", "racecar", "car" }, ""),
        make_tuple(vector<string> { "ab", "a" }, "a"),
    }));

    REQUIRE(solution.longestCommonPrefix(param) == result);
}
