/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
    public:
        string addBinary(string a, string b) {
            string ans = "";
            int i = a.size() - 1, j = b.size() - 1, carry = 0;
            while (i >= 0 || j >= 0) {
                int sum = carry;
                if (i >= 0) sum += a[i--] - '0';
                if (j >= 0) sum += b[j--] - '0';
                ans = to_string(sum % 2) + ans;
                carry = sum / 2;
            }
            return (carry == 0) ? ans : "1" + ans;
        }
};
