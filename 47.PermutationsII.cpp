/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

class Solution {
    public:
        void dfs(int pos, vector<int> nums, vector<vector<int>>& ans) {
            if (pos == nums.size()) ans.push_back(nums);
            for (int i = pos; i < nums.size(); ++i) {
                if (i != pos && nums[pos] == nums[i]) continue;
                swap(nums[pos], nums[i]);
                dfs(pos + 1, nums, ans);
            }
        }
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int> > ans;
            sort(nums.begin(), nums.end());
            dfs(0, nums, ans);
            return ans;
        }
};
