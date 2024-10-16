#include <catch2/catch_all.hpp>
using namespace Catch;
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26] = {0};

        for(auto c : s) {
            hash[c - 'a']++;
        }

        for(auto c : t) {
            hash[c - 'a']--;
        }

        for(int i = 0; i < 26; i++) {
            if(hash[i] != 0)
                return false;
        }

        return true;
    }
};

TEST_CASE("Check Solution isAnagram method work successfully") {
    Solution solution;

    string param, param2;
    bool result = false;
    tie(param, param2, result) = GENERATE(table<string, string, bool>({
        make_tuple("anagram", "nagaram", true),
        make_tuple("rat", "cat", false),
    }));

    CAPTURE(param, param2, result);
    REQUIRE(solution.isAnagram(param, param2) == result);
}
