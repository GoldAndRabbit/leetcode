/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.

只能买一次
找到最高峰和最低谷
维护一个最低谷
维护一个之差
O(n)扫
*/

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int minPrice = INT_MAX;
            int ans = 0;
            for (auto x : prices) {
                if (x < minPrice)
                    minPrice = x;
                else if (x - minPrice > ans)
                    ans = x - minPrice;
            }
            return ans;
        }
};
