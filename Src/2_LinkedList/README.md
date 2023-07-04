# 链表

1. [0203\_移除链表元素](https://leetcode.cn/problems/remove-linked-list-elements/)--[code](./0203_RemoveLinkedListElements.cpp):

   给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

   ![sample](https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg)

   ```text
   列表中的节点数目在范围 [0, 104] 内
   1 <= Node.val <= 50
   0 <= val <= 50
   ----------------------------------------
   输入：head = [1,2,6,3,4,5,6], val = 6
   输出：[1,2,3,4,5]
   ----------------------------------------
   输入：head = [], val = 1
   输出：[]
   ----------------------------------------
   输入：head = [7,7,7,7], val = 7
   输出：[]
   ```

   - 解题思路：链表操作的方式：1. 直接使用原来的链表进行删除操作。2. 设置一个虚拟头节点在进行删除。
     - 这两个操作方式的区别在于，是否需要对头节点进行特殊处理，第一种需要特殊处理头节点，而第二种则不需要。

2. [0707\_设置链表](https://leetcode.cn/problems/design-linked-list/)--[code](./0707_DesignLinkedList.cpp):

   单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。

   如果是双向链表，则还需要属性  prev  以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

   - 解题思路：本体纯锻炼对于链表实现与操作的技巧。

3. [0206\_反转链表](https://leetcode.cn/problems/reverse-linked-list/)--[code](./0206_ReverseLinkedList.cpp):

   示例: 输入: 1->2->3->4->5->NULL 输出: 5->4->3->2->1->NULL

   - 解题思路：通过双指针改变链表每个节点的指向，从指向后一个改为指向前一个节点即可完成翻转而不需要重新建立链表。

   ![sample](https://code-thinking.cdn.bcebos.com/gifs/206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.gif)
