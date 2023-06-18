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

1. [1991\_寻找数组的中心索引](https://leetcode.cn/problems/find-the-middle-index-in-array/)--[code](./Src/1_ArrayAndString/1991_FindTheMiddleIndexInArray.cpp):

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

2. [0035\_搜索插入位置](https://leetcode.cn/problems/search-insert-position/)--[code](./Src/1_ArrayAndString/0035_SearchInsertPos.cpp):

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

3. [0056\_合并区间](https://leetcode.cn/leetbook/read/array-and-string/c5tv3/)--[code](./Src/1_ArrayAndString/0056_MergeIntervals.cpp):

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

   - 解题思路：合并重叠的区域，首先想到排序使得可以合并的区域相邻，在比对相邻区域是否重合即可。

### 二维数组

1. [0048\_旋转矩阵](https://leetcode.cn/problems/rotate-image/)--[code](./Src/1_ArrayAndString/0048_RotateImage.cpp):

   给定一个 `n × n` 的二维矩阵  matrix 表示一个图像。请你将图像顺时针旋转 90 度。

   你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

   ```text
   n == matrix.length == matrix[i].length
   1 <= n <= 20
   -1000 <= matrix[i][j] <= 1000

   ------------------------------------------

   给定 matrix =
   [
   [1,2,3],
   [4,5,6],
   [7,8,9]
   ],

   原地旋转输入矩阵，使其变为:
   [
   [7,4,1],
   [8,5,2],
   [9,6,3]
   ]

   ------------------------------------------

   给定 matrix =
   [
   [ 5, 1, 9,11],
   [ 2, 4, 8,10],
   [13, 3, 6, 7],
   [15,14,12,16]
   ],

   原地旋转输入矩阵，使其变为:
   [
   [15,13, 2, 5],
   [14, 3, 4, 1],
   [12, 6, 8, 9],
   [16, 7,10,11]
   ]
   ```

   - [解题思路](https://leetcode.cn/problems/rotate-image/solution/lu-qing-ge-chong-by-pennx-ce3x/)：旋转类基本操作如下，其他角度可以根据如下基础方法组合：

   ```text
   上下对称：matrix[i][j] -> matrix[n-i-1][j]，（列不变）
   左右对称：matrix[i][j] -> matrix[i][n-j-1]，（行不变）
   主对角线对称：matrix[i][j] -> matrix[j][i]，（行列互换）
   副对角线对称：matrix[i][j] -> matrix[n-j-1][n-i-1] （行列均变，且互换）

   那么，对于顺时针 90° 旋转，即本题，先写出转移式：
    matrix[i][j] -> matrix[j][n-i-1]，
   可以观察到，我们希望原来的列j不变，且要交换行列位置。
   因此可以分解为：上下对称 + 主对角线对称 或者 主对角线对称 + 左右对称，
   注意分解顺序是不能换的。
   ```

2. [0073\_矩阵置零](https://leetcode.cn/problems/set-matrix-zeroes/)--[code](./Src/1_ArrayAndString/0073_SetMatrixZeroes.cpp):

   编写一种算法，若 M × N 矩阵中某个元素为 0，则将其所在的行与列清零。

   ```text
   输入：
   [
   [1,1,1],
   [1,0,1],
   [1,1,1]
   ]
   输出：
   [
   [1,0,1],
   [0,0,0],
   [1,0,1]
   ]

   ------------------------------------------

   输入：
   [
   [0,1,2,0],
   [3,4,5,2],
   [1,3,1,5]
   ]
   输出：
   [
   [0,0,0,0],
   [0,4,5,0],
   [0,3,1,0]
   ]

   ```

   - 解题思路：当前行或列上存在 0 就将当前行和列上均清 0，因此不必记录具体哪些坐标 `pos[x][y]` 需要清零，只需要记录哪些行与列清 0 即可。

3. [0498\_对角线遍历](https://leetcode.cn/problems/diagonal-traverse/comments/)--[code](./Src/1_ArrayAndString/0498_DiagonalTraverse.cpp):

   给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。

   ![](https://assets.leetcode.com/uploads/2021/04/10/diag1-grid.jpg)

   ```text
   m == mat.length
   n == mat[i].length
   1 <= m, n <= 104
   1 <= m * n <= 104
   -105 <= mat[i][j] <= 105

   -------------------------------------

   输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
   输出：[1,2,4,7,5,3,6,8,9]

   -------------------------------------

   输入：mat = [[1,2],[3,4]]
   输出：[1,2,3,4]
   ```

   - [解题思路](https://leetcode.cn/problems/diagonal-traverse/solution/by-lin-shen-shi-jian-lu-k-laf5/)：按对角线的方向进行遍历，可以发现偶数对角线向右上，奇数对角线向右下:

     - 对于每条序号为 i 的对角线，判断其奇偶性：
     - 如果是偶数对角线 ，确定其横坐标 x，从下往上遍历，将 `mat[x][i - x]` 加入 res 中。
     - 如果是奇数对角线 ，确定其横坐标 x，从上往下遍历，将 `mat[x][i - x]` 加入 res 中。

     ![](https://pic.leetcode-cn.com/1652665232-EcMafx-image-20210820224609655.png)
     ![](https://pic.leetcode-cn.com/1652665284-HSqlDR-image-20210821151601039.png)

### 字符串

1. [0014\_最长公共前缀](https://leetcode.cn/problems/longest-common-prefix/)--[code](./Src/1_ArrayAndString/0014_LongestCommonPrefix.cpp):

   编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。

   ```text
   1 <= strs.length <= 200
   0 <= strs[i].length <= 200
   strs[i] 仅由小写英文字母组成

   -------------------------------------

   输入：strs = ["flower","flow","flight"]
   输出："fl"

   -------------------------------------

   输入：strs = ["dog","racecar","car"]
   输出：""
   解释：输入不存在公共前缀。
   ```

   - 解题思路：选中第一个字符串为模版比对其他字符串同一偏移字符是否一致：
     1. 其他字符串长度结束，返回当前相同长度的子字符串；
     2. 其他字符串中有不同的字符；
     3. 所有第一个字符串的字符比对结束。
