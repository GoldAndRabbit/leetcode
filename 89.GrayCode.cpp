/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 */

/*
格雷码与二进制的转化
int binaryToGray(int num) {
    return (num >> 1) ^ num;
}

int grayToBinary(int num) {
    int mask;
    for (mask = num >> 1; mask != 0; mask >>= 1) {
        num ^= mask;
    }
    return num;
}
 */
class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> ans;
            for (int i = 0; i < pow(2, n); i++) {
                ans.push_back((i >> 1) ^ i);
            }
            return ans;
        }
};
