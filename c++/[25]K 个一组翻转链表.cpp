//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。 
//
// k 是一个正整数，它的值小于或等于链表的长度。 
//
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。 
//
// 
//
// 示例： 
//
// 给你这个链表：1->2->3->4->5 
//
// 当 k = 2 时，应当返回: 2->1->4->3->5 
//
// 当 k = 3 时，应当返回: 3->2->1->4->5 
//
// 
//
// 说明： 
//
// 
// 你的算法只能使用常数的额外空间。 
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 
// 
// Related Topics 链表 
// 👍 758 👎 0


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* result = new ListNode(-1);
        result->next = head;
        ListNode* index = result;
        ListNode* tail = findKthNode(index, k);
        while (tail != nullptr){
            ListNode* prev = tail->next;
            ListNode* temp = head;
            for (int i = 0; i < k; i++){
                ListNode* nextTemp = head->next;
                head->next = prev;
                prev = head;
                head = nextTemp;
            }
            index->next = prev;
            index = temp;
            tail = findKthNode(index, k);
        }
        return result->next;
    }

    ListNode* findKthNode(ListNode* index, const int& k){
        for (int i=0; i < k; i++) {
            index = index->next;
            if (index == nullptr)
                return nullptr;
        }
        return index;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
