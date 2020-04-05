/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.
*/


/*
 * 枚举每一位1的个数
 * 累加 1的个数乘以0的个数
 */

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        if (nums.empty())
            return ans;
        int len = nums.size();
        for (int i = 0; i < 32; i++) {
            int tmp = 0;
            for (num : nums) {
                if ((num >> i) & 1 != 0)
                    tmp += 1;
            }
            ans += tmp * (len - tmp);
        }
        return ans;
    }
};
