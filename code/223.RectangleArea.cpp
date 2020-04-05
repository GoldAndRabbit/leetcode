/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

求两个矩形覆盖的面积
矩形的坐标由从左上到有下的对角线定义

两个面积减去公共面积
*/

class Solution {
    public:
        int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
            int m = (C - A) * (D - B), n = (G - E) * (H - F);
            int overlap = 0;
            int left = min(A, E);
            int right = max(C, G);
            int bottom = max(B, F);
            int top = min(D, H);
            if (left < right && bottom < top)
                overlap = (right - left) * (top - bottom);
            return m + n - overlap;
        }
};
