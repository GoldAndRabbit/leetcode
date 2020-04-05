/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

推广到最多交易k次的最大收益

http://blog.csdn.net/fightforyourdream/article/details/14503469

local[i][j]表示第i天，最多j次交易，且最后一天发生交易的最大利润
global[i][j]表示第i天，最多j次交易的最大利润

local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff);
global[i][j] = max(global[i - 1][j], local[i][j]);
*/


class Solution {
    public:
        int helper(vector<int>& prices, int k) {
            int len = prices.size();
            if (len < 1) return 0;
            vector<vector<int> > local(len, vector<int>(k + 1, 0);
            vector<vector<int> > global(len, vector<int>(k + 1, 0);
            int diff;
            for (int i = 1; i < len; ++i) {
                diff = prices[i] - prices[i - 1];
                for (int j = 1; j < k; ++j) {
                    local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff);
                    global[i][j] = max(global[i - 1][j], local[i][j]);
                }
            }
            return global[len - 1][k];
        }
        int maxProfit(vector<int>& prices) {
            return helper(price, 2);
        }
};
