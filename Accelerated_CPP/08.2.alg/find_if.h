#ifndef GUARD_find_if
#define GUARD_find_if

template<class In, class Predicate>
bool find_if(In begin, In end, Predicate p)
{
    while (begin < end) {
        if (p(*begin))
            return true;
        else
            begin++;
    }
    return false;
}

#endif
