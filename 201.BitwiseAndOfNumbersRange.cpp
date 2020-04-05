/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
*/

/*
 * 4-6
 * 100
 * 101
 * 110
 * result:
 * 100
 *
 *
 * 8-11
 * 1000
 * 1001
 * 1010
 * 1011
 * result 1000
 * 把不同的位数目先记下来有多少位。然后补齐位数。
 */


class Solution {
    public:
        int rangeBitwiseAnd(int m, int n) {
            int cnt = 0;
            while (m != n) {
                m >>= 1;
                n >>= 1;
                ++cnt;
            }
            return m << cnt;
        }
};
