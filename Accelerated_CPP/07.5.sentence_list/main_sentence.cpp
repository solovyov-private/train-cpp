#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

#include "grammar.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::map;
using std::string;
using std::time;
using std::vector;

int main()
{
    srand(time(NULL));

    Grammar grammar = readGrammar(cin);

    for (int i = 0; i != 30; ++i) {
        vector<string> sentence = genSentence(grammar);

        vector<string>::const_iterator it = sentence.begin();
        if (! sentence.empty()) {
            cout << *it;
            ++it;
        }

        while (it != sentence.end()) {
            cout << " " << *it;
            ++it;
        }

        cout << endl;
    }

    return 0;
}
