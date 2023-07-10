#include <catch2/catch_all.hpp>

using namespace std;
using namespace Catch;

class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};


TEST_CASE("Check Solution reverseLeftWords method work successfully ")
{
    Solution solution;

    string input;
    int target = 0;
    string result;
    tie(input, target, result) = GENERATE(table<string, int, string>({
        make_tuple("abcdefg", 2, "cdefgab"),
    }));
    CAPTURE(input, target, result);
    REQUIRE(solution.reverseLeftWords(input, target) == (result));
}
