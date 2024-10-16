#include <catch2/catch.hpp>
#include <limits.h>
#include <string>
#include <tuple>
using namespace std;
using namespace Catch;

class Solution_Mine {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

        int count = nums1.size() / 2 - 1;
        if(nums1.size() % 2 == 0) {
            return (nums1[count] + nums1[count + 1]) / 2.0;
        }
        return nums1[count + 1];
    }
};

// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(n > m) // 保证数组1一定最短
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Ci
        // 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。
        // LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
        int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0;
        int hi = 2 * n; // 我们目前是虚拟加了'#'所以数组1是2*n长度

        while(lo <= hi) // 二分
        {
            c1 = (lo + hi) / 2; // c1是二分的结果
            c2 = m + n - c1;

            LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
            LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

            if(LMax1 > RMin2)
                hi = c1 - 1;
            else if(LMax2 > RMin1)
                lo = c1 + 1;
            else
                break;
        }
        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
    }
};

TEST_CASE("Check Solution lengthOfLongestSubstring method work successfully ") {
    Solution solution;

    vector<int> LeftParm, RightParm;
    double result = -1;
    // clang-format off
    tie(LeftParm, RightParm, result) = 
        GENERATE(table<vector<int>, vector<int>, double>
            (
                {
                    make_tuple(vector<int>{1, 3},vector<int>{2}, 2.0),
                    make_tuple(vector<int>{1, 2},vector<int>{3, 4}, 2.5),
                    make_tuple(vector<int>{0, 0},vector<int>{0, 0}, 0.0),
                    make_tuple(vector<int>{},vector<int>{1}, 1.0),
                    make_tuple(vector<int>{2},vector<int>{}, 2.0),
                    make_tuple(vector<int>{1,2},vector<int>{1,2}, 1.5),
                    make_tuple(vector<int>{1,1},vector<int>{1,2}, 1.0),
                }
            )
        );
    // clang-format on;

    REQUIRE(solution.findMedianSortedArrays(LeftParm, RightParm) == result);
}