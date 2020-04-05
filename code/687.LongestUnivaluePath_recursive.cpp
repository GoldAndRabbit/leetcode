/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
题意
求二叉树中由相同值构成路径最长路径长度，可以不包括根节点
路径长度：两个节点中间的边的个数
第一图片中的555
第二图片中的444

recursive:
递归求当前节点的最长等值路径长度
算出左孩子节点。
如果根节点等于左孩子节点那么就是左边这一侧的当前长度+1
算出右边孩子节点。
如果根节点等于右侧孩子节点那么就是右边这一测的当前长度+1
ans = max(ans, left+right)

tmpLeft = getPath(node -> left);
tmpRight = getPath(node -> right);

int leftPath = 0, rightPath = 0;
if left != nullptr && node -> left -> val == node -> val:
    left = tmpLeft + 1;
if right != nullptr &&  node -> right -> val == node -> val:
    right = tmpRight + 1;
ans = max(ans, left, right)
return max(left, right)
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
        int arrowLength(TreeNode* node) {
            if (!node) return 0;
            int tmpL = arrowLength(node->left);
            int tmpR = arrowLength(node->right);
            int l = 0, r = 0;
            if (node->left && node->left->val == node->val) l = tmpL + 1;
            if (node->right && node->right->val == node->val) r = tmpR + 1;
            ans = max(ans, l + r);
            return max(l, r);
        }
        int longestUnivaluePath(TreeNode* root) {
            ans = 0;
            arrowLength(root);
            return ans;
        }
};
