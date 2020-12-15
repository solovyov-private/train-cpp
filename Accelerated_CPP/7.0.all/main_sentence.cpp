#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

#include "split.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::logic_error;
using std::map;
using std::string;
using std::time;
using std::vector;

typedef vector<string> Rule;
typedef vector<Rule> RuleCollection;
typedef map<string, RuleCollection> Grammar;

bool bracketed(const string& s);
int nrand(int n);
vector<string> genSentence(const Grammar& g);
void genAux(const Grammar& g,
             const string& word, vector<string>& ret);

Grammar readGrammar(istream& in);

Grammar readGrammar(istream& in)
{
    Grammar ret;
    string line;

    while (getline(in, line)) {
        vector<string> entry = split(line);
        
        if (! entry.empty())
            ret[entry[0]].push_back(
                Rule(entry.begin() + 1, entry.end())
            );
    }
    return ret;
}

vector<string> genSentence(const Grammar& g)
{
    vector<string> ret;
    genAux(g, "<sentence>", ret);
    return ret;
}

bool bracketed(const string& s)
{
    return s.size() > 1 && s[0] == '<'
                        && s[s.size() - 1] == '>';
}

void genAux(const Grammar& g,
             const string& word, vector<string>& ret)
{
    if (! bracketed(word)) {
        ret.push_back(word);
    } else {
        Grammar::const_iterator it = g.find(word);
        if (it == g.end()) {
            throw logic_error("empty rule");
        }

        const RuleCollection& c = it->second;
        const Rule& r = c[nrand(c.size())];

        for (Rule::const_iterator i = r.begin();
             i != r.end(); ++i) {
            genAux(g, *i, ret);
        }
    }
}

int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument of the nrand is out of range");

    const int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / bucket_size;
    while (r >= n);

    return r;
}

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
