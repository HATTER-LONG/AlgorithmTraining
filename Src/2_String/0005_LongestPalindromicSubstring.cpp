#include <catch2/catch_all.hpp>

using namespace std;
using namespace Catch;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        return s;
    }
};


TEST_CASE("Check Solution lengthOfLongestSubstring method work successfully ", "[.]")
{
    Solution solution;

    string inputStr;
    string result;
    tie(inputStr, result) = GENERATE(table<string, string>({
        make_tuple("babad", "bab"),
        make_tuple("cbbd", "bb"),
        make_tuple("a", "a"),
        make_tuple("ac", "a"),
    }));

    REQUIRE_THAT(solution.longestPalindrome(inputStr), Matchers::Equals(result));
}
