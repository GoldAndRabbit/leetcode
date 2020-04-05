/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */

/*
注意这道题不能贪心比如说
[1, 3, 5, 6] amount = 8
用动态规划
dp[i]代表amount == i时候最小的coinChange
dp[i] = min(dp[i], dp[i - coins[j]] + 1);
初始化需要将最所有的状态弄成较大的数字比如INT_MAX
或者用amout+1比较合理
最后需要进行比较
return dp[amount] <= amount ? dp[amount]:-1;
因为极端的情况
[2] 1
既没有发生任何变化。
coinchange必须 <= amount才合法
初始化dp[0] = 1, 必须从0开始记录
 */

class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            vector<int> dp(amount + 1, amount + 1);
            dp[0] = 0;
            for (int i = 1; i <= amount; i++) {
                for (int j = 0; j < coins.size(); j++) {
                    // 合法状态发生在coin[j] <= i的情况下
                    if (coins[j] <= i) {
                        // 放入和不放入的两种情况
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }
            return dp[amount] <= amount ? dp[amount] : -1;
        }
};
