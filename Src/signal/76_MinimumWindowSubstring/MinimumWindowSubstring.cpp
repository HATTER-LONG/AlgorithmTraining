#include <catch2/catch.hpp>
#include <cstddef>
#include <cstdint>
#include <string>
#include <tuple>
#include <unordered_map>

using namespace Catch;
using namespace std;

// 滑动窗口

class Solution {
public:
    bool check() {
        for(const auto& p : ori) {
            if(cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(s.length() < 2) {
            return s == t ? s : "";
        }
        for(const auto& c : t) {
            ++ori[c];
        }
        int l = 0, r = -1;
        int len = INT32_MAX, ansL = -1;

        while(r < static_cast<int>(s.length())) {
            if(ori.find(s[++r]) != ori.end()) {
                ++cnt[s[r]];
            }
            while(check() && l <= r) {
                if(r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if(ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }
                ++l;
            }
        }
        return ansL == -1 ? "" : s.substr(ansL, len);
    }

private:
    unordered_map<char, int> ori, cnt;
};

TEST_CASE("Check Solution minWindow method work successfully") {
    Solution solution;

    string inputParm, inputParm2, resultParm;

    tie(inputParm, inputParm2, resultParm) = GENERATE(table<string, string, string>({
        make_tuple("ADOBECODEBANC", "ABC", "BANC"),
        make_tuple("a", "a", "a"),
    }));

    CAPTURE(inputParm, inputParm2, resultParm);

    REQUIRE_THAT(solution.minWindow(inputParm, inputParm2), Equals(resultParm));
}