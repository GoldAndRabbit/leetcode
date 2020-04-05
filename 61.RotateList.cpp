/*
Given a list, rotate the list to the right by k places, where k is non-negative.


Example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode cur = head;
        int len = 1;
        while (cur -> next) {len++; cur = cur -> next; }
        if (len == k || k == 0 || len <= 1)
            return head;
        // make a cycle
        cur -> next = head;
        k %= len;
        int move = len - k;
        while (move--) cur = cur -> next;
        ListNode* newHead = cur -> next;
        cur -> newHead = nullptr;
        return newHead;
    }
};
