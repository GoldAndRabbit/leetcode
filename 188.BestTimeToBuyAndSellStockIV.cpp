/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

这个题是2，3题的结合。
k如果大于等于len,那么就是第二题
*/
class Solution {
    public:
        int getMax(vector<int>& prices, int len) {
            int ans = 0;
            for (int i = 1; i < len; ++i) {
                if (prices[i] - prices[i - 1] > 0)
                    ans += prices[i] - prices[i - 1];
            };
            return ans;
        }
        int maxProfit(int k, vector<int>& prices) {
            int len = prices.size();
            if (len < 1) return 0;
            if (k >= len) return getMax(prices, len);
            vector<vector<int> > local(len, vector<int>(k + 1, 0));
            vector<vector<int> > global(len, vector<int>(k + 1, 0));
            int diff;
            for (int i = 1; i < len; ++i) {
                diff = prices[i] - prices[i - 1];
                for(int j = 1; j <= k; ++j) {
                    local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff);
                    global[i][j] = max(global[i - 1][j], local[i][j]);
                }
            }
            return global[len - 1][k];
        }
};


