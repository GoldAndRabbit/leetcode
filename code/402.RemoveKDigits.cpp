/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

给定一个数字
删除k个数字使得剩下来的数字最小。
从高位到低位反复覆盖上个数字的做法
1432219:
1
14   --k
13   --k
12
122  --k
121
1219
for (char c : num) {
    while (!ans.empty() && k > 0 && ans.back() > c) {
        ans.pop_back(c);
        --k;
    }
    ans.push_back(c);
}
*/

class Solution {
    public:
        string removeKdigits(string num, int k) {
            int len = num.size();
            int preK = k;
            string ans;
            for (char c : num) {
                while (!ans.empty() && k > 0 && ans.back() > c) {
                    ans.pop_back();
                    --k;
                }
                ans.push_back(c);
            }
            int cnt = 0;
            while (ans[cnt]=='0') cnt++;
            ans = ans.substr(cnt, len - preK - cnt);
            return ans.size() == 0? "0" : ans;
        }
};
