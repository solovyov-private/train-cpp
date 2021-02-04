#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "find_urls.h"
#include "split.h"
#include "xref.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::to_string;
using std::vector;

int main()
{
    const int outputWidth = 60;

    map<string, vector<int> > words = xref(cin, find_urls);

    Collection ret = sortWords(words);
 
    for (Collection::const_iterator iter = ret.begin();
         iter != ret.end(); ++iter) {
        string ret = "\"" + iter->first + "\" occurs on ";
 
        if (iter->second.size() == 1) {
            ret += "line: ";
        } else {
            ret += "lines: ";
        }
     
        vector<int>::const_iterator line_no = iter->second.begin();
        ret += to_string(*line_no);
        ++line_no;

        while (line_no != iter->second.end()) {
            ret += ", " + to_string(*line_no);
            ++line_no;
        }
        
        // output
        //
        lineWrap(ret, outputWidth);
        cout << ret << endl;
   }

   return 0;
}
