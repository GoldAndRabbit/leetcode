/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            vector<int> ans;
            int carry = 0;
            for (int i = digits.size() - 1; i >= 0; --i) {
                int sum = carry + digits[i] + (i == digits.size() - 1 ? 1 : 0);
                carry = sum / 10;
                ans.push_back(sum % 10);
            }
            if (carry > 0) ans.push_back(carry);
            reverse(ans.begin(), ans.end());
            return ans;
        }
};
