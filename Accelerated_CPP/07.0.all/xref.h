#ifndef GUARD_XREF
#define GUARD_XREF

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "split.h"

std::map<std::string, std::vector<int> >
         xref(std::istream& in,
              std::vector<std::string> find_words(const std::string&) = split);

#endif
