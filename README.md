# LeetCode 算法刷题

<!-- PROJECT SHIELDS -->

![Contributors][build-url]
[![Contributors][contributors-shield]][contributors-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]

<!--[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![LinkedIn][linkedin-shield]][linkedin-url]-->
<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/HATTER-LONG/AlgorithmTraining.svg?style=flat
[contributors-url]: https://github.com/HATTER-LONG/AlgorithmTraining/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/HATTER-LONG/AlgorithmTraining.svg?style=flat
[forks-url]: https://github.com/HATTER-LONG/AlgorithmTraining/network/members
[stars-shield]: https://img.shields.io/github/stars/HATTER-LONG/AlgorithmTraining.svg?style=flat
[stars-url]: https://github.com/HATTER-LONG/AlgorithmTraining/stargazers
[issues-shield]: https://img.shields.io/github/issues/HATTER-LONG/AlgorithmTraining.svg?style=flat
[issues-url]: https://github.com/HATTER-LONG/AlgorithmTraining/issues
[license-shield]: https://img.shields.io/github/license/HATTER-LONG/AlgorithmTraining?style=flat
[license-url]: https://github.com/HATTER-LONG/AlgorithmTraining/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/othneildrew
[build-url]: https://github.com/HATTER-LONG/AlgorithmTraining/workflows/CMake/badge.svg?style=flat

## 数组和字符串

### 数组

1. [寻找数组的中心索引](https://leetcode.cn/problems/find-the-middle-index-in-array/)--[code](./Src/1_ArrayAndString/1991_FindTheMiddleIndexInArray.cpp):

   给你一个整数数组  nums ，请计算数组的 中心下标 。

   数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。

   如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。

   如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。

   ```text

   1 <= nums.length <= 104
   -1000 <= nums[i] <= 1000

   ---------------------------------------

   输入：nums = [1, 7, 3, 6, 5, 6]
   输出：3
   解释：
   中心下标是 3 。
   左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
   右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。

   ---------------------------------------

   输入：nums = [1, 2, 3]
   输出：-1
   解释：
   数组中不存在满足此条件的中心下标。

   ---------------------------------------

   输入：nums = [2, 1, -1]
   输出：0
   解释：
   中心下标是 0 。
   左侧数之和 sum = 0 ，（下标 0 左侧不存在元素），
   右侧数之和 sum = nums[1] + nums[2] = 1 + -1 = 0 。

   ```

   - 解题思路：主要在于优化计算量，先计算总和，然后遍历计算 left 总和，如果 left 总和 ×2 加当前值等于总和，就返回当前值

2. [搜索插入位置](https://leetcode.cn/problems/search-insert-position/)--[code](./Src/1_ArrayAndString/0000_SearchInsertPos.cpp):

   给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

   请必须使用时间复杂度为 O(log n) 的算法。

   ```text

   1 <= nums.length <= 104
   -104 <= nums[i] <= 104
   nums 为 无重复元素 的 升序 排列数组
   -104 <= target <= 104

   ---------------------------------------

   输入: nums = [1,3,5,6], target = 5
   输出: 2

   ---------------------------------------


   输入: nums = [1,3,5,6], target = 2
   输出: 1

   ---------------------------------------

   输入: nums = [1,3,5,6], target = 7
   输出: 4

   ```

   - 解题思路：从有序数组和时间复杂度来看可以判断使用二分法，重点在 `while` 循环条件 `lo <= hi` 这样保证 `lo` 最后会被更新，避免返回 `lo` 出错。

3. [合并区间](https://leetcode.cn/leetbook/read/array-and-string/c5tv3/)--[code](./Src/1_ArrayAndString/0056_MergeIntervals.cpp):

   以数组 intervals 表示若干个区间的集合，其中单个区间为 `intervals[i] = [starti, endi]` 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

   ```text
   1 <= intervals.length <= 104
   intervals[i].length == 2
   0 <= starti <= endi <= 104

   ------------------------------------------

   输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
   输出：[[1,6],[8,10],[15,18]]
   解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

   ------------------------------------------

   输入：intervals = [[1,4],[4,5]]
   输出：[[1,5]]
   解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
   ```
   - 解题思路：合并重叠的区域，首先想到排序使得可以合并的区域相邻，在使用双指针查找两个区域重叠即可。
