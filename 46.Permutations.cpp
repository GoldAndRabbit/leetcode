/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

思路从第一个元素的位置开始
递归回溯
*/

class Solution {
public:
    void dfs(int pos, vector<int>& nums, vector<vector<int>>& ans) {
        if (pos == nums.size()) ans.push_back(nums);
        for (int i = pos; i < nums.size(); ++i) {
            swap(nums[pos], nums[i]);
            dfs(pos + 1, nums, ans);
            swap(nums[i], nums[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        dfs(0, nums, ans);
        return ans;
    }
};
