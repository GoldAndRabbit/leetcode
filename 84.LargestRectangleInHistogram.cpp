/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> s;
        for (int i = 0; i < heights.size(); ++i) {
            if (s.empty() || heights[i] >= s.top()) s.push(heights[i]);
            else {
                int cnt = 0;
                while (!s.empty() && heights[i] < s.top()) {
                    ++cnt;
                    ans = max(ans, s.top() * cnt);
                    s.pop();
                }
                while (cnt--) s.push(heights[i]);
                s.push(heights[i]);
            }
        }
        int cnt = 1;
        while (!s.empty()) {
            ans = max(ans, s.top() * cnt);
            ++cnt;
            s.pop();
        }
        return ans;
    }
};
