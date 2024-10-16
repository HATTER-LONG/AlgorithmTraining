#include <catch2/catch.hpp>
#include <unordered_map>
#include <vector>

using namespace Catch;
using namespace std;
// hash 表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        for(size_t i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto iter = record.find(complement);
            if(iter != record.end()) {
                int l = i;
                int r = iter->second;
                if(l > r)
                    swap(l, r);

                return {l, r};
            }
            record[nums[i]] = static_cast<int>(i);
        }
        return {};
    }
};

TEST_CASE("Check Solution twoSum method work successfully") {
    Solution solution;
    vector<int> inputParam{2, 7, 11, 15};
    int target = 9;

    REQUIRE_THAT(solution.twoSum(inputParam, target), Equals(vector<int>{0, 1}));
}
