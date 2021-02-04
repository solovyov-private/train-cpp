#ifndef GUARD_reverse_book_realization
#define GUARD_reverse_book_realization

#include <algorithm>

template <class Bi>
void reverse(Bi begin, Bi end)
{
    while (begin != end) {
        --end;
        if (begin != end)
            swap(*begin++, *end);
    }
}

#endif
