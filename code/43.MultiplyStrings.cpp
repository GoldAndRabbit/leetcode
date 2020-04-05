/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

solution:

index1    012
num1      123

index2     01
num2       45

ans     01234
ans[i + j + 1] = (ans[i + j + 1] + ans[i] * ans[j] + carry) % 10;
if ans == 0
return "0"
*/

class Solution {
    public:
        string multiply(string num1, string num2) {
            string ans(num1.size() + num2.size(), '0');
            for (int i = num1.size() - 1; i >= 0; i--) {
                int carry = 0;
                for (int j = num2.size() - 1; j >= 0; j--) {
                    int tmp = (ans[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                    ans[i + j + 1] = tmp % 10 + '0';
                    carry = tmp / 10;
                }
                ans[i] += carry;
            }
            size_t pos = ans.find_first_not_of("0");
            if (pos != string::npos)
                return ans.substr(pos);
            return "0";
        }
};