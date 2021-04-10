#include <iostream>

int find(int A[], int N, int x)
{
    for (int i = 0; i < N; ++i)
        if (A[i] == x)
            return i;
    return -1;
}

int main()
{
    int N = 10;
    int A[] = {1, 3, 3, 7, 7, 7, 7, 9, 10, 10};
    int x;

    
    for (int i = 0; i < N; ++i)
        std::cout << A[i] << '\t';
    std::cout << std::endl;

    std::cin >> x;
    std::cout << "index of x is: " << find(A, N, x) << std::endl;

    return 0;
}
