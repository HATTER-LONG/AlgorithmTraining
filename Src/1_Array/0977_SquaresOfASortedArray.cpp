#include "Tools/Tools.hpp"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        while(left <= right) {
            if(nums[left] * nums[left] < nums[right] * nums[right]) {
                result[right - left] = nums[right] * nums[right];
                --right;
            } else {
                result[right - left] = nums[left] * nums[left];
                ++left;
            }
        }
        return result;
    }
};

TEST_CASE("Check Solution sortedSquares method work successfully") {
    Solution solution;
    vector<int> inputParm, resultParm;

    tie(inputParm, resultParm) = GENERATE(table<vector<int>, vector<int>>({
        make_tuple(vector<int>{-4, -1, 0, 3, 10}, vector<int>{0, 1, 9, 16, 100}),
        make_tuple(vector<int>{-7, -3, 2, 3, 11}, vector<int>{4, 9, 9, 49, 121}),
    }));

    CAPTURE(inputParm, resultParm);
    REQUIRE_THAT(solution.sortedSquares(inputParm), Catch::Matchers::Equals(resultParm));
}
