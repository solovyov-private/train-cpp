#include "split.h"
#include "xref.h"

using std::cin;
using std::istream;
using std::map;
using std::pair;
using std::string;
using std::vector;

bool compare(pair<string, vector<int> >& a,
             pair<string, vector<int> >& b)
{
    return a.second.size() < b.second.size();
}

Collection sortWords(map<string, vector<int> >& words)
{
    Collection ret;

    for (map<string, vector<int> >::const_iterator it = words.begin();
         it != words.end(); ++it) {
        ret.push_back(*it);
    }
    
    sort(ret.begin(), ret.end(), compare);

    return ret;
}

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
            iter != words.end(); ++iter) {
            if (find(ret[*iter].begin(), ret[*iter].end(), line_number) == ret[*iter].end()) {
                ret[*iter].push_back(line_number);
            }
        }
    }

    return ret;
}
