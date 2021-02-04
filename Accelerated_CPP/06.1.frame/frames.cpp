#include <algorithm>
#include <string>
#include <vector>

#include "stream.h"

using std::cin;
using std::max;
using std::string;
using std::vector;

string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for (vector<string>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        maxlen = max(maxlen, iter->size());
    }

    return maxlen;
}

vector<string> center(const vector<string>& v){
    vector<string> ret;
    string x;
    string::size_type maxlen = width(v);

    for (vector<string>::const_iterator i = v.begin(); i != v.end(); ++i) {
        size_t fw_spaces = (maxlen - i->size()) / 2;
        x = *i;
        x.std::string::insert(0, fw_spaces, ' ');
        ret.push_back(x);
    }

    return ret;
}

vector<string> hcat(const vector<string>& left,
                    const vector<string>& right)
{
    vector<string> ret;
    string::size_type width1 = width(left) + 1;

    vector<string>::const_iterator i = left.begin();
    vector<string>::const_iterator j = right.begin();

    while (i != left.end() || j != right.end()) {
        string s;

        if (i != left.end()){
            s = *(i++);
        }

        s += string(width1 - s.size(), ' ');

        if (j != right.end()) {
            s += *(j++);
        }

        ret.push_back(s);
    }

    return ret;
}

vector<string> vcat(const vector<string>& top,
                    const vector<string>& bottom)
{
    vector<string> ret = top;

    for (
            vector<string>::const_iterator iter = bottom.begin();
            iter != bottom.end();
            ++iter
    ) {
        ret.push_back(*iter);
    }

    // or the same
    // ret.insert(ret.end(), bottom.begin(), bottom.end());

    return ret;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    ret.push_back(border);

    for (vector<string>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        ret.push_back("* " + *iter + string(maxlen - iter->size(), ' ') + " *");
    }

    ret.push_back(border);
    return ret;
}

int main(){
    string x;
    vector<string> collection;

    while (getline(cin, x)) {
        collection.push_back(x);
    }

    collection = center(collection);
    collection = frame(collection);

    printLines(collection);

    return 0;
}
