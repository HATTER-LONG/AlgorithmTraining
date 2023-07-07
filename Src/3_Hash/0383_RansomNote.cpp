#include <catch2/catch_all.hpp>
#include <glog/logging.h>
#include <unordered_map>

using namespace Catch;
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int box[26] = { 0 };
        for (auto c : magazine) {
            box[c - 'a']++;
        }

        for (auto c : ransomNote) {
            if (--box[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

TEST_CASE("Check Solution canConstruct method work successfully")
{
    Solution solution;

    string param, param2;
    bool result = false;
    tie(param, param2, result) = GENERATE(table<string, string, bool>({
        make_tuple("a", "b", false),
        make_tuple(
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
            true),
    }));

    CAPTURE(param, param2, result);
    REQUIRE(solution.canConstruct(param, param2) == result);
}
