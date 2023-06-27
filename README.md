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

## [数组](./Src/1_Array/)

1. 二分法：循环不变量原则，只有在循环中坚持对区间的定义，才能清楚的把握循环中的各种细节。
2. 双指针法：通过一个快指针和慢指针在一个 for 循环下完成两个 for 循环的工作。双指针法（快慢指针法）在数组和链表的操作中是非常常见的。
3. 滑动窗口：滑动窗口的精妙之处在于根据当前子序列和大小的情况，不断调节子序列的起始位置。从而将 O(n^2)的暴力解法降为 O(n)。
4. 模拟行为：真正解决题目的代码都是简洁的，或者有原则性的。

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
