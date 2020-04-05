/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

实现除法不能用乘法、除法或者取模。如果溢出返回MAX_INT;
int cnt = 0;
while (dividend > divisor) {
    dividend -= divisor;
    ++cnt;
}
cnt 就是所求的结果

24 / 4
24 20 16 12 8 4 0

dividend每次减去2^n倍数的divisor, 相当于count每次加上1 << 2 ^ N
*/

class Solution {
    public:
        int divide(int dividend, int divisor) {
            if ((divisor == 0) || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
            long long m = abs((long long) dividend), n = abs((long long) divisor);
            int sign = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) ? 1 : -1;
            long long ans = 0;
            while (m >= n) {
                long long t = n, cnt = 1;
                while (m >= (t << 1)) {
                    t <<= 1;
                    cnt <<= 1;
                }
                ans += cnt;
                m -= t;
            }
            return sign == 1 ? ans : -ans;
        }
};

