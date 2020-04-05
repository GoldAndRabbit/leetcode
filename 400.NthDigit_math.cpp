/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/

/*
思路：
第一步:计算数字落在一个几位数字上面, 记录为digit
1-9     包括9个; 10-99   包括90*2个; 100-999 包括900*3个
比如
n = 250  那么 n = 250 - 9 - 90 * 2 = 61; n = 189       n = 189 - 9 - 90 * 2 = 0

第二步:算出来 61 代表的含义是第61个3位的数字中.
num = 100 + 61 / 3 = 120
但是如果n恰好是9, 189这种情况, 恰好是最后一个
num += n / digit - 1;
num = 1 + 9 / 1 - 1 = 9
num = 10 + 180 / 2 - 1 = 10 + 90 - 1 = 99;

第三步:计算number有几位 % digit
120 的第 1 位*/

class Solution {
public:
    int findNthDigit(int n) {
        // calculate digit
        long base = 9, digit = 1;
        while (n - base * digit > 0) {
            n -= base * digit;
            base *= 10;
            digit++;
        }

        // calculate in which number
        int index = n % digit;
        if (index == 0) index = digit;
        long num = 1;
        for (int i = 1; i < digit; i++) num *= 10;
        num += (index == digit) ? n / digit - 1 : n / digit;

        // return
        for (int i = index; i < digit; i++) num /= 10;
        return num % 10;
    }
};


