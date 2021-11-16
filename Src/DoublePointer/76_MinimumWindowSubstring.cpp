#include "Tools/Tools.hpp"

string minWindow(string s, string t)
{
    VecInt charInput(128, 0);
    vector<bool> flags(128, false);
    int tSize = t.length();
    int sSize = s.length();
    for (int i = 0; i < tSize; i++)
    {
        charInput[t[i]]++;
        flags[t[i]] = true;
    }

    int cnt = 0, l = 0, minL = 0, minSize = sSize + 1;
    for (int r = 0; r < sSize; r++)
    {
        if (flags[s[r]])
        {
            if (--charInput[s[r]] >= 0)
            {
                cnt++;
            }

            while (cnt == tSize)
            {
                if (r - l + 1 < minSize)
                {
                    minL = l;
                    minSize = r - l + 1;
                }

                if (flags[s[l]] && ++charInput[s[l]] > 0)
                {
                    cnt--;
                }
                l++;
            }
        }
    }
    return minSize > sSize ? "" : s.substr(minL, minSize);
}


TEST_CASE("Check Solution minWindow method work successfully")
{
    string inputParm, inputParm2, resultParm;

    tie(inputParm, inputParm2, resultParm) =
        GENERATE(table<string, string, string>({
            make_tuple("ADOBECODEBANC", "ABC", "BANC"),
            make_tuple("a", "a", "a"),
        }));

    CAPTURE(inputParm, inputParm2, resultParm);

    REQUIRE_THAT(minWindow(inputParm, inputParm2), Catch::Equals(resultParm));
}
