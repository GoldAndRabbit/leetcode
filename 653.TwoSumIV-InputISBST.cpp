/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
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
    vector<int> arr;
    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node -> left);
        arr.push_back(node -> val);
        dfs(node -> right);
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int start = 0, end = arr.size() - 1;
        while (start < end) {
            if (arr[start] + arr[end] == k) return true;
            else if (arr[start] + arr[end] < k) ++start;
            else --end;
        }
        return false;
    }
};

