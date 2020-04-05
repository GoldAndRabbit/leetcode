/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

完全二叉树，如果是满二叉树那么是2 ^ height - 1个节点
如果不是满二叉树, 那么就是countNodes(root -> left) + countNodes(root -> right) + 1
*/

/**
 ** Definition for a binary tree node.
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ** };
 **/

class Solution {
    public:
        int getLeftHeight(TreeNode* root) {
            if (!root) return 0;
            return 1 + getLeftHeight(root -> left);
        }

        int getRightHeight(TreeNode* root) {
            if (!root) return 0;
            return 1 + getRightHeight(root -> right);
        }

        int countNodes(TreeNode* root) {
            int leftH = getLeftHeight(root);
            int rightH = getRightHeight(root);
            return leftH == rightH ? pow(2, leftH) - 1 : countNodes(root -> left) + countNodes(root -> right) + 1;
        }
};