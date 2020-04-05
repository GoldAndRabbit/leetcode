/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

相比于第一题,第二题可以进行多次交易,在同一天不能发生多个交易.
遍历prices, 如果第二天大于第一天那么就累加二者之差
*/

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int ans = 0;
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] - prices[i - 1] > 0) {
                    ans += prices[i] - prices[i - 1];
                }
            }
            return ans;
        }
};
