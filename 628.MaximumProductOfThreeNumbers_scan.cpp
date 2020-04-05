/*
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

数组中找三个数字使得乘积最大
根据之前的分析
只需要找max(min1*min2*max1, max1*max2*max3)
*/


class Solution {
    public:
        int maximumProduct(vector<int>& nums) {
            int min1 = INT_MAX, min2 = INT_MAX;
            int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
            for (auto x : nums) {
                if (x <= min1) {
                    min2 = min1;
                    min1 = x;
                } else if (x <= min2) {
                    min2 = x;
                }
                if (x >= max1) {
                    max3 = max2;
                    max2 = max1;
                    max1 = x;
                } else if (x >= max2) {
                    max3 = max2;
                    max2 = x;
                } else if (x >= max3) {
                    max3 = x;
                }
            }
            return max(min1 * min2 * max1, max1 * max2 * max3);
        }
};
