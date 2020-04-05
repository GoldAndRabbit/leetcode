/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
    int ans;
    int arrowSum(TreeNode* node) {
        if (!node) return 0;
        int l = max(0, arrowSum(node->left));
        int r = max(0, arrowSum(node->right));
        ans = max(ans, node->val + l + r);
        return max(l, r) + node->val;
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        arrowSum(root);
        return ans;
    }
};
