#ifndef GUARD_remove_copy_if
#define GUARD_remove_copy_if

template<class In, class Out, class Predicate>
Out remove_copy_if(In begin, In end, Out o_begin, Predicate p)
{
    while (begin < end)
        if (p(*begin))
            *o_begin++ = *begin++;
        else
            begin++;
    return o_begin;
}

#endif
