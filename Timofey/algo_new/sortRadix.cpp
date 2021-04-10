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

void sortRadix(int A[], int N)
{
    int *a0 = new int[N];
    int *a1 = new int[N];

    for (int radix = 0; /* разряд*/
         radix < 32; ++radix) {
        int a0_size = 0;
        int a1_size = 0;
        for (int i = 0; i < N; ++i){
            if ((A[i] & (1 << radix)) == 0)
                a0[a0_size++] = A[i];
            else
                a1[a1_size++] = A[i];
        }

        for (int i = 0; i < a0_size; ++i)
            A[i] = a0[i];
        for (int i = 0; i < a1_size; ++i)
            A[a0_size + i] = a1[i];
    }

    delete[] a0;
    delete[] a1;
}

int main()
{
    const int N = 100;
    int A[N];

    genArray(A, N, 100);
    printArray(A, N);
    sortRadix(A, N);
    printArray(A, N);
}
