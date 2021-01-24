#ifndef GUARD_median_h
#define GUARD_median_h

#include <algorithm>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::sort;
using std::vector;

template<class T>
T median(vector<T> vec)
{
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = vec.size();

    if (size == 0) {
        throw domain_error("Median of empty vector.");
    }

    sort(vec.begin(), vec.end());

    vec_sz mid = size / 2;

    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2
                         : vec[mid];
}

#endif
