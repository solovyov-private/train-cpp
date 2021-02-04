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

vector<string> split(const string& s)
{
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = s.begin();

    while (i != s.end()) {
        i = find_if(i, s.end(), not_space);

        iter j = find_if(i, s.end(), space);

        if (i != s.end())
            ret.push_back(string(i, j));
        i = j;
    }

    return ret;
}

void lineWrap(string& text, const size_t outputWidth) {
    string::size_type textLength = text.size();

    for (string::size_type pos = outputWidth;
         pos < textLength; pos += outputWidth){
         pos = text.rfind(' ', pos);
         text.at(pos) = '\n';
    }
}
