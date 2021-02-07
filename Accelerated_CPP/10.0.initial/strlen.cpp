#include <cstddef>
#include <iostream>
#include <string>

std::size_t strlen(const char* p)
{
    std::size_t size = 0;
    while (*p++ != '\0')
        ++size;

    return size;
}

int main(int argc, char** argv)
{
    const char hello[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    std::string s(hello, hello + strlen(hello));
    std::cout << s << std::endl;
}
