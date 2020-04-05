/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

给一个长度为n的元素
找到它majority element:出现次数多于ceil(n / 2)的元素
boyer-moore voting algorithm

idx = 0
cnt = 1
i = 1 <-> n - 1
if nums[idx] == nums[i] ++cnt;
else --cnt;
if (cnt == 0) {
    idx = i;
    cnt = 1;
}
return nums[idx]
*/

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int idx = 0, cnt = 1;
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[idx] == nums[i]) ++cnt;
                else --cnt;
                if (cnt == 0) {
                    idx = i;
                    cnt = 1;
                }
            }
            return nums[idx];
        }
};
