/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

一次lower_bound,一次upper_bound,第二次可以接着上一次来二分
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if (nums.empty()) return ans;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) l = m + 1;
            else r = m;
        }
        if (nums[r] != target)  return ans;
        ans[0] = r;
        r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target) l = m + 1;
            else r = m;
        }
        ans[1] = l - 1;
        return ans;
    }
};
