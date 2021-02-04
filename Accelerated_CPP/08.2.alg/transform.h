#ifndef GUARD_transform
#define GUARD_transform

template<class In, class Out, class Func>
Out transform(In begin, In end, Out o_begin, Func f)
{
    while (begin < end)
        *o_begin++ = f(*begin++);
    return o_begin;
}

#endif
