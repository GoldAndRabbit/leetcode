/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

用一个栈保存每个高度的index
遍历数组，如果当前位置上的元素小于等于栈顶元素，一直入栈
如果遇到大于栈顶的, 那么出栈
如果初栈后为空break
水的高度为min(top.height, cur.height) - 出来栈元素的top
水的宽度为cur.idx - top.indx
*/


class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[st.top()] < height[i]) {
                int tmp = st.top(); st.pop();
                if (st.empty()) break;
                int distance = i - st.top() - 1;
                int high = min(height[st.top()], height[i]) - height[tmp];
                ans += distance * high;
            }
            st.push(i);
        }
        return ans;
    }
};

