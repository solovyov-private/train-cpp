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

    for (int pos = 0; pos < N - 1; ++pos) {
        for(int i = pos + 1; i < N; ++i) {
            int tmp = A[i];
            A[i] = A[pos];
            A[pos] = tmp;
        }
    }

    // cout
    for (int k = 0; k < N; ++k) {
        std::cout << A[k] << std::endl;
    }
}
