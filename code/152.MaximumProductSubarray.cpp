/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

维护一个到第i个位置的最大乘积和最小乘积
ans = A[0]
curmax = A[0]
curmin = A[0]

if (A[i] < 0)
    swap(curmax, curmin);
curmax = max(curmax * A[i], A[i]);
curmin = min(curmin * A[i], A[i]);

ans = max(ans, curmax);
*/

class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int n = nums.size();
            int ans = nums[0], curmax = nums[0], curmin = nums[0];
            for (int i = 1; i < n; ++i) {
                if (nums[i] < 0)
                    swap(curmax, curmin);
                curmax = max(nums[i], curmax * nums[i]);
                curmin = min(nums[i], curmin * nums[i]);
                ans = max(ans, curmax);
            }
            return ans;
        }
};
