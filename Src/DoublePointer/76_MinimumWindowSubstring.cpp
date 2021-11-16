#include "Tools/Tools.hpp"

string minWindow(string s, string t)
{
    vector<int> chars(128, 0);   // 记录存在的字符情况
    vector<bool> flags(128, false);

    for (size_t i = 0; i < t.length(); i++)
    {
        flags[t[i]] = true;
        ++chars[t[i]];
    }   // O(n)

    // 移动滑动窗口，不断更改统计数据
    int cnt = 0, l = 0, minL = 0, minSize = s.length() + 1;
    int length = s.length();
    for (int r = 0; r < length; r++)
    {
        if (flags[s[r]])
        {
            if (--chars[s[r]] >= 0)
            {
                ++cnt;
            }

            // 若目前滑动窗口已包含 T 中全部字符，
            // 则尝试将 l 右移，在不影响结果的情况下获得最短字符串
            while (cnt == static_cast<int>(t.size()))
            {
                if (r - l + 1 < minSize)
                {
                    minL = l;
                    minSize = r - l + 1;
                }
                if (flags[s[l]] && ++chars[s[l]] > 0)
                {
                    --cnt;
                }
                ++l;
            }
        }
    }
    return minSize > static_cast<int>(s.size()) ? "" : s.substr(minL, minSize);
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
