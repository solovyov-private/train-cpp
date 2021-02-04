#include <iostream>

using std::cout;
using std::endl;

int next(int n)
{
    return n + 1;
}

int main()
{
    int (*fp)(int);
    fp = next;

    int i = 10;
    cout << i << endl;

    i = fp(i);
    i = fp(i);

    cout << i << endl;

    return 0;
}
