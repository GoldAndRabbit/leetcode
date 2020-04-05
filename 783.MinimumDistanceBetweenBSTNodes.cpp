/*
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

        4
       / \
      2   6
     / \
    1   3

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's value is different.

题意：
求二叉树中两个节点之间的差的最小值
1.将二叉树转为数组然后排序比较
2.中序遍历二叉树，然后维护前一个节点的值
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
    int prev, ans;
    public:
        int minDiffInBST(TreeNode* root) {
            prev = -1;
            ans = INT_MAX;
            dfs(root);
            return ans;
        }
        // 中序遍历二叉树，维护遍历的上个节点
        void dfs(TreeNode* node) {
            if (!node) return;
            dfs(node -> left);
            if (prev != -1)
                ans = min(ans, node -> val - prev);
            prev = node -> val;
            dfs(node -> right);
        }
};

class Solution {
    public:
        vector<int> arr;
        int minDiffInBST(TreeNode* root) {
            int ans = INT_MAX;
            dfs(root);
            sort(arr.begin(), arr.end());
            for (int i = 0; i < arr.size() - 1; ++i)
                ans = min(ans, arr[i + 1] - arr[i]);
            return ans;
        }
        void dfs(TreeNode* node) {
            if (!node) return;
            arr.push_back(node -> val);
            dfs(node -> left);
            dfs(node -> right);
        }
};


