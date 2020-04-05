/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].

扫第一遍统计出出现最多的次数以及出现最多次数的任务的个数
partCnt = mx - 1;
emptySlots = partCnt * (n - (maxCnt - 1));
leftTasks = task.size() - mx * maxCnt;
idles = max(0, emptySlots - leftTasks)
ans = task.length + idles;
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counter(26, 0);
        int mx = 0;
        int maxCnt = 0;
        for (auto x : tasks) {
            ++counter[x - 'A'];
            if (mx < counter[x - 'A']) {
                mx = counter[x - 'A'];
                maxCnt = 1;
            } else if (mx == counter[x - 'A']) {
                ++maxCnt;
            }
        }
        int partCnt = mx - 1;
        int emptySlots = partCnt * (n - (maxCnt - 1));
        int restCnt = tasks.size() - mx * maxCnt;
        int idles = max(0, emptySlots - restCnt);
        return tasks.size() + idles;
    }
};
