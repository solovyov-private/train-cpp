#ifndef PERMUTED_INDEX_GUARD
#define PERMUTED_INDEX_GUARD

#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

struct Variation
{
    std::vector<std::string>::size_type sz;
    std::vector<std::string> words;
};

std::vector<Variation> browseLine(const std::string& s);
std::vector<Variation> browseLines(std::vector<std::string>& lines);

std::vector<std::string> generateVariations(std::vector<Variation> collection);

std::vector<std::string> toLowCase(const std::vector<std::string>& words);

bool compare(const Variation& x, const Variation& y);

#endif
