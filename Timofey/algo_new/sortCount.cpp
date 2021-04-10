//
// Created by nightingale on 4/10/21.
//
#include <iostream>

void genArray(int A[], int N, int M)
{
    for (int i = 0; i < N; ++i)
        A[i] = rand() % M;
}

void printArray(int A[], int N)
{
    for (int k = 0; k < N; ++k)
        std::cout << A[k] << '\t';
    std::cout << std::endl;
}

void sortCount(int A[], int N, int M)
{
    int tmp[M] = {0};

    for (int i = 0; i < N; ++i)
        tmp[A[i]]++;

    int i = 0;
    for (int x = 0; x < M; ++x)
        for (int k = 0; k < tmp[x]; ++k)
            A[i++] = x;
}

int main()
{
    const int N = 1000;
    int A[N];

    genArray(A, N, 10);
    printArray(A, N);
    sortCount(A, N, 10);
    printArray(A, N);
}
