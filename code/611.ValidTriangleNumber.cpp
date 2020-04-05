/*
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].

输出合法三角形的个数
任意两边之和大于第三边
因此转化为找到所有三个数字使得任意两个大于第三个
因此可以转化为两个最小的数字大于第三个那么就是三角形 维护一个两个较小的数字之和, 然后用二分查找找到第一个
*/

class Solution {
    public:
        int getFirstGreaterOrEqual(vector<int>& nums, int x, int target) {
            int left = x, right = nums.size();
            int mid;
            while (left < right) {
                mid = left + ((right - left) >> 1);
                if (nums[mid] < target) left = mid + 1;
                else right = mid;
            }
            return right;
        }
        int triangleNumber(vector<int>& nums) {
            int len = nums.size();
            int ans = 0;
            int sum;
            int left, right, mid;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < len - 2; ++i) {
                for (int j = i + 1; j < len - 1; ++j) {
                    sum = nums[i] + nums[j];
                    int firstGE = getFirstGreaterOrEqual(nums, j + 1, sum);
                    ans += firstGE - j - 1;
                }
            }
            return ans;
        }
};

