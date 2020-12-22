#ifndef GUARD_SPLIT
#define GUARD_SPLIT

#include <algorithm>
#include <iostream>
#include <cctype>
#include <vector>

std::vector<std::string> split(const std::string& s);
void lineWrap(std::string& text, const size_t outputWidth);

#endif
