#ifndef GUARD_remove_copy
#define GUARD_remove_copy

template<class In, class Out, class X>
Out remove_copy(In begin, In end, Out o_begin, const X& x)
{
    while (begin < end)
        if (*begin == x)
            *o_begin++ = *begin++;
        else
            begin++;
    return o_begin;
}

#endif
