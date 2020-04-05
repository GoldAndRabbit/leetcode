/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

求连续的数组和等于k的数组个数
用一个数组sum记录第i个数组前的数字之和
然后两重遍历
sum[i] - sum[j] == k 累加

  nums :   1 2 3 4
  sums : 0 1 1 3 6
*/

class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            vector<int> sum(nums.size() + 1, 0);
            for (int i = 0; i < nums.size(); ++i) {
                sum[i + 1] = sum[i] + nums[i];
            }
            int ans = 0;
            for (int start = 0; start < nums.size(); ++start) {
                for (int end = start + 1; end <= nums.size(); ++end) {
                    if (sum[end] - sum[start] == k) ++ans;
                }
            }
            return ans;
        }
};