#include <catch2/catch.hpp>
#include <map>
#include <set>
#include <string>
#include <tuple>
using namespace Catch;
using namespace std;

//思路： 从后向前找到 index > index - 1 的地方，然后将已经遍历过的尾处最小数字移动 到 index -1 ，然后将index
//-1 到尾处反转
class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        size_t index = nums.size() - 1;
        map<int, size_t, greater<int>> m1;
        for (; index > 0; index--)
        {
            m1.insert(pair<int, size_t>(nums[index], index));
            if (nums[index] > nums[index - 1])
            {
                swap(nums[findBigSwapIndex(m1, nums[index - 1])], nums[index - 1]);
                reverse(nums.begin() + index, nums.end());
                break;
            }
        }
        if (0 == index)
        {
            reverse(nums.begin(), nums.end());
        }
    }
    size_t findBigSwapIndex(const map<int, size_t, greater<int>>& s1, const int num)
    {
        for (auto index = s1.begin(); index != s1.end(); index++)
        {
            if (index->first > num)
            {
                auto tmpIndex = index;
                if (((++tmpIndex) != s1.end() && tmpIndex->first <= num) || (tmpIndex) == s1.end())
                    return index->second;
            }
        }
        return -1;
    }
};



TEST_CASE("Check Solution generateParenthesis method work successfully")
{
    Solution solution;

    vector<int> InputParam, ResultParm;


    tie(InputParam, ResultParm) = GENERATE(table<vector<int>, vector<int>>({
        make_tuple(vector<int> { 1, 2, 3 }, vector<int> { 1, 3, 2 }),
        make_tuple(vector<int> { 3, 2, 1 }, vector<int> { 1, 2, 3 }),
        make_tuple(vector<int> { 1, 1, 5 }, vector<int> { 1, 5, 1 }),
        make_tuple(vector<int> { 1, 3, 2 }, vector<int> { 2, 1, 3 }),
        make_tuple(vector<int> { 1, 4, 3, 2, 1 }, vector<int> { 2, 1, 1, 3, 4 }),
        make_tuple(vector<int> { 2, 3, 1 }, vector<int> { 3, 1, 1 }),
    }));
    solution.nextPermutation(InputParam);
    REQUIRE_THAT(InputParam, Equals(ResultParm));
}