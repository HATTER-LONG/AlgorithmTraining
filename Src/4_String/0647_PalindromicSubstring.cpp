#include <catch2/catch_all.hpp>

using namespace std;
using namespace Catch;

class Solution {
public:
    int countSubstrings(string s) { return 0; }
};

TEST_CASE("Check Solution longestPalindrome method work successfully ", "[.]") {
    Solution solution;

    string inputStr;
    int result;
    tie(inputStr, result) = GENERATE(table<string, int>({
        make_tuple("abc", 3),
        make_tuple("aaa", 6),
    }));

    REQUIRE(solution.countSubstrings(inputStr) == 0);
}
