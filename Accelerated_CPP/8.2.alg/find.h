#ifndef GUARD_find_if
#define GUARD_find_if

template<class In, class X>
bool find(In begin, In end, const X& x)
{
    while (begin < end) {
        if (*begin == x)
            return true;
        else
            begin++;
    }
    return false;
}

#endif
