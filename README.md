# LeetCode 算法刷题


## [01_TwoSum](./Src/01_TwoSum/TwoSum.cpp)

```shell
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

使用 map 记录以检查的已出现的数字和对应下标 `pair(num, index)`。
类似桶查找，直到找到与当前数组匹配的另一个数字 `Target - Num[i]`，然后返回下标。

## [02_AddTwoNumbers](./Src/02_AddTwoNumbers/AddTwoNumbers.cpp)

```shell
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
```

相加两个链表中位置对应的元素，当超过 10 时，取余进位。通过 while 循环遍历两个链表所有的元素，最终返回相加完成后的链表。

## [03_LongestSubstringWithoutRepeatingCharacters](./Src/03_LongestSubstringWithoutRepeatingCharacters/LongestSubstringWithoutRepeatingCharacters.cpp)

```shell
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

滑动窗口算法。
整个循环从 l == 0; r == -1 这个空窗口开始，维护一个 res 最长的长度，通过循环遍历判断当前窗口中是否有相同的字符 (这一步判断使用桶方法)。
如果检查当前字符没有出现，则 r ++，增加字符到桶中， 更新 res 长度。整体窗口向右生长。
如果检查当前字符出现过，则 先从桶中删除 l 当前所在的字符，l ++ 向右滑动，判断是否需要更新 res 长度。整体窗口向右缩减。

当遍历所有字符完成得到一个最长的长度。

## [04_MedianofTwoSortedArrays](./Src/04_MedianofTwoSortedArrays/MedianofTwoSortedArrays.cpp)

```shell
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
-----------
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
```

二分法进行裁剪。
其实 insert + sort 也挺香的 `:)`。

## [05_LongestPalindromicSubstring](./Src/05_LongestPalindromicSubstring/LongestPalindromicSubstring.cpp)

```shell
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
```

回文有两种情况 aba 和 abba，需要考虑两种不同的中间点。
解决方案是遍历整个字符串，已每个`当前字符`和`当前字符 + 1` 为中心点，向两边扩展比对，直到 left != right 返回此时 left 和 right 的下标，最终保存一个最长的，然后使用 substr 截取子串返回。

## [10_RegularExpressionMatching](./Src/10_RegularExpressionMatching/RegularExpressionMatching.cpp)

```shell
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素


输入：s = "aa" p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。
```

动态规划
