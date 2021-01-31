#ifndef GUARD_swap
#define GUARD_swap

template<class In>
void swap(In& x, In& y)
{
    if (x != y) {
        In tmp = x;
        x = y;
        y = tmp;
    }
}


#endif
