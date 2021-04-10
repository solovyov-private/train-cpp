#include <iostream>

int left_boundary(int A[], int N, int x)
{
    int left = -1;
    int right = N;

    while (right - left > 1) {
        int middle = (left + right) / 2;
        if(A[middle] < x)
            left = middle;
        else
            right = middle;
    }

    return left;
}

int find(int A[], int N, int x)
{
    int left = left_boundary(A, N, x);
    int potential_first_index_of_x_in_A = left + 1;

    if (potential_first_index_of_x_in_A < N
        && A[potential_first_index_of_x_in_A] == x)
        return potential_first_index_of_x_in_A;
    else
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
    std::cout << "pos of x is: " << find(A, N, x) << std::endl;

    return 0;
}
