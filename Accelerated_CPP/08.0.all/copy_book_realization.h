#ifndef GUARD_copy_book_realization
#define GUARD_copy_book_realization

template <class In, class Out>
Out copy(In begin, In end, Out dest)
{
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}

#endif
