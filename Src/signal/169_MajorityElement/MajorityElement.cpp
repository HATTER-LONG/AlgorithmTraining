#include <algorithm>
#include <catch2/catch.hpp>
#include <climits>
#include <cstddef>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace Catch;
using namespace std;

// 摩尔投票法
// 前提必须有值大于 1/2

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, cnt = 0;
        for(size_t i = 0; i < nums.size(); i++) {
            if(cnt == 0) {
                res = nums[i];
                cnt++;
            } else {
                res == nums[i] ? cnt++ : cnt--;
            }
        }
        return res;
    }
};

TEST_CASE("Check Solution maxProduct method work successfully") {
    Solution solution;
    vector<int> inputParmA;
    int result = 0;
    tie(inputParmA, result) = GENERATE(table<vector<int>, int>({
        make_tuple(vector<int>{3, 2, 3}, 3),
        make_tuple(vector<int>{2, 2, 1, 1, 1, 2, 2}, 2),
    }));

    REQUIRE(solution.majorityElement(inputParmA) == result);
}