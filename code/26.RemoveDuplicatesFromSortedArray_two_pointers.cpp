/*
Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
 */

/*
题意：就地数组去重，就是把不重复的元素依次放在前面。
用slow-fast pointer实现
if slow != fast:
    slow向后移动
    nums[slow] = nums[fast]
例如1 1 2
*/
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.empty())
               return 0;
            int slow = 0;
            for (int fast = 1; fast < nums.size(); fast++) {
                if (nums[slow] != nums[fast]) {
                    slow++;
                    nums[slow] = nums[fast];
                }
            }
            return slow + 1;
        }
};
