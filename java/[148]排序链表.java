//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。 
//
// 进阶： 
//
// 
// 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [4,2,1,3]
//输出：[1,2,3,4]
// 
//
// 示例 2： 
//
// 
//输入：head = [-1,5,3,4,0]
//输出：[-1,0,3,4,5]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 5 * 104] 内 
// -105 <= Node.val <= 105 
// 
// Related Topics 排序 链表 
// 👍 913 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        return head == null ? null :helper(head);
    }

    private ListNode helper(ListNode node) {
        if (node.next == null){
            return node;
        }
        ListNode slow = node;
        ListNode fast = node;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode l1 = node;
        ListNode l2 = slow.next;
        slow.next = null;
        return merge(helper(l1), helper(l2));
    }

    private ListNode merge(ListNode l1, ListNode l2){
        ListNode dummy = new ListNode(0);
        ListNode temp = dummy;
        while(l1 != null && l2 != null){
            if (l1.val > l2.val){
                temp.next = l2;
                l2 = l2.next;
            }else{
                temp.next = l1;
                l1 = l1.next;
            }
            temp = temp.next;
        }
        if (l1 != null){
            temp.next = l1;
        }
        if (l2 != null){
            temp.next = l2;
        }
        return dummy.next;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
