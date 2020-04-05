#include <iostream>
#define LEN 8

using namespace std;

void sortPrint(int* array, int len, int i)  {
    if (i % 2 == 0)     //even
        cout << array[i / 2];
    else                    // odd
        cout << array[(2 * len - 1 - i) / 2];
}

int main() {
    // int a[LEN] = {0,1,2,3,4,5,6,7};
    int b[LEN] = {7,6,5,4,3,2,1,0};
    for (int i = 0; i< LEN; ++i)
        sortPrint(b, LEN, i);
    cout << endl;
    return 0;
}
