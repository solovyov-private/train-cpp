#ifndef GUARD_median_h
#define GUARD_median_h

#include <algorithm>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::sort;
using std::vector;

template<class T, class ITER>
T median(ITER begin, ITER end)
{
    if (begin == end) {
        throw domain_error("Median of empty vector.");
    }

    vector<T> tmp;

    while (begin != end)
        tmp.push_back(*begin++);

    sort(tmp.begin(), tmp.end());

    size_t mid = tmp.size() / 2;

    T retVal = (tmp.size() % 2 == 0) ? (tmp[mid] + tmp[mid - 1]) / 2
                                     : tmp[mid];
    return retVal;
}

#endif
