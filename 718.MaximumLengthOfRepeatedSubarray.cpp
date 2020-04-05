/*
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation:
The repeated subarray with maximum length is [3, 2, 1].
Note:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100

返回两个数组公共最长子数组长度
用dp[i][j]表示A[:i]和B[:j]的公共最长子数组长度
if A[i - 1] == B[j - 1]:
    dp[i][j] = dp[i - 1][j - 1] + 1
*/

class Solution {
    public:
        int findLength(vector<int>& A, vector<int>& B) {
            if (A.empty() || B.empty()) return 0;
            int ans = 0;
            vector<vector<int> > dp(A.size() + 1, vector<int>(B.size() + 1, 0));
            for (int i = 1; i <= A.size(); ++i) {
                for (int j = 1; j <= B.size(); ++j) {
                    if (A[i - 1] == B[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                        ans = max(ans, dp[i][j]);
                    }
                }
            }
            return ans;
        }
};
