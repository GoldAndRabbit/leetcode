/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

阶乘中5的个数
只需要求出n中5的个数
可以写一个牛逼的递归写法
*/


class Solution {
    public:
        int trailingZeroes(int n) {
            int ans = 0;
            while (n) {
                ans += n / 5;
                n /= 5;
            }
            return ans;
        }
};

class Solution {
    public:
        int trailingZeroes(int n) {
            return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
        }
};
