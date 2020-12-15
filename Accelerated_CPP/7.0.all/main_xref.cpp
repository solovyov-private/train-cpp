#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "xref.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;
 
int main()
{
  map<string, vector<int> > ret = xref(cin);
 
  for (map<string, vector<int> >::const_iterator iter = ret.begin();
       iter != ret.end();
       ++iter) {
 
    cout << iter->first << " occurs on line(s): ";
 
    vector<int>::const_iterator line_no = iter->second.begin();
    cout << *line_no;
 
    ++line_no;
    while (line_no != iter->second.end()) {
      cout << ", " << *line_no;
      ++line_no;
    }
    cout << endl;
  }
 
  return 0;
}
