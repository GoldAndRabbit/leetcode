/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:
Input: [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Example 2:
Input: [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
*/

class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            vector<string> ans;
            string s = "";
            int i = 0, len = nums.size();
            while (i < len) {
                int start = i, end = i;
                while (end + 1 < len && nums[end + 1] == nums[end] + 1) ++end;
                if (end > start) ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
                else ans.push_back(to_string(nums[start]));
                i = end + 1;
            }
            return ans;
        }
};