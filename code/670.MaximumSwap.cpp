/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]

思路：
用10个桶记录下来[0-9]十个字母出现的最低位
从高位到低位遍历字母
    从大桶到小桶遍历
        如果大桶子里面的元素位置低于当前位置那么交换, 并且返回
*/

class Solution {
    public:
        int maximumSwap(int num) {
            string s = to_string(num);
            vector<int> buckets(10, 0);
            for (int i = 0; i < s.size(); ++i) buckets[s[i] - '0'] = i;
            for (int i = 0; i < s.size(); ++i) {
                for (int k = 9; k > s[i] - '0'; --k) {
                    if (i < buckets[k]) {
                        swap(s[i], s[buckets[k]]);
                        return stoi(s);
                    }
                }
            }
            return num;
        }
};