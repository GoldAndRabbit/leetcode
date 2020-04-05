/*
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.

最后末尾的处理
min = (ans, 24 * 60 + t[0] - t.back());
*/

class Solution {
    public:
        int convert(string t) {
            return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
        }
        int findMinDifference(vector<string>& timePoints) {
            if (timePoints.size() <= 1) return 0;
            vector<int> t;
            for (int i = 0; i < timePoints.size(); ++i)
                t.push_back(convert(timePoints[i]));
            sort(t.begin(), t.end());
            int ans = t[1] - t[0];
            for (int i = 2; i < t.size(); ++i)
                ans = min(ans, t[i] - t[i - 1]);
            return min(ans, 24 * 60 + t[0] - t.back());
        }
};

