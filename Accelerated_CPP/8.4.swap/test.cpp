#include <iostream>
#include <vector>

#include "swap.hpp"

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> x = {1,2,3,4};

    swap(*(x.begin()), *(x.end()-1));

    for (vector<int>::const_iterator it = x.begin(); it != x.end(); ++it) {
        cout << *it << endl;
    }

    int y = 5;
    swap(y, y);

    cout << y << endl;
}
