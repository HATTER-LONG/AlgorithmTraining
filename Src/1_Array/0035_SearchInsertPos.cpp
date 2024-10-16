#include <catch2/catch_all.hpp>
using namespace Catch;
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        // 二分查找重点在于右侧边界是否闭合，当前为左闭右闭，因此 lo == hi 是有意义的
        while(lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            if(nums[mid] < target)
                lo = mid + 1;
            else if(nums[mid] > target)
                hi = mid - 1; // 右闭区间不需要包含 mid，右开区间需要包括 mid
            else
                return mid;
        }
        return lo;
    }
};

TEST_CASE("Check Solution searchInsert method work successfully") {
    Solution solution;

    vector<int> param;
    int target = -1;
    int result = -1;
    tie(param, target, result) = GENERATE(table<vector<int>, int, int>({
        make_tuple(vector<int>{1, 3, 5, 6}, 5, 2),
        make_tuple(vector<int>{1, 3, 5, 6}, 2, 1),
        make_tuple(vector<int>{1, 3, 5, 6}, 0, 0),
        make_tuple(vector<int>{1, 3, 5, 6}, 7, 4),
    }));

    REQUIRE(solution.searchInsert(param, target) == result);
}
