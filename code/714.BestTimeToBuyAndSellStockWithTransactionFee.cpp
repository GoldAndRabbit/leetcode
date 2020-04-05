/*
Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Note:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.

思路

    buy  ---> 

在第i天，
维护一个cash表示手上没有股票的最大利润
维护一个hold表示手上有股票的最大利润
从第i天到i+1天的交易，可以选择两类操作
1.卖掉手上的股票 cash = max(cash, hold + price[i] - fee);
2.买个股票 hold = max(hold, cash - price[i]);
*/

class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
            int len = prices.size();
            if (len < 2) return 0;
            vector<int> sell(len, 0), hold(len, 0);
            hold[0] = -prices[0];
            for (int i = 1; i < prices.size(); ++i) {
                sell[i] = max(sell[i - 1], hold[i - 1] + prices[i] - fee);
                hold[i] = max(hold[i - 1], sell[i - 1] - prices[i]);
            }
            return sell[len - 1];
        }
};
