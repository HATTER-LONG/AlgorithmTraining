#include "Tools/Tools.hpp"

string minWindow(string s, string t) {
    vector<int> target(128, 0);
    vector<bool> flag(128, false);

    int tSize = t.length();
    int sSize = s.length();

    for(int i = 0; i < tSize; i++) {
        target[t[i]]++;
        flag[t[i]] = true;
    }

    int l = 0, cnt = 0, minL = 0, minLen = sSize + 1;
    for(int r = 0; r < sSize; r++) {
        if(flag[s[r]]) {
            if(--target[s[r]] >= 0)
                ++cnt;
            if(cnt == tSize) {
                while(cnt == tSize) {
                    if(r - l + 1 < minLen) {
                        minL = l;
                        minLen = r - l + 1;
                    }

                    if(flag[s[l]] && ++target[s[l]] > 0) {
                        --cnt;
                    }
                    ++l;
                }
            }
        }
    }
    return minLen > sSize ? "" : s.substr(minL, minLen);
}

TEST_CASE("Check Solution minWindow method work successfully") {
    string inputParm, inputParm2, resultParm;

    tie(inputParm, inputParm2, resultParm) = GENERATE(table<string, string, string>({
        make_tuple("ADOBECODEBANC", "ABC", "BANC"),
        make_tuple("a", "a", "a"),
    }));

    CAPTURE(inputParm, inputParm2, resultParm);

    REQUIRE_THAT(minWindow(inputParm, inputParm2), Catch::Equals(resultParm));
}
