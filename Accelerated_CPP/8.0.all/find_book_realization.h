#ifndef GUARD_find_book_realization
#define GUARD_find_book_realization

template <class In, class X> In find(In begin,
                                     In end, const X& x)
{
    while (begin != end && *begin != x) {
        ++begin;
    }
    return begin;
}

template <class In, class X> In find_recursive(In begin,
                                               In end, const X& x)
{
    if (begin == end || *begin == x) {
        return begin;
    }
    ++begin;
    find_recusrsive(begin, end, x);
}

#endif
