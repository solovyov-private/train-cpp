//
// Created by nightingale on 4/5/21.
//
#include <iostream>

int main()
{
    const int N = 1000;
    int A[N];

    for (int i = 0; i < N; ++i) {
        A[i] = N - i;
    }

    for (int pos = 1; pos < N; ++pos) {
        int i = pos;

        while (i > 0 && A[i-1] > A[i]) {
            int tmp = A[i];
            A[i] = A[i-1];
            A[i-1] = tmp;
            i--;
        }
    }

    // cout
    for (int k = 0; k < N; ++k) {
        std::cout << A[k] << std::endl;
    }
}
