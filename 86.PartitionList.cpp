/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

给定一个数x，小于x的数排在第x之前
两个dummy,两个cur
遍历链表，比较连接，
最后把cur2->next = NULL
避免链表有环
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* cur1 = dummy1;
        ListNode* cur2 = dummy2;
        ListNode* p = head;
        while (p) {
            if (p->val < x) {
                cur1->next = p;
                cur1 = cur1->next;
            } else {
                cur2->next = p;
                cur2 = cur2->next;
            }
            p = p->next;
        }
        cur2->next = NULL;
        cur1->next = dummy2->next;
        return dummy1->next;
    }
};
