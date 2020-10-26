//反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。 
//
// 说明: 
//1 ≤ m ≤ n ≤ 链表长度。 
//
// 示例: 
//
// 输入: 1->2->3->4->5->NULL, m = 2, n = 4
//输出: 1->4->3->2->5->NULL 
// Related Topics 链表 
// 👍 558 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* newHead = new ListNode();
        newHead->next = head;
        ListNode* curr = newHead;
        int count = 0;
        ListNode* tem1 = newHead;
        ListNode* tem2 = newHead->next;
        ListNode* tem3 = newHead;
        ListNode* tem4 = newHead->next;
        while (curr != NULL) {
            count++;
            if (count == m) {
                tem1 = curr;
                tem2 = curr->next;
            }
            if (count == n+1){
                tem3 = curr;
                tem4 = curr->next;
                curr = tem2->next;
                ListNode* prev = tem2;
                while (curr != tem4) {
                    ListNode* temp = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = temp;
                }
                break;
            }
            curr = curr->next;
        }
        tem1->next = tem3;
        tem2->next = tem4;
        return newHead->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
