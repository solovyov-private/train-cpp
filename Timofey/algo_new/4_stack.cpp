#include <iostream>

using namespace std;

const int MAX_A_SIZE = 100;

int main()
{
    
    int N = MAX_A_SIZE;
    int A[N];
    int top = 0;
    int x;

    cin >> x;

    while (x) {
        A[top++] = x;
        cin >> x;
    }

    while (top > 0) {
        cout << A[--top] << '\t';
    }

    cout << endl;

    return 0;
}
