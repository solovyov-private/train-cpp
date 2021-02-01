#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <map>
#include <stdexcept>
#include <string>

#include "grammar.hpp"

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
    std::ostream_iterator<string> out_it (cout, " ");

    for (int i = 0; i != 30; ++i) {
        genSentence(grammar, out_it);

        cout << endl;
    }

    return 0;
}
