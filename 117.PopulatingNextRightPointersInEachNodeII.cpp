/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
        1
       /  \
      2   3
     / \    \
    4   5   7
After calling your function, the tree should look like:
        1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

在每行子孩子加一个dummy
*/

/**
 ** Definition for binary tree with next pointer.
 ** struct TreeLinkNode {
 **  int val;
 **  TreeLinkNode *left, *right, *next;
 **  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 ** };
 **/

class Solution {
    public:
        void connect(TreeLinkNode *root) {
            while (root) {
                TreeLinkNode* dummy = new TreeLinkNode(0);
                TreeLinkNode* cur = dummy;
                while (root) {
                    if (root->left) {
                        cur->next = root->left;
                        cur = cur->next;
                    }
                    if (root->right) {
                        cur->next = root->right;
                        cur = cur->next;
                    }
                    root = root->next;
                }
                root = dummy->next;
            }
        }
};
