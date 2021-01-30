#include <iostream>
#include <vector>

#include "equal.h"
#include "find.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> x = {1,2,3};
    vector<int> y = {1,2,3};

    cout << equal(x.begin(), x.end(), y.begin(), y.end()) << endl;

    cout << find(x.begin(), x.end(), 4) << endl;
    
    return 0;
}
