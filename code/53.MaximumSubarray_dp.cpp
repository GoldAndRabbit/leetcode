/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

dp[i]表示以i为结尾的最大子数组和
dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0)
*/

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            if (nums.empty())
                return 0;
            int dp[nums.size()]; // dp[i]表示以i为结尾的最大子数组和
            dp[0] = nums[0];
            int ans = nums[0];
            for (int i = 1; i < num.size(); i++) {
                dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
                ans = max(ans, dp[i]);
            }
            return max;
        }
};

// O(1)复杂度优化
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int sum = nums[0];
            int ans = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                sum = nums[i] + (sum > 0 ? sum : 0);
                ans = max(ans, sum);
            }
            return ans;
        }
};
