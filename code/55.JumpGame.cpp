/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (nums.empty()) return false;
        int reach = 0, i = 0;
        while (i < len && i <= reach) {
            reach = max(reach, i + nums[i]);
            ++i;
        }
        return i == len;
    }
};
