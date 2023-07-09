# 字符串

1. [0344\_反转字符串](https://leetcode.cn/problems/reverse-string/description/)--[code](./0344_ReverseString.cpp):

   编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

   不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

   ```text
   输入：s = ["h","e","l","l","o"]
   输出：["o","l","l","e","h"]

   ----------------------------------

   输入：s = ["H","a","n","n","a","h"]
   输出：["h","a","n","n","a","H"]
   ```

   - 解题思路：双指针，没啥特殊的。

     ![sampel](https://code-thinking.cdn.bcebos.com/gifs/344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.gif)

2. [0541\_反转字符串 II](https://leetcode.cn/problems/reverse-string-ii/)--[code](./0541_ReverseStringII.cpp):

   给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

   - 如果剩余字符少于 k 个，则将剩余字符全部反转。
   - 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

   ```test
   输入：s = "abcdefg", k = 2
   输出："bacdfeg"

   ------------------------------------

   输入：s = "abcd", k = 2
   输出："bacd"
   ```

   - 解题思路：技巧是在遍历过程中步长可以设定为 2 \* k，这样只需要处理每次前进的字符串不需要单独记录字符数量。

3. [剑指*05*替换空格](https://leetcode.cn/problems/ti-huan-kong-ge-lcof/)--[code](./ZJ05_ReplaceSpace.cpp):

   请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

   ```text
   输入：s = "We are happy."
   输出："We%20are%20happy."
   ```

   - 解题思路：这道题重点在于要从后向前进行替换，可以有效避免多余的内存拷贝否则时间复杂度将 On 变为 On^2。

   ![sample](https://code-thinking.cdn.bcebos.com/gifs/%E6%9B%BF%E6%8D%A2%E7%A9%BA%E6%A0%BC.gif)
