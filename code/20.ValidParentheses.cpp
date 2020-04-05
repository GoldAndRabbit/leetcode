/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
    public:
        bool isValid(string s) {
            if (s.empty()) return true;
            stack<char> st;
            for (char x : s) {
                if (x == '(' || x == '{' || x == '[') st.push(x);
                else {
                    if (st.empty()) return false;
                    if (x == ')' && st.top() != '(') return false;
                    if (x == '}' && st.top() != '{') return false;
                    if (x == ']' && st.top() != '[') return false;
                    st.pop();
                }
            }
            return st.empty();
        }
};
