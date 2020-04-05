/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

/*
同样是快慢指针的思想
这次有两处不同
slow指针前两个元素无脑推进
fast的指针比较它前面的两个元素fast - 2的大小
if fast > fast-2
那么slow++且nums[slow] = fast

        1 1 1 2 2 3
        1 1 2 2 3 3
slow:   0 1 2 3 4 5

拓展版本如果最大是n
// discuss的写法
int removeDuplicates(vector<int>& nums, int k) {
    if (nums.size() < k)
        return nums.size();
    int i, j;
    for (int i = k, j = k; j < nums.size(); j++) {
        if (nums[i - k] != nums[j]) {
            nums[i++] = nums[j];
        }
    }
    return i;
}
*/
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.empty())
               return 0;
            int slow = 0;
            for (int fast: nums) {
               if (slow < 2 || fast > nums[slow - 2]) {
                   nums[slow++] = fast;
               }
            }
            return slow;
        }
};
