#include "Tools/Tools.hpp"
/*
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1
 * 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 *
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 示例 2：
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 */

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    if (nums1.size() > nums2.size())
    {
        return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();
    int left = 0, right = m;
    // median1：前一部分的最大值
    // median2：后一部分的最小值
    int median1 = 0, median2 = 0;

    while (left <= right)
    {
        // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
        // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
        int i = (left + right) / 2;
        int j = (m + n + 1) / 2 - i;

        // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i],
        // nums2[j-1], nums2[j]
        int numsIm1 = (i == 0 ? INT_MIN : nums1[i - 1]);
        int numsI = (i == m ? INT_MAX : nums1[i]);
        int numsJm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
        int numsJ = (j == n ? INT_MAX : nums2[j]);

        if (numsIm1 <= numsJ)
        {
            median1 = max(numsIm1, numsJm1);
            median2 = min(numsI, numsJ);
            left = i + 1;
        }
        else
        {
            right = i - 1;
        }
    }

    return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
}

TEST_CASE("Check Solution lengthOfLongestSubstring method work successfully ")
{
    vector<int> leftParm, rightParm;
    double result = -1;
    // clang-format off
    tie(leftParm, rightParm, result) = 
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

    REQUIRE(findMedianSortedArrays(leftParm, rightParm) == result);
}
