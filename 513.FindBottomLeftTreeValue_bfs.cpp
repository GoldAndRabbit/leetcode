/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.

思路：
right-to-left bfs
从右到左层序遍历二叉树，
在入队时，先插入右节点，再插入左边的节点
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        while (!q.empty()) {
            root = q.front();
            ans = root -> val;
            q.pop();
            if (root -> right != nullptr)
                q.push(root -> right);
            if (root -> left != nullptr)
                q.push(root -> left);
        }
        return ans;
    }
};

