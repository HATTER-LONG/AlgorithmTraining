#include <catch2/catch.hpp>
#include <cstddef>
#include <map>
#include <spdlog/spdlog.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using namespace Catch;
using namespace spdlog;

//递归
class Solution
{
public:
    unordered_map<char, string> keypad { { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" },
        { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };

    vector<string> result;
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return result;

        addLetter(digits, "");
        return result;
    }

    void addLetter(string Str, string resultStr)
    {
        string key = keypad[Str[0]];
        for (size_t index = 0; index < key.length(); index++)
        {
            string tmpstr = resultStr + key[index];
            if (Str.length() == 1)
            {
                result.push_back(tmpstr);
            }
            else
            {
                addLetter(Str.substr(1), tmpstr);
            }
        }
    }
};


TEST_CASE("Check Solution threeSum method work successfully ")
{
    Solution solution;

    string inputStr;
    vector<string> result;

    tie(inputStr, result) = GENERATE(table<string, vector<string>>({
        make_tuple("23", vector<string> { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }),
        make_tuple("", vector<string> {}),
        make_tuple("2", vector<string> { "a", "b", "c" }),
    }));
    CAPTURE(inputStr, result);
    REQUIRE_THAT(solution.letterCombinations(inputStr), Equals(result));
}