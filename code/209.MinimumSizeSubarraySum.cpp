/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

找到长度最小的子数组，使得子数组之和大于等于s

维护一个right和left指针
right向后移动，并且求和
如果超出sum那么left向后移动
*/

class Solution {
    public:
        int minSubArrayLen(int s, vector<int>& nums) {
            int len = nums.size() - 1;
            int left = 0;
            int sum = 0, ans = len + 1;
            for (int i = 0; i < len; ++i) {
                sum += nums[i];
                while (sum >= s) {
                    ans = min(ans, i - left + 1);
                    sum -= nums[left];
                    ++left;
                }
            }
            return ans;
        }
};
