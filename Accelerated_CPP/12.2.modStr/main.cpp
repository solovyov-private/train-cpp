#include <algorithm>
#include <cstring>
#include <iostream>

#include "Str.h"

int main()
{
    Str x("Hello");
    std::cout << x.c_str() << std::endl;

    Str y = " World ";
    const size_t noSymbolsToCopy = 3;
    char f[noSymbolsToCopy];
    size_t f_size = y.copy(f, noSymbolsToCopy);
    std::cout << f << std::endl;
}
