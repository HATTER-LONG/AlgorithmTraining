#include <catch2/catch_all.hpp>
#include <unordered_map>
using namespace Catch;
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> need;
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            auto iter = need.find(target - nums[i]);
            if (iter != need.end()) {
                return vector<int> { iter->second, i };
            }
            need.insert({ nums[i], i });
        }
        return {};
    }
};

TEST_CASE("Check Solution twoSum method work successfully")
{
    Solution solution;

    vector<int> param, result;
    int param2;
    tie(param, param2, result) = GENERATE(table<vector<int>, int, vector<int>>({
        make_tuple(vector<int> { 1, 2, 2, 1 }, 3, vector<int> { 0, 1 }),
        make_tuple(vector<int> { 2, 7, 11, 15 }, 9, vector<int> { 0, 1 }),
        make_tuple(vector<int> { 3, 2, 4 }, 6, vector<int> { 1, 2 }),
    }));

    CAPTURE(param, param2, result);
    REQUIRE_THAT(solution.twoSum(param, param2), Matchers::Equals(result));
}
