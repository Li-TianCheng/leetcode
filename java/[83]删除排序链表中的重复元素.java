//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。 
//
// 示例 1: 
//
// 输入: 1->1->2
//输出: 1->2
// 
//
// 示例 2: 
//
// 输入: 1->1->2->3->3
//输出: 1->2->3 
// Related Topics 链表 
// 👍 413 👎 0


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
        if (head == null || head.next == null)
            return head;
        ListNode newHead = new ListNode();
        ListNode tail = newHead;
        ListNode temp = head;
        while (temp.next != null) {
            if (temp.val != temp.next.val) {
                tail.next = temp;
                tail = tail.next;
            }
            temp = temp.next;
        }
        tail.next = temp;
        return newHead.next;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
