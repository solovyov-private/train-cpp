#ifndef GUARD_equal
#define GUARD_equal

template<class In>
bool equal(In beginX, In endX, In beginY, In endY)
{
    while (beginY != endY) {
        if (*beginX == *beginY) {
            beginX++;
            beginY++;
        }
        else
            return false;
    }
    return true;
}

#endif
