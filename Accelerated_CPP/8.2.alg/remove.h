#ifndef GUARD_remove
#define GUARD_remove

template<class In, class X>
In remove(In begin, In end, const X& x)
{
    In result = begin;
    while (begin < end)
        if (*begin == x)
            *result++ = *begin++;
        else
            begin++;
    return result;
}

#endif
