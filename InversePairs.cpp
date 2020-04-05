// 牛课网: 数组中的逆序对AC solution

//
class Solution {
    public:
        int mergeSortAndCount(int left, int right, vector<int>& nums) {
            if (left >= right) return 0;
            int mid = left + (right - left) / 2;
            long long cnt = mergeSortAndCount(left, mid, nums) + mergeSortAndCount(mid + 1, right, nums);
            for (int i = left, j = mid + 1; i <= mid; ++i) {
                while (j <= right && nums[i] > nums[j]) ++j;
                cnt += j - (mid + 1);
            }
            sort(nums.begin() + left, nums.begin() + right + 1);
            return cnt % 1000000007;
        }
        int InversePairs(vector<int>& nums) {
            return mergeSortAndCount(0, nums.size() - 1, nums);
        }
};

