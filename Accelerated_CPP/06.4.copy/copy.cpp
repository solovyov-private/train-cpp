#include <algorithm>
#include <iostream>
#include <vector>

using std::copy;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> u(10, 100);
    vector<int> v;

    copy(u.begin(), u.end(), back_inserter(v));

    for (vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        cout << (*iter) << endl;
    }

    return 0;
}
