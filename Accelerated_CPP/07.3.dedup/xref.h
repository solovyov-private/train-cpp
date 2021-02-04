#ifndef GUARD_XREF
#define GUARD_XREF

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "split.h"

typedef std::vector<std::pair<std::string, std::vector<int> > > Collection;

bool compare(std::pair<std::string, std::vector<int> >& a,
             std::pair<std::string, std::vector<int> >& b);

Collection sortWords(std::map<std::string, std::vector<int> >& words);

std::map<std::string, std::vector<int> >
         xref(std::istream& in,
              std::vector<std::string> find_words(const std::string&) = split);

#endif
