#ifndef GUARD_median_h
#define GUARD_median_h

#include <algorithm>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::sort;
using std::vector;

template<class T, class It>
T median(It begin, It end)
{
    size_t size = end - begin; 

    if (size == 0) {
        throw domain_error("Median of empty vector.");
    }

    sort(begin, end);

    size_t mid = size / 2;

    return size % 2 == 0 ? (begin[mid] + begin[mid -1]) / 2
                         : begin[mid];
}

#endif
