/*
Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example 1:
Input: N = 10
Output: 9
Example 2:
Input: N = 1234
Output: 1234
Example 3:
Input: N = 332
Output: 299
Note: N is an integer in the range [0, 10^9].

题意：
求不大于N的单调上升数字(可以相等)
从前往后遍历，找到第一个变小的数字, 把它-1，继续往高位执行
直到最后
将对应位置后面的所有数字都改成9
332
322
222
299

774
764
754
744
644
544
444
499
*/

class Solution {
    public:
        int monotoneIncreasingDigits(int N) {
            string s = to_string(N);
            int len = s.size();
            int i = 1;
            while (i < len && s[i - 1] <= s[i]) ++i;
            while (0 < i && i < len && s[i - 1] > s[i]) {
                --i;
                --s[i];
            }
            for (int j = i + 1; j < len; ++j) s[j] = '9';
            return stoi(s);
        }
};
