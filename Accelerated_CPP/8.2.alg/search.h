#ifndef GUARD_search
#define GUARD_search

template<class In, class X>
bool search(In begin, In end, X xbeg, X xend)
{
    while (begin != end) {
        if (*begin == *xbeg) {
            if (*begin == *--xend) {
                return true;
            }
            begin++; xbeg++;
        }
        else
            begin++;
    }
    return false;
}

#endif
