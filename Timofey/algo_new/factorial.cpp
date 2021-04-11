/*
* Factorial really should not be written with recursion
*/
#include <iostream>

uint64_t fact(uint16_t x)
{
    int result;
    std::cout << "fact is called with " << x << std::endl;
    if (x == 0)     // base case
        result = 1;
    else {          //recurrent case
        result = x * fact(x - 1);
    }

    std::cout << "fact exiting with " << x << std::endl;
    return result;
}

int main()
{
    uint16_t x;
    std::cin >> x;
    std::cout << fact(x) << '\n';
    return 0;
}
