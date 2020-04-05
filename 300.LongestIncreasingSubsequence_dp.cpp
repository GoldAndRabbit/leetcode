/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?


n^2复杂度dp
dp[i]表示以i为index的最长上升子序列
对于0 < j < i, dp[i] = max(dp[i], dp[j] + 1);

nlngn复杂度dp 这种方法无法得到的数组并不是一个原数组的最长上升子序列
维护单调递增的数组dp因为之前的最长上升子序列是单调递增的
dp初始为空
如果当前元素nums[i]大于dp最大值
那么就加入数组
否则
nums[i]替换dp中第一个不小于它的数字,查找的时候用二分查找
 */

// O(n^2)
class Solution {
    public:
        int lenthOfLIS(vector<int>& nums) {
            if (nums.empty())
                return 0;
            vector<int> dp(nums.size(), 1);
            int ans = 1;
            for (int i = 0; i < nums.size(); i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[j] < nums[i])
                        dp[i] = max(dp[i], dp[j] + 1);
                }
                ans = max(dp[i], ans);
            }
            return ans;
        }
};


// O(nlgn)
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            if (nums.empty())
                return 0;
            vector<int> up{nums[0]};
            for (int i = 1; i < nums.size(); i++) {
                // 如果比最后一个大, 那么直接加入
                if (nums[i] > up.back()) {
                    up.push_back(nums[i]);
                } else { // 否则二分查找第一个不小于nums[i]的
                    int l = 0, r = up.size() - 1;
                    while (l < r) {
                        int m = l + (r - l) / 2;
                        if (up[m] >= nums[i])
                            r = m;
                        else
                            l = m + 1;
                    }
                    up[l] = nums[i];
                }
            }
            return upd.size();
        }
};
