#include <algorithm>
#include <catch2/catch.hpp>
#include <climits>
#include <cstddef>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>
using namespace Catch;
using namespace std;

// Hash 哈希表记录

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> num_set;
        // 去重
        for (const auto& num : nums)
        {
            num_set.insert(num);
        }

        int longestStreak = 0;
        for (const auto& num : num_set)
        {
            //枚举的数 xx 一定是在数组中不存在前驱数 x-1x−1 的，不然按照上面的分析我们会从 x-1x−1
            //开始尝试匹配，因此我们每次在哈希表中检查是否存在 x-1x−1 即能判断是否需要跳过了。
            if (!num_set.count(num - 1))
            {
                int currentNum = num;
                int currentStreak = 1;
                while (num_set.count(currentNum + 1))
                {
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};

TEST_CASE("Check Solution longestConsecutive method work successfully")
{
    Solution solution;

    vector<int> inputParm;
    int resultParm = 0;

    tie(inputParm, resultParm) = GENERATE(table<vector<int>, int>({
        make_tuple(vector<int> { 100, 4, 200, 1, 3, 2 }, 4),
        make_tuple(vector<int> { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 }, 9),
    }));

    CAPTURE(inputParm, resultParm);

    REQUIRE(solution.longestConsecutive(inputParm) == (resultParm));
}