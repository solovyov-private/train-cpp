#include <algorithm>
#include <iostream>
#include <vector>

using std::copy;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    const size_t NDim = 3;
    double coords[NDim];

    vector<double> v;
    copy(coords, coords + NDim, back_inserter(v));

    return 0;
}
