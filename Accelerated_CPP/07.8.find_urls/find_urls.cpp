#include "find_urls.h"

using std::cin;
using std::cout;
using std::endl;
using std::find_if;
using std::search;
using std::string;
using std::vector;

bool not_url_char(char c)
{
    // Allowed url chars
    //
    static const string url_ch = "~;/?:!@#$%^_&*(),.";

    // find > Returns an iterator to the first element in the range [first,last) that
    // compares equal to val. If no such element is found, the function returns last.
    //
    return !(
                   isalnum(c)
                || find(url_ch.begin(), url_ch.end(), c) != url_ch.end()
            );
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";
    typedef string::const_iterator iter;
    iter i = b;

    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        // ensure sep is not at the begin or end of a string
        //
        if (i != b && i + sep.size() != e) {
            // beg is a start of protocol name
            //
            iter beg = i;
            while (beg != b && isalpha(beg[-1])) 
                --beg;

            // exists at least one symbol after sep
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }

        // sep is not a part of url, move further
        //
        i += sep.size();
    }
    return e;
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
    // find_if > Returns an iterator to the first element in the range [first,last) for
    // which pred returns true. If no such element is found, the function returns last.
    //
    return find_if(b, e, not_url_char);
}

vector<string> find_urls(const string& s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    while (b != e) {
        b = url_beg(b, e);

        if (b != e) {
            iter after = url_end(b, e);
            ret.push_back(string(b, after));
            b = after;
        }
    }

    return ret;
}
