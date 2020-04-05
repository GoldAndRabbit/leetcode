/*
Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
*/


class Solution {
    public:
        int findNumberOfLIS(vector<int>& nums) {
            if (nums.empty())
                return 0;
            int n = nums.size();
            int maxLen = 1;
            // len数组保存结尾为i的lcs
            vector<int> len(n, 1);
            // cnt数组保存结尾为i的lcs数量
            vector<int> cnt(n, 1);
            for (int i = 0; i < nums.size(); i++) {
                for (int j = 0; j < i; j++) {
                    // 合法情况是nums[j] < nums[i]
                    if (nums[j] < nums[i]) {
                        // 如果len[j] + 1 等于 len[i]
                        // 那么cnt[i]直接累加
                        if (len[j] + 1 == len[i]) {
                            cnt[i] += cnt[j];
                        // 另外len[j] + 1 > len[i] 那么
                        // 更新len[i]为 len[j] + 1
                        // 更新cnt[i] = cnt[j]
                        } else if (len[j] + 1 > len[i]) {
                            len[i] = len[j] + 1;
                            cnt[i] = cnt[j];
                        }
                    }
                }
                // 保存一个最长上升子序列的长度
                maxLen = max(maxLen, len[i]);
            }
            // 重新遍历len数组, 累加cnt
            int ans = 0;
            for (int i = 0; i < len.size(); i++) {
                if (maxLen == len[i]) {
                    ans += cnt[i];
                }
            }
            return ans;
        }
};
