# 哈希表

1. [0242\_有效的字母异位词](https://leetcode.cn/problems/valid-anagram/)--[code](./0242_ValidAnagram.cpp):

   给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

   示例 1: 输入: s = "anagram", t = "nagaram" 输出: true

   示例 2: 输入: s = "rat", t = "car" 输出: false

   说明: 你可以假设字符串只包含小写字母。

   - 解题思路：题目只有小写字母，可以定义一个数组使用桶方法记录出现过的字母，对比字符串删除出现过的字母，最后比对桶是否为空即可知道字母是否都相同。

   ![sample](https://code-thinking.cdn.bcebos.com/gifs/242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.gif)

2. [0349\_两个数组的交集](https://leetcode.cn/problems/intersection-of-two-arrays/)--[code](./0349_IntersectionOfTwoArrays.cpp):

   给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

   ```text
   1 <= nums1.length, nums2.length <= 1000
   0 <= nums1[i], nums2[i] <= 1000

   -----------------------------

   输入：nums1 = [1,2,2,1], nums2 = [2,2]
   输出：[2]

   -----------------------------

   输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
   输出：[9,4]
   解释：[4,9] 也是可通过的
   ```

   - 解题思路：由于限制了数组内数组大小，可以尝试用桶数组进行，也可以使用 unordered_set 去重。
