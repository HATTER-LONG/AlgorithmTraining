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

4. [0704\_二分查找](https://leetcode.cn/problems/binary-search/)--[code](./Src/1_ArrayAndString/0704_BinarySearch.cpp):

   给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

   ```text
   你可以假设 nums 中的所有元素是不重复的。
   n 将在 [1, 10000]之间。
   nums 的每个元素都将在 [-9999, 9999]之间。

   ----------------------------------------

   输入: nums = [-1,0,3,5,9,12], target = 9
   输出: 4
   解释: 9 出现在 nums 中并且下标为 4

   ----------------------------------------

   输入: nums = [-1,0,3,5,9,12], target = 2
   输出: -1
   解释: 2 不存在 nums 中因此返回 -1
   ```

   - 解题思路: 题目的前提是数组为有序数组，同时题目还强调数组中无重复元素，因为一旦有重复元素，使用二分查找法返回的元素下标可能不是唯一的，这些都是使用二分法的前提条件。写二分法，区间的定义一般为两种，左闭右闭即 `[left, right]`，或者左闭右开即 `[left, right)`。
     - `[left, right]` 左闭右闭区间：
       1. `while (left <= right)` 要使用 `<=` ，因为 `left == right` 是有意义的，所以使用 `<=`；
       2. `if (nums[middle] > target)`，right 要赋值为 `middle - 1`，因为当前这个 `nums[middle]` 一定不是 target，那么接下来要查找的左区间结束下标位置就是 middle - 1。
     - `[left, right)` 左闭右开区间：
       1. `while (left < right)`，这里使用 `<` ,因为 `left == right` 在区间 `[left, right)` 是没有意义的；
       2. `if (nums[middle] > target)`， right 更新为 middle，因为当前 `nums[middle]` 不等于 target，去左区间继续寻找，而寻找区间是左闭右开区间，所以 right 更新为 middle，即：下一个查询区间不会去比较 `nums[middle]`。

5. [0027\_移除元素](https://leetcode.cn/problems/remove-element/)--[code](./Src/1_ArrayAndString/0027_RemoveElement.cpp):

   给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

   不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。

   元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

   ```text
   输入：nums = [3,2,2,3], val = 3
   输出：2, nums = [2,2]
   解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。

   ----------------------------------------

   输入：nums = [0,1,2,2,3,0,4,2], val = 2
   输出：5, nums = [0,1,4,0,3]
   解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。

   ```

   - 解题思路：通过一个快指针和慢指针在一个 for 循环下完成两个 for 循环的工作。

     - 双指针法（快慢指针法）在数组和链表的操作中是非常常见的，很多考察数组、链表、字符串等操作的面试题，都使用双指针法。

     ![sample](https://code-thinking.cdn.bcebos.com/gifs/27.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0-%E5%8F%8C%E6%8C%87%E9%92%88%E6%B3%95.gif)

6. [0977\_有序数组的平方](https://leetcode.cn/problems/squares-of-a-sorted-array/)--[code](./Src/1_ArrayAndString/0977_SquaresOfASortedArray.cpp):

   给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

   ```text
   示例 1： 输入：nums = [-4,-1,0,3,10] 输出：[0,1,9,16,100] 解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]

   示例 2： 输入：nums = [-7,-3,2,3,11] 输出：[4,9,9,49,121]
   ```

   - 解题思路：数组是有序的，只不过平方后负数可能成为最大数，想要在单词循环中完成比对左右平后大小需要使用 **双指针**，

     ```text
     如果A[i] * A[i] < A[j] * A[j] 那么result[k--] = A[j] * A[j]; 。

     如果A[i] * A[i] >= A[j] * A[j] 那么result[k--] = A[i] * A[i]; 。
     ```

     ![sample](https://code-thinking.cdn.bcebos.com/gifs/977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.gif)

7. [0209\_长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/)--[code](./Src/1_ArrayAndString/0209_MinimumSizeSubarraySum.cpp):

   给定一个含有  n  个正整数的数组和一个正整数 target 。

   找出该数组中满足其和 `≥ target` 的长度最小的 连续子数组 `[numsl, numsl+1, ..., numsr-1, numsr]` ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

   ```text
   输入：target = 7, nums = [2,3,1,2,4,3]
   输出：2
   解释：子数组 [4,3] 是该条件下的长度最小的子数组。

   -----------------------------------------------

   输入：target = 4, nums = [1,4,4]
   输出：1

   -----------------------------------------------

   输入：target = 11, nums = [1,1,1,1,1,1,1,1]
   输出：0
   ```

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
