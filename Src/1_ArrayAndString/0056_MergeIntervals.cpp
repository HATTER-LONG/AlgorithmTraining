#include <catch2/catch_all.hpp>
using namespace Catch;
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),
             intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        vector<vector<int>> ans;
        size_t n = intervals.size();
        for (size_t i = 0; i < n;)
        {
            int big = intervals[i][1];
            size_t j = i + 1;
            while (j < n && intervals[j][0] <= big)
            {
                big = max(big, intervals[j][1]);
                j++;
            }
            ans.push_back({ intervals[i][0], big });
            i = j;
        }
        return ans;
    }
};

TEST_CASE("Check Solution merge method work successfully")
{
    Solution solution;

    vector<vector<int>> inputParm;

    vector<vector<int>> resultParm;

    tie(inputParm,
        resultParm) = GENERATE(table<vector<vector<int>>, vector<vector<int>>>({
        make_tuple(
            vector<vector<int>> { { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } },
            vector<vector<int>> { { 1, 6 }, { 8, 10 }, { 15, 18 } }),

        make_tuple(vector<vector<int>> { { 1, 4 }, { 4, 5 } },
                   vector<vector<int>> { { 1, 5 } }),
        make_tuple(vector<vector<int>> { { 1, 4 }, { 0, 4 } },
                   vector<vector<int>> { { 0, 4 } }),
    }));

    CAPTURE(inputParm, resultParm);
    REQUIRE_THAT(solution.merge(inputParm), Matchers::Equals(resultParm));
}
