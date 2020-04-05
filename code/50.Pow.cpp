/*
Implement pow(x, n).


Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
*/

class Solution {
    public:
        double myPow(double x, int n) {
            if (n == 0) return 1;
            if (n == 1) return x;
            if (n < 0)
                return n == INT_MIN ? 1 / pow(x, INT_MAX) / x : 1 / pow(x, -n);
            double ret = myPow(x, n>>1);
            ret *= ret;
            return (n & 1 == 1) ? ret * x : ret;
        }
};
