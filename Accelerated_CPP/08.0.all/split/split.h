#ifndef GUARD_SPLIT
#define GUARD_SPLIT

#include <algorithm>
#include <iostream>
#include <cctype>
#include <vector>

bool space(char);
bool not_space(char);

template<class Out>
Out split(const std::string& s)
{
    typedef std::string::const_iterator iter;
    std::vector<std::string> ret;
    Out os;

    iter i = s.begin();

    while (i != s.end()) {
        i = find_if(i, s.end(), not_space);

        iter j = find_if(i, s.end(), space);

        if (i != s.end())
            *os++ = std::string(i, j);
        i = j;
    }
    return os;
}
void lineWrap(std::string& text, const size_t outputWidth);

#endif
