#include <catch2/catch.hpp>
#include <cstddef>
#include <iterator>
#include <spdlog/spdlog.h>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;
using namespace Catch;
using namespace spdlog;
class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        if (n % 2 == 1)
        {
            return false;
        }

        unordered_map<char, char> pairs = { { ')', '(' }, { ']', '[' }, { '}', '{' } };
        stack<char> stk;
        for (char ch : s)
        {
            if (pairs.count(ch))
            {
                if (stk.empty() || stk.top() != pairs[ch])
                {
                    return false;
                }
                stk.pop();
            }
            else
            {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};


TEST_CASE("Check Solution isValid method work successfully ")
{
    Solution solution;

    string inputStr;
    bool result;

    tie(inputStr, result) = GENERATE(table<string, bool>({
        make_tuple("()", true),
        make_tuple("()[]{}", true),
        make_tuple("(]", false),
        make_tuple("([)]", false),
    }));
    CAPTURE(inputStr, result);
    REQUIRE(solution.isValid(inputStr) == result);
}