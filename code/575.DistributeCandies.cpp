/*
Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.
Example 1:
Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation:
There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too.
The sister has three different kinds of candies.
Example 2:
Input: candies = [1,1,2,3]
Output: 2
Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1].
The sister has two different kinds of candies, the brother has only one kind of candies.
Note:

The length of the given array is in range [2, 10,000], and will be even.
The number in given array is in range [-100,000, 100,000].

1,2,3,...,分别代表不同的糖果
把糖果等分给哥哥和姐姐
返回姐姐最多能获得几种糖果

妹妹最多能获得len/2个不同种类的糖果
如果种类数目达不到len/2，那么妹妹最多获种类书目个糖果
*/

class Solution {
    public:
        int distributeCandies(vector<int>& candies) {
            int len = candies.size();
            unordered_set<int> s;
            for (int x : candies)
                s.insert(x);
            if (s.size() < len / 2)
                return s.size();
            else
                return len / 2;
        }
};
