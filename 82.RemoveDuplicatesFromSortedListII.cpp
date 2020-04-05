/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode* dummy = new ListNode(-1);
            dummy->next = head;
            ListNode* cur = dummy;
            int repeat;
            while (cur->next && cur->next->next) {
                if (cur->next->val == cur->next->next->val) {
                    repeat = cur->next->val;
                    while (cur->next && cur->next->val == repeat) {
                        cur->next = cur->next->next;
                    }
                } else {
                    cur = cur->next;
                }
            }
            return dummy->next;
        }
};
