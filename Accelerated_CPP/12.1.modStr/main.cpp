#include <algorithm>
#include <cstring>
#include <iostream>

#include "Str.h"

int main()
{
    Str x("Hello");
    Str y = " World ";
    std::cout << y.c_str() << std::endl;
}
