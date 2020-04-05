class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        long max1 = LONG_MIN;
        long max2 = LONG_MIN;
        long max3 = LONG_MIN;
        for (auto x : nums) {
            if (x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            } else if (x > max2 && x < max1) {
                max3 = max2;
                max2 = x;
            } else if (x > max3 && x < max2) {
                max3 = x;
            }
        }
        return (max3 == LONG_MIN) ? max1 : max3;
    }
};