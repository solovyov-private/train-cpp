//
// Created by nightingale on 4/5/21.
//
#include <iostream>

int main()
{
    const int N = 5;
    int A[N] = {1,2,3,4,5};

    bool isSorted = 1;
    int k = 0;
    while (k < N - 1) {
        if (A[k] > A[k+1]) {
            isSorted = 0;
            break;
        }

        k++;
    }

    // cout
    std::cout << isSorted << std::endl;
}
