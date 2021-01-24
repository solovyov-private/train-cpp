#ifndef GUARD_binary_search_book_realization
#define GUARD_binary_search_book_realization

template<class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
    while (begin < end) {
        Ran mid = begin + (end - begin) / 2;

        if (x < * mid)
            end = mid;
        else if (*mid < x)
            begin = mid + 1;
        else
            return true;
    }
    return false;
}

#endif
