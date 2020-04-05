/*
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input:
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input:
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.

一种二叉树
每个节点要么没有孩子，要么有两个孩子
如果由两个孩子，该节点的值比两个孩子节点的值小
求最第二小的节点, 如果没有，那么输出-1
思路：
firstMin < ans < 其他任何值
dfs 当前节点
if firstMin < node -> val 同时 node -> val < ans:
    ans = node -> val
elif firstMin == node -> val:
    dfs(node -> left)
    dfs(node -> right)
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
**/

class Solution {
    public:
        int firstMin;
        int ans;
        void dfs(TreeNode* node) {
            if (node) {
                if (firstMin < node -> val && node -> val < ans)
                    ans = node -> val;
                else if (firstMin == node -> val) {
                    dfs(node -> left);
                    dfs(node -> right);
                }
            }
        }
        int findSecondMinimumValue(TreeNode* root) {
            firstMin = root -> val;
            ans = INT_MAX;
            dfs(root);
            return ans < INT_MAX ? ans : -1;
        }
};
