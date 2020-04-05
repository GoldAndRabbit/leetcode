/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        int mask = 0;
        // start from high bit to low bit
        for (int i = 31; i >= 0; i--) {
            // generate 1000....0, 1100...0, 1110...0, ... , 1111...1
            mask = mask | (1 << i);
            unordered_set<int> s; // unordered_set s maintain prefix
            for (int num: nums) {
                s.insert(num & mask);
            }
            // generate a greedyTry from previous ans
            int greedyTry = ans | (1 << i);
            // if a ^ b = c then a ^ c = b, now we got a and c, we should find out if b exsits in unordered_set s
            for (int prefix: s) {
                if (s.find(greedyTry ^ prefix) != s.end()) {
                    ans = greedyTry;
                    break;
                }
            }
        }
        return ans;
    }
};
