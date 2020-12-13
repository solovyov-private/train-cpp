#include "split.h"
#include "xref.h"

using std::cin;
using std::istream;
using std::map;
using std::string;
using std::vector;

map<string, vector<int> >
    xref(istream& in,
         vector<string> find_words(const string&))
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    while (getline(in, line)) {
        ++line_number;

        vector<string> words = find_words(line);

        for (vector<string>::const_iterator iter = words.begin();
            iter != words.end();
            ++iter) {
            ret[*iter].push_back(line_number);
        }
    }

    return ret;
}
