#include "Tools/Tools.hpp"

#include <unordered_set>

/*
 * 题目描述
 *   给定一个整数数组，求这个数组中的数字可以组成的最长连续序列有多长。
 * 输入输出样例
 *   输入一个整数数组，输出一个整数，表示连续序列的长度。
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * 在这个样例中，最长连续序列是 [1,2,3,4]。
 */

int longestConsecutive(vector<int>& nums)
{
    unordered_set<int> hash;

    for (const auto& num : nums)
    {
        //去重
        hash.insert(num);
    }

    int ans = 0;
    while (!hash.empty())
    {
        int cur = *(hash.begin());
        hash.erase(cur);
        int next = cur + 1, prev = cur - 1;
        while (hash.count(next))
        {
            hash.erase(next++);
        }
        while (hash.count(prev))
        {
            hash.erase(prev--);
        }
        ans = max(ans, next - prev - 1);
    }
    return ans;
}


TEST_CASE("Check Solution longestConsecutive method work successfully")
{
    vector<int> inputParm;
    int resultParm = 0;

    tie(inputParm, resultParm) = GENERATE(table<vector<int>, int>({
        make_tuple(vector<int> { 100, 4, 200, 1, 3, 2 }, 4),
        make_tuple(vector<int> { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 }, 9),
    }));

    CAPTURE(inputParm, resultParm);

    REQUIRE(longestConsecutive(inputParm) == (resultParm));
}
