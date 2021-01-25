#include <algorithm>
#include <string>

using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int count = 0;

        string tmpstr;
        for (int i = 0; i < s.length(); i++)
        {
            string::size_type pos;
            pos = tmpstr.find(s[i]);
            if (pos != string::npos)
            {
                if ((i + pos + 2) > s.length())
                    break;

                tmpstr = tmpstr.substr(pos + 1);
                string cutstr = tmpstr + s.substr(i, pos + 2);

                if (cutstr.length() > count && !hasRepeatingChar(cutstr))
                {
                    tmpstr = cutstr;
                    count = tmpstr.length();
                    i += pos + 1;
                    continue;
                }
            }
            tmpstr += s[i];
            if (tmpstr.length() > count)
            {
                count = tmpstr.length();
            }
        }
        return count;
    }

    bool hasRepeatingChar(const string& str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (count(str.begin(), str.end(), str[i]) > 1)
            {
                return true;
            }
        }
        return false;
    }
};
