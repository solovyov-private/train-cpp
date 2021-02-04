#ifndef GUARD_replace_book_realization
#define GUARD_replace_book_realization

template<class In, class X>
void replace(In begin, In end,
             const X& x, const X& y)
{
    while (begin != end) {
        if (*begin == x)
            *begin = y;
        ++begin;
    }
}

#endif
