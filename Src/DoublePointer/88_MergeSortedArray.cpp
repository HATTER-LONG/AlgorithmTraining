#include "Tools/Tools.hpp"

/*
 * 双指针
 * 题目描述
 *   给定两个有序数组，把两个数组合并为一个。
 *
 * 输入输出样例
 *   输入是两个数组和它们分别的长度 m 和 n。
 *   其中第一个数组的长度被延长至 m + n，多出的 n 位被 0 填补。
 *   题目要求把第二个数组归并到第一个数组上，不需要开辟额外空间。
 *
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * Output: nums1 = [1,2,2,3,5,6]
 *
 */

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pos = m-- + n-- - 1;
    while(m >= 0 && n >= 0)
    {
        nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
    while(n >=0)
    {
        nums1[pos--] = nums2[n--];
    }
}

TEST_CASE("test merge func")
{
    VecInt nums1, nums2;
    int m, n;

    VecInt result;
    tie(nums1, m, nums2, n, result) =
        GENERATE(table<VecInt, int, VecInt, int, VecInt>(
            { make_tuple(VecInt { 1, 2, 3, 0, 0, 0 }, 3, VecInt { 2, 5, 6 }, 3,
                VecInt { 1, 2, 2, 3, 5, 6 }) }));
    merge(nums1, m, nums2, n);
    REQUIRE_THAT(nums1, Catch::Equals(result));
}
