/*
dp思路
dp[i] = min(dp[1], dp[i / 2] + 2, dp[i / 3] + 3, 4 + dp[i / 4] + 4,..., dp[1] + 1)
*/
class Solution {
    public:
        int minSteps(int n) {
            vector<int> dp(n + 1, INT_MAX);
            dp[0] = 0;
            dp[1] = 0;
            for (int i = 2; i <= n; i++) {
                for (int d = 2; d <= i; d++) {
                    if (i % d == 0) 
                        dp[i] = min(dp[i], dp[i/d] + d);
                }
            }
            return dp[n];
        }
};
