#include "stream.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> getLines() {
    vector<string> lines;
    string line;
    
    while (getline(cin, line)) {
        lines.push_back(line);
    }
    
    return lines;
}

void printLines(vector<string>& lines) {
    for (vector<string>::size_type i = 0; i != lines.size(); ++i) {
        cout << lines[i] << endl;
    }
}
