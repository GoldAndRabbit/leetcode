/*
思路：
从最小的约数开始，依次加上约数的个数
如果长度为n
考虑divisor d 我们能通过n/d次copy all操作来得到n
为了得到d，我们可以通过共d个操作（1个copy和d-1次paste)
最小的次数发生在 n下降最快的时候，时间复杂度O(lon(n))
举例来说
如果n=1024，那么n/2需要10次，是最小的结果。比O(n)复杂度的dp方法好很多
但是最差的情况下是n=一个很大的素数，比如n=997
*/

class Solution {
    public:
        int minSteps(int n) {
            int ans = 0;
            for (int d = 2; d <= n; d++) {
                while (n % d == 0) {
                    ans += d;
                    n /= d;
                }
            }
            return ans;
        }
};
