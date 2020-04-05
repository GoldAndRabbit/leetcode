/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?

tree pointers
recursive way
*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
    public:
 		// three pointers version
        ListNode* reverseList(ListNode* head) {
            ListNode* pre = NULL;
            ListNode* cur = head;
            while (cur) {
                ListNode* next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            return pre;
        }
        // recursive version
        ListNode* reverseList(ListNode* head) {
            if (!head || !head->next) return head;
            ListNode* newHead = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return newHead;
        }
};
