//给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。 
//
// 示例 1: 
//
// 输入: 1->2->3->3->4->4->5
//输出: 1->2->5
// 
//
// 示例 2: 
//
// 输入: 1->1->1->2->3
//输出: 2->3 
// Related Topics 链表 
// 👍 384 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null)
            return head;
        ListNode newHead = new ListNode(Integer.MAX_VALUE);
        ListNode tail = newHead;
        ListNode temp = head;
        ListNode prev = new ListNode(Integer.MAX_VALUE);
        prev.next = head;
        while (temp.next != null) {
            if (temp.val != prev.val && temp.val != temp.next.val) {
                tail.next = temp;
                tail = tail.next;
            }
            temp = temp.next;
            prev = prev.next;
        }
        if (temp.val != prev.val)
            tail.next = temp;
        else
            tail.next = null;
        return newHead.next;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
