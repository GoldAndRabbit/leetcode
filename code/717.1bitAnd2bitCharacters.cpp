/*
We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

Example 1:
Input:
bits = [1, 0, 0]
Output: True
Explanation:
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
Example 2:
Input:
bits = [1, 1, 1, 0]
Output: False
Explanation:
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
Note:

1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.
 */

/*
题目大意有两类编码方式，第一种是0另外一种是10和11
问最后一位是0  还是10 或者11
思路
从第一位开始
如果遇到1那么前进2步
如果遇到0那么前进1步
看最后能否到最后一步 (len - 1)
 */

class Solution {
    public:
        bool isOneBitCharacter(vector<int>& bits) {
            int len = bits.size();
            int i = 0;
            while (i < len) {
                if (i == len - 1)
                    return true;
                if (bits[i] == 1)
                    i += 2;
                else
                    i++;
            }
            return false;
        }
};
