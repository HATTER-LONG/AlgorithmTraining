# LeetCode 算法刷题

<!-- PROJECT SHIELDS -->
![Contributors][build-url]
[![Contributors][contributors-shield]][contributors-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
<!--[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url] 
[![LinkedIn][linkedin-shield]][linkedin-url]-->

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

定义一个快指针，随着循环遍历所有节点，另一个慢指针定位在快指针后 n 个的目标位置，找到后将慢指针后一个节点删除即可。

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
