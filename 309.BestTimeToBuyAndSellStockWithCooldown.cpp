/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]

基于之前的题目
多了一条规则
如果卖完了一个股票，第二天接着一个休市，休市不能买

    rest
  s0 -- s2
 buy\  /sell
     s1

s0 means the state that "one has no holdings"
s1 means the state that "one has holdings"
s2 means the state that “one has sold has holdings” - s2 is different from s0 because of the cooldown. after the cooldown s2 can return to s0.


s0[i] = max(s0[i - 1, s2[i - 1])
s1[i] = max(s0[i - 1, s0[i - 1] - price[i])
s2[i] = s1[i - 1] + price[i]

s0[0] = 0;
s1[0] = -price[0];
s2[0] = INT_MIN;
*/

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.size() <= 1) return 0;
            vector<int> s0(price.size(), 0);
            vector<int> s1(price.size(), 0);
            vector<int> s2(price.size(), 0);
            s0[0] = 0;
            s1[0] = -prices[0];
            s2[0] = INT_MIN;
            for (int i = 1; i < prices.size(); ++i) {
                s0[i] = max(s0[i - 1], s2[i - 1]);
                s1[i] = max(s1[i - 1], s0[i - 1] - price[i]);
                s2[i] = s1[i - 1] + price[i];
            }
            return max(s0[prices.size() - 1], s2[prices.size() - 1]);
        }
};
