/*
Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root node is at depth 1.

The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, create two tree nodes with value v as N's left subtree root and right subtree root. And N's original left subtree should be the left subtree of the new left subtree root, its original right subtree should be the right subtree of the new right subtree root. If depth d is 1 that means there is no depth d-1 at all, then create a tree node with value v as the new root of the whole original tree, and the original tree is the new root's left subtree.

Example 1:
Input:
A binary tree as following:
       4
     /   \
    2     6
   / \   /
  3   1 5

v = 1

d = 2

Output:
       4
      / \
     1   1
    /     \
   2       6
  / \     /
 3   1   5

Example 2:
Input:
A binary tree as following:
      4
     /
    2
   / \
  3   1

v = 1

d = 3

Output:
      4
     /
    2
   / \
  1   1
 /     \
3       1
Note:
The given d is in range [1, maximum depth of the given tree + 1].
The given binary tree has at least one tree node.

思路：插入到d行，必须先搜索到第n = d - 1行再进行操作
学习递归写法
对d - 1行之前
递归调用
helper(root->left, d + 1, v, n)
helper(root->right, d + 1, v, n)
还有个特殊情况d == 1单独处理
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
        void helper(TreeNode* p, int h, int v, int d) {
            if (!p) return;
            if (h == d - 1) {
                TreeNode* t = p->left;
                p->left = new TreeNode(v);
                p->left->left = t;
                t = p->right;
                p->right = new TreeNode(v);
                p->right->right = t;
            } else {
                helper(p->left, h + 1, v, d);
                helper(p->right, h + 1, v, d);
            }
        }
        TreeNode* addOneRow(TreeNode* root, int v, int d) {
            if (d == 1) {
                TreeNode* newRoot = new TreeNode(v);
                newRoot->left = root;
                return newRoot;
            }
            helper(root, 1, v, d);
            return root;
        }
};

