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

4. [0151\_反转字符串中的单词](https://leetcode.cn/problems/reverse-words-in-a-string/)--[code](./0151_ReverseWordsInAString.cpp):

   给你一个字符串 s ，请你反转字符串中 单词 的顺序。

   单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

   返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

   注意：输入字符串 s 中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

   ```text
   输入：s = "the sky is blue"
   输出："blue is sky the"

   -----------------------------

   输入：s = "  hello world  "
   输出："world hello"
   解释：反转后的字符串中不能存在前导空格和尾随空格。

   -----------------------------

   输入：s = "a good   example"
   输出："example good a"
   解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
   ```

   - 解题思路：整体步骤如下：

   1. 多余空格去重，采用双指针方法，快指针跳过所有空格，慢指针拷贝有效单词并补上间隔空格；
   2. 反转整个空格去重后的字符串，在快慢指针单独反转所有空格分割的单词。
