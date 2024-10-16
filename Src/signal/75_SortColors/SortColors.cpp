#include <catch2/catch.hpp>
#include <cstddef>
#include <string>
#include <tuple>

using namespace Catch;
using namespace std;

// 双指针

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return;
        }

        int p = 0, q = n - 1;
        for(int i = 0; i <= q; i++) {
            if(nums[i] == 0) {
                nums[i] = nums[p];
                nums[p] = 0;
                ++p;
            } else if(nums[i] == 2) {
                nums[i] = nums[q];
                nums[q] = 2;
                --q;
                if(nums[i] != 1) // 注意如果交换过来的不是 1 需要回退 i 重新处理
                {
                    --i;
                }
            }
        }
        return;
    }
};

TEST_CASE("Check Solution sortColors method work successfully") {
    Solution solution;

    vector<int> inputParm, resultParm;

    tie(inputParm, resultParm) = GENERATE(table<vector<int>, vector<int>>({
        make_tuple(vector<int>{2, 0, 2, 1, 1, 0}, vector<int>{0, 0, 1, 1, 2, 2}),
        make_tuple(vector<int>{2, 0, 1}, vector<int>{0, 1, 2}),
    }));

    CAPTURE(inputParm, resultParm);
    solution.sortColors(inputParm);
    REQUIRE_THAT(inputParm, Equals(resultParm));
}