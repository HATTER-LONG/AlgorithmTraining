#include <catch2/catch_all.hpp>

using namespace std;
using namespace Catch;

class Solution {
public:
    string reverseString(string s, int k) {
        // 每次步长为 2*k 长
        for(int i = 0; i < static_cast<int>(s.length()); i += 2 * k) {

            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if(i + k <= static_cast<int>(s.length())) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                // 3. 剩余字符小于 k 个，反转剩余全部
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

TEST_CASE("Check Solution 541reverseString method work successfully ") {
    Solution solution;

    string input;
    int target;
    string result;
    tie(input, target, result) = GENERATE(table<string, int, string>({
        make_tuple("abcdefg", 2, "bacdfeg"),
    }));
    REQUIRE_THAT(solution.reverseString(input, target), Matchers::Equals(result));
}
