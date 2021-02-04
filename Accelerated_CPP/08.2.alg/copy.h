#ifndef GUARD_copy
#define GUARD_copy

template<class In, class Out>
Out copy(In begin, In end, Out o_begin)
{
    while (begin < end)
        *o_begin++ = *begin++;
    return o_begin;
}

#endif
