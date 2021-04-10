//
// Created by nightingale on 4/5/21.
//
#include <iostream>

int main()
{
    const int N = 10000;
    int A[N];

    for (int i = 0; i < N; ++i) {
        A[i] = N - i;
    }

    bool isSorted = 0;
    while (!isSorted) {
        int k = 0;
        isSorted = 1;

        while (k < N - 1) {
            if (A[k] > A[k+1]) {
                int tmp = A[k];
                A[k] = A[k+1];
                A[k+1] = tmp;
                isSorted = 0;
            } 
            k++;
        }
    }

    // cout
    for (int k = 0; k < N; ++k) {
        std::cout << A[k] << std::endl;
    }
}
