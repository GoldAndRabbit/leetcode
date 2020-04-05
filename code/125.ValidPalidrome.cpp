/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
    public:
        bool isPalindrome(string s) {
            if (s.empty()) return true;
            int l = 0, r = s.size() - 1;
            while (l < r) {
                while (l < r && !isalnum(s[l])) ++l;
                while (l < r && !isalnum(s[r])) --r;
                if (tolower(s[l++]) != tolower(s[r--])) 
                    return false;
            }
            return true;
        }
};
