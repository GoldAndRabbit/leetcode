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

排序
如果全是正数或者全是负数
-6, -5, -4, -3, -2, -1
就是最后三个的乘积

如果最后三个不都是负数
-3 -2 -1 3
-2 -1 2 3
那么就是用最前面的两个负数乘以最后一个正数
*/


class Solution {
    public:
        int maximumProduct(vector<int>& nums) {
            nums.sort(nums.begin(), nums.end());
            return max(nums[nums.size() -1] * nums[nums.size() - 2, nums[nums.size() - 3],
                    nums[0] * nums[1] * nums[nums.size() - 1]);
        }
};
