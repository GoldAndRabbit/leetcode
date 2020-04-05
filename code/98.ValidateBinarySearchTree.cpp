/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.

中序遍历二叉树，维护一个pre指向前一个节点
中序遍历使用stack实现
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            if (!root) return true;
            stack<TreeNode*> s;
            TreeNode* p = root;
            TreeNode* pre = NULL;
            while (p || !s.empty()) {
                while (p) {
                    s.push(p);
                    p = p->left;
                }
                TreeNode* t = s.top(); s.pop();
                if (pre && t->val <= pre->val) return false;
                pre = t;
                p = t->right;
            }
            return true;
        }
};