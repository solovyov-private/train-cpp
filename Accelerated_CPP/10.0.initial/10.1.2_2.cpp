#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template<class In, class Pred>
In find_if(In begin, In end, Pred f)
{
    while (begin != end && ! f(*begin))
        begin++;
    return begin;
}

bool isNegative(int n)
{
    return n < 0;
}

int main()
{
    vector<int> v;

    v.push_back(-3);
    v.push_back(3);

    vector<int>::iterator it = find_if(v.begin(), v.end(),
                                       isNegative);

    cout << *it << endl;

    return 0;
}
