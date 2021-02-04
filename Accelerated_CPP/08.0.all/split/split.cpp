#include "split.h"

using std::cin;
using std::cout;
using std::endl;
using std::find_if;
using std::isspace;
using std::string;
using std::vector;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

bool is_palindrome(const string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

void lineWrap(string& text, const size_t outputWidth) {
    string::size_type textLength = text.size();

    for (string::size_type pos = outputWidth;
         pos < textLength; pos += outputWidth){
         pos = text.rfind(' ', pos);
         text.at(pos) = '\n';
    }
}
