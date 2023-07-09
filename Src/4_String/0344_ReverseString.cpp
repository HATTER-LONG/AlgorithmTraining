#include <catch2/catch_all.hpp>

using namespace std;
using namespace Catch;

class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while (right > left) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};


TEST_CASE("Check Solution reverseString method work successfully ", "[.]")
{
    Solution solution;

    vector<char> input;
    vector<char> result;
    tie(input, result) = GENERATE(table<vector<char>, vector<char>>({
        make_tuple(vector<char> { 'h', 'e', 'l', 'l', 'o' },
                   vector<char> { 'o', 'l', 'l', 'e', 'h' }),
    }));
    solution.reverseString(input);
    REQUIRE_THAT(input, Matchers::Equals(result));
}
