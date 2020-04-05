/*
Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].


  3 4 2
->3 4 4 true

  3 4 3
->3 4 3 true

  3 4 3 4
->3 4 3 4 false

设置一个modified = false;
从第2个元素开始比较
if nums[i] < nums[i - 1]:
    if modfied: return false
    else:
        modified = true
        if i - 2 >= 0 and nums[i] < nums[i - 2]:
            nums[i] = nums[i - 1]
return true
*/

class Solution {
    public:
        bool checkPossibility(vector<int>& nums) {
            bool modified = false;
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] < nums[i - 1]) {
                    if (modified) return false;
                    else {
                        modified = true;
                        if (i - 2 >= 0 && nums[i] < nums[i - 2])
                            nums[i] = nums[i - 1];
                    }
                }
            }
            return true;
        }
};
