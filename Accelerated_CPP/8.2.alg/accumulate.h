#ifndef GUARD_accumulate
#define GUARD_accumulate

template<class In, class X>
X accumulate(In begin, In end, X x)
{
    while (begin < end)
        x += *begin++;
    return x;
}

#endif
