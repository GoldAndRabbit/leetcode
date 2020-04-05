/*
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.

(a+bi) * (c+di) = ac - bd + (ad + bc)i
*/


class Solution {
    public:
        string complexNumberMultiply(string a, string b) {
            int len1 = a.size();
            int len2 = b.size();
            auto p1 = a.find_first_of('+'), p2 = b.find_first_of('+');
            int a1 = stoi(a.substr(0, p1)), a2 = stoi(a.substr(p1 + 1, len1 - p1 - 2));
            int b1 = stoi(b.substr(0, p2)), b2 = stoi(b.substr(p2 + 1, len2 - p2 - 2));
            int r1 = a1 * b1 - a2 * b2;
            int r2 = a1 * b2 + a2 * b1;
            return to_string(r1) + '+' + to_string(r2) + 'i';
        }
};
