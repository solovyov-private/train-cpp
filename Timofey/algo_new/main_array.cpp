//
// Created by nightingale on 4/5/21.
//
#include <iostream>

const int MAX_A_SIZE = 100;

int main()
{
    const int N = 5;
    int A[N] = {1,2,3,4,5};
    int B[N];

    for (int i = 0; i < N; ++i) {
        B[i] = A[N];
    }

    // reverse
    for (int k = 0; k < N; ++k) {
        B[k] = A[N-k-1];
    }


    // cout
    for (int k = 0; k < N; ++k) {
        std::cout << A[k] << '\t';
    }
    std::cout << std::endl;

    // swap
    int O = MAX_A_SIZE;
    int X[N];
    int top = 0;
    int x;

    std::cin >> x;
    while (x != 0) {
        X[top++] = x;
        std::cin >> x;
    }

    // cout
    for (int k = 0; k < N; ++k) {
        std::cout << A[k] << std::endl;
    }

    int tmp;
    for (int k = 0; k < top; ++k) {
        tmp = A[k];
        A[k] = A[top-k-1];
        A[N-k-1] = tmp;
    }

    // cout
    for (int k = 0; k < N; ++k) {
        std::cout << A[k] << std::endl;
    }
}