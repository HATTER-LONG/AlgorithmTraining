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

- [LeetCode 算法刷题](#leetcode-算法刷题)
  - [01_桶_两数之和](#01_桶_两数之和)
  - [02_链表操作_两数相加](#02_链表操作_两数相加)
  - [03_滑动窗口算法_无重复字符的最长子串](#03_滑动窗口算法_无重复字符的最长子串)
  - [04_二分法_寻找两个正序数组的中位数](#04_二分法_寻找两个正序数组的中位数)
  - [05_动态规划_最长回文子串](#05_动态规划_最长回文子串)
  - [10_动态规划||递归_正则表达式匹配](#10_动态规划递归_正则表达式匹配)
  - [11_双指针_盛最多水的容器](#11_双指针_盛最多水的容器)
  - [15_双指针_双数之和](#15_双指针_双数之和)
  - [17_递归_电话号码的字母组合](#17_递归_电话号码的字母组合)
  - [19_链表操作_删除链表的倒数第 N 个结点](#19_链表操作_删除链表的倒数第-n-个结点)
  - [20_栈_有效括号](#20_栈_有效括号)
  - [21_递归算法_合并两个有序链表](#21_递归算法_合并两个有序链表)
  - [22_动态规划_括号生成](#22_动态规划_括号生成)
  - [23_分治合并_合并 K 个升序列](#23_分治合并_合并-k-个升序列)
  - [31_两遍扫描_下一个排序](#31_两遍扫描_下一个排序)
  - [32_递归||动态规划_最长有效括号](#32_递归动态规划_最长有效括号)
  - [33_二分法_搜索旋转排序数组](#33_二分法_搜索旋转排序数组)
  - [34_二分法_在排序数组中查找元素的第一个和最后一个位置](#34_二分法_在排序数组中查找元素的第一个和最后一个位置)
  - [39_回溯_组合总和](#39_回溯_组合总和)
  - [42_双指针_接雨水](#42_双指针_接雨水)
  - [46_回溯_全排列](#46_回溯_全排列)
  - [48_数组例题原地计算_旋转图像](#48_数组例题原地计算_旋转图像)
  - [49_哈希或质数相乘_字母异位词分组](#49_哈希或质数相乘_字母异位词分组)

## [01_桶_两数之和](./Src/01_TwoSum/TwoSum.cpp)

```shell
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

**桶**。

- 使用 map 记录以检查的已出现的数字和对应下标 `pair(num, index)`。
- 桶查找，直到找到与当前数组匹配的另一个数字 `Target - Num[i]`，然后返回下标。

## [02_链表操作_两数相加](./Src/02_AddTwoNumbers/AddTwoNumbers.cpp)

```shell
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
```

**两数相加**。

相加两个链表中位置对应的元素，当超过 10 时，取余进位。通过 while 循环遍历两个链表所有的元素，最终返回相加完成后的链表。

## [03_滑动窗口算法_无重复字符的最长子串](./Src/03_LongestSubstringWithoutRepeatingCharacters/LongestSubstringWithoutRepeatingCharacters.cpp)

```shell
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

**滑动窗口算法。**

- 整个循环从 l == 0; r == -1 这个空窗口开始，维护一个 res 最长的长度，通过循环遍历判断当前窗口中是否有相同的字符 (这一步判断使用桶方法)。
- 如果检查当前字符没有出现，则 r ++，增加字符到桶中， 更新 res 长度。整体窗口向右生长。
- 如果检查当前字符出现过，则 先从桶中删除 l 当前所在的字符，l ++ 向右滑动，判断是否需要更新 res 长度。整体窗口向右缩减。
- 当遍历所有字符完成得到一个最长的长度。

## [04_二分法_寻找两个正序数组的中位数](./Src/04_MedianofTwoSortedArrays/MedianofTwoSortedArrays.cpp)

```shell
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
-----------
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
```

**二分法**。

其实 insert + sort 也挺香的 `:)`。

## [05_动态规划_最长回文子串](./Src/05_LongestPalindromicSubstring/LongestPalindromicSubstring.cpp)

```shell
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
```

**动态规划**。

- 回文有两种情况 aba 和 abba，需要考虑两种不同的中间点。
- 解决方案是遍历整个字符串，已每个`当前字符`和`当前字符 + 1` 为中心点，向两边扩展比对，直到 left != right 返回此时 left 和 right 的下标，最终保存一个最长的，然后使用 substr 截取子串返回。

## [10_动态规划||递归_正则表达式匹配](./Src/10_RegularExpressionMatching/RegularExpressionMatching.cpp)

```shell
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素


输入：s = "aa" p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。

输入：s = "aaa" p = "ab*a*c*a"
输出：true
```

**动态规划或递归**。

`dp[i][j]` 表示 s 的前 i 个是否能被 p 的前 j 个匹配。

s 和 p 倒着看，`dp[i][j]` 的值可以分为以下几种情况：

1. `p[j-1]` 为普通字符，若 `s[i-1] == p[j-1]`，则 `dp[i][j] = dp[i-1][j-1]`，否则匹配失败。
2. `p[j-1]` 为 `.`，则 `dp[i][j] = dp[i-1][j-1]`。
3. `p[j−1]` 为'*'：
   1. 不看，则 `dp[i][j] = dp[i][j-2]`。
   2. 看，则 `dp[i][j] = dp[i-1][j]`。

## [11_双指针_盛最多水的容器](./Src/11_ContainerWithMostWater/ContainerWithMostWater.cpp)

![question11](Img/question_11.jpg)

```shell
输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
```

**双指针**。

这道题比较简单，首先定下左右指针，然后判断短的一侧向后或前查找下一个比自身大的数字。循环计算处最大的容积。

## [15_双指针_双数之和](./Src/15_3Sum/3Sum.cpp)

```shell
一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
```

**双指针**。

对传入的 nums 进行排序。
然后对 first 元素从 0 开始在 nums 中进行遍历，然后将 third 在 nums 末尾处向前移动。
确定 second 的值为 `nums[second] + nums[third] == -nums[first]`。

## [17_递归_电话号码的字母组合](./src/../Src/17_LetterCombinationsOfAPhoneNumber/LetterCombinationsOfAPhoneNumber.cpp)

![17_question](Img/17_telephone_keypad.png)

```shell
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**递归**。

首先遍历传入的按键，通过递归来获取对应按键所有的字母全排列情况。

## [19_链表操作_删除链表的倒数第 N 个结点](./Src/19_RemoveNthNodeFromEndofList/RemoveNthNodeFromEndofList.cpp)

```shell
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
```

**遍历或递归**。

定义一个快指针，随着循环遍历所有节点，另一个慢指针定位在快指针后 n 个位置的目标位置，找到后将慢指针后一个节点删除即可。

## [20_栈_有效括号](./Src/20_ValidParentheses/ValidParentheses.cpp)

```shell
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：
    1. 左括号必须用相同类型的右括号闭合。
    2. 左括号必须以正确的顺序闭合。

输入：s = "()"
输出：true

输入：s = "(]"
输出：false
```

**栈**。

遍历给定的字符串，当遇到一个左括号时，则会期望后续的遍历中有一个相同类型的右括号将其闭合。可以将这个左括号放入栈顶，当我们遇到一个右括号时，再将一个相同类型的左括号闭合。此时，我们可以取出栈顶的左括号并判断它们是否是相同类型的括号。如果不是相同的类型，或者栈中并没有左括号，那么字符串 s 无效，返回 False。

## [21_递归算法_合并两个有序链表](./Src/21_MergeTwoSortedLists/MergeTwoSortedLists.cpp)

```shell
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

    1 -> 2 -> 4
    1 -> 3 -> 4
        ↓
1 -> 1 -> 2 -> 3 -> 4 -> 4

输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
```

**递归算法**。

首先判断是否为空链设立递归结束条件，然后判断节点大小递归决定下一个添加到结果里的节点，直到一个链表为空，递归结束。

## [22_动态规划_括号生成](./Src/22_GenerateParentheses/GenerateParentheses.cpp)

```shell
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
```

**动态规划**。

当生成一组括号序列如 `()(())`，它最左和最右肯定是一组括号 `(*)`，我们可以认为它是最后一组增加进来的括号，而其余的 n - 1 组括号则需要对所有情况进行遍历，而符合条件的遍历模板：

`"(" + 【i=p时所有括号的排列组合】 + ")" + 【i=q时所有括号的排列组合】`

其中 p + q = n-1，且 p q 均为非负整数。事实上，当上述 p 从 0 取到 n-1，q 从 n-1 取到 0 后，所有情况就遍历完了。

## [23_分治合并_合并 K 个升序列](./Src/21_MergeTwoSortedLists/MergeTwoSortedLists.cpp)

```shell
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
```

**分治合并**。

![23](./Img/23.png)

1. 首先实现合并两个链表的方法，具体可以[参考 21 题](#21_递归算法_合并两个有序链表)；
2. 将 k 个链表配对并将同一对中的链表合并；
3. 第一轮合并以后，k 个链表被合并成了 k/2 个链表，平均长度为 2n/k 以此类推。
4. 重复直到得到最终的有序链表。

## [31_两遍扫描_下一个排序](./Src/31_NextPermutation/NextPermutation.cpp)

```shell
实现获取 **下一个排列** 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须 **原地** 修改，只允许使用额外常数空间。

输入：nums = [1,2,3]
输出：[1,3,2]
```

**两遍扫描**。

从后向前找到 index > index - 1 的地方，然后将已经遍历过的尾处最小数字移动 到 index -1 ，然后将 index - 1 到尾处反转。

## [32_递归||动态规划_最长有效括号](./Src/32_LongestValidParentheses/LongestValidParentheses.cpp)

```shell
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"
```

**[递归||动态规划](https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/)**。

DP：有效的子串一定以 `)` 结尾，因此可知以 `(` 结尾的子串对应的 dp 值为 0。我们只需要求解 `)` 在 dp 数组中对应位置的值。我们从前往后遍历字符串求解 dp 值，我们每两个字符检查一次。

栈：可以看题解的动图，好理解。

## [33_二分法_搜索旋转排序数组](./Src/33_SearchInRotatedSortedArray/SearchInRotatedSortedArray.cpp)

```shell
升序排列的整数数组 nums 在预先未知的某个点上进行了旋转（例如， [0,1,2,4,5,6,7] 经旋转后可能变为 [4,5,6,7,0,1,2] ）。

请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
```

**二分法**。

根据中值逐步推进左边界与右边界，找出目标值。

## [34_二分法_在排序数组中查找元素的第一个和最后一个位置](./Src/34_FindFirstAndLastPositionOfElementInSortedArray/FindFirstAndLastPositionOfElementInSortedArray.cpp)

```shell
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
```

**二分法**。

分别查找 Left 和 Right 坐标，其主要区别在于当 `nums[mid] == targe` 中值等于目标时，取范围头还是尾。

注意要点再查找 RightPos 时，取中止应当 `(left + right + 1) >> 1`  ，其中 +1 上取很重要，否则 left = mid 将一直 小于 right 导致死循环。

## [39_回溯_组合总和](./Src/39_CombinationSum/CombinationSum.cpp)

```shell
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
```

**[回溯](https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/)**。

经典回溯使用，DFS 扩展，区别是当返回上一步时会撤销。

## [42_双指针_接雨水](./Src/42_TrappingRainWater/TrappingRainWater.cpp)

```shell
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
```

![42](./Img/42.png)

**[双指针](https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/)**。

与动态分析只依赖单侧 left_max 计算不同，使用双指针可以假设 left_max < right_max，保证了当前指向的位置高度与左侧最高点的差值及为存水量，单次遍历即可完成计算。

## [46_回溯_全排列](./Src/46_Permutations/Permutations.cpp)

```shell
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

**[回溯](https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/)**。

![46](./Img/46.png)

经典回溯用法，配合 39 题食用，主要解决这种无重复、全排列的问题。

## [48_数组例题原地计算_旋转图像](./Src/48_RotateImage/RotateImage.cpp)

```shell
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]
```

![48](./Img/48.jpg)

自己实现方法：

先翻转矩阵，再按照斜对角线翻转：

```bash
{ 1, 2, 3 }      { 7, 8, 9 }      { `7`,  8 ,  9 }      { `7`,  4 ,  1 }
{ 4, 5, 6 }  ->  { 4, 5, 6 }  ->  {  4 , `5`,  6 }  ->  {  8 , `5`,  2 }
{ 7, 8, 9 }      { 1, 2, 3 }      {  1 ,  2 , `3`}      {  9 ,  6 , `3`}
```

[原地计算法](https://leetcode-cn.com/problems/rotate-image/solution/xuan-zhuan-tu-xiang-by-leetcode-solution-vu3m/)。

## [49_哈希或质数相乘_字母异位词分组](./src/../Src/49_GroupAnagrams/GroupAnagrams.cpp)

```shell
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
```

**哈希或质数相乘**。

基础方法就是排序、置入 map 中、map 查对应插入。

本例中使用 哈希 或者 质数相乘 获得每个子串 `ID`，通过 map 查进行分类。
