/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

思路：
1.counting sort
一个数组记录每个元素出现了几次
然后根据每个元素的计数来一次给原数组赋值

2.two pointers
a pointer point at red, init = 0
a pointer point at blue, init = size - 1
遍历数组
如果发现0 那么和red交换, red++;
如果发现2 那么和blue交换, blue--, 且i--, i--的原因是不要让i直接增长,要让他保持在远地,因为交换完后面的数字以后，当前数字还可能与red交换
1 2 0
1 0 2
0 1 2
3.三个指针ijk维护开始的位置
将设置为i = -1, j = -1, k = -1
遍历数组
if  == 0
    nums[++k] = 2;
    nums[++j] = 1;
    nums[++i] = 0;
elif == 1
    nums[++k] = 2;
    nums[++j] = 1;
elif == 2
    nums[++k] = 2;
*/

// 计数排序
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            vector<int> cnt(3, 0);
            for (auto n: nums)
               cnt[n]++;
            int idx = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < cnt[i]; j++) {
                    nums[idx++] = i;
                }
            }
            return;
        }
};

// two pointers
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            if (nums.size() < 2)
                return;
            int red = 0, blue = nums.size() - 1;
            // i最高只能是blue指针
            for (int i = 0; i <= blue; i++) {
                if (nums[i] == 0) {
                    swap(nums[i], nums[red++]);
                } else if (nums[i] == 2) {
                    // i需要保留原始位置，可能和之前的元素还有交换
                    swap(nums[i--], nums[blue--]);
                }
            }
            return;
        }
};

// three pointers
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int i = -1, j = -1, k = -1;
            for (int idx = 0; idx < nums.size(); idx++) {
                if (nums[idx] == 0) {
                    nums[++k] = 2;
                    nums[++j] = 1;
                    nums[++i] = 0;
                } else if (nums[idx] == 1) {
                    nums[++k] = 2;
                    nums[++j] = 1;
                } else if (nums[idx] == 2) {
                    nums[++k] = 2;
                }
            }
            return;
        }
};
