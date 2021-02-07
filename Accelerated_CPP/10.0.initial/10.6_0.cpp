#include <algorithm>
#include <cstddef>
#include <cstring>
#include <vector>

using std::copy;
using std::size_t;
using std::vector;

int* pointer_to_static()
{
    static int x;
    return &x;
}

int* pointer_to_dynamic()
{
    return new int(0);
}

char* duplicate_chars(const char* p)
{
    size_t length = strlen(p) + 1;
    char* result = new char[length];

    copy(p, p + length, result);

    return result;
}

int main()
{
    const int n = 10;
    typedef int T;
    T* p = new T[n];
    vector<T> v(p, p + n);
    delete[] p;
}
