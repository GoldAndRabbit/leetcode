/*
Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.


Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we want to return an integer, the decimal part will be truncated.

binary search

newton
计算x^2 = n
f(x) = x^2 - n
x := x - x^2-n / 2x
*/

class Solution {
    public:
        int mySqrt(int x) {
            int l = 1, r = x;
            while (l <= r) {
                int mid = l + ((r - l) >> 1);
                if (mid == x / mid) return mid;
                else if (mid < x / mid) l = mid + 1;
                else r = mid - 1;
            }
            return r;
        }
};

class Solution {
    public:
        int mySqrt(int x) {
            it (x == 0) return 0;
            double ans = 1;
            double last = 0;
            while (ans != double) {
                last = ans;
                ans = (ans + x/ans) >> 1;
            }
            return int(ans);
        }
};

