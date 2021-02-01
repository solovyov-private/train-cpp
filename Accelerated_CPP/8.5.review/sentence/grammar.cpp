#include "grammar.hpp"

using std::domain_error;
using std::istream;
using std::logic_error;
using std::map;
using std::string;
using std::vector;

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

bool bracketed(const string& s)
{
    return s.size() > 1 && s[0] == '<'
                        && s[s.size() - 1] == '>';
}

void genAux(const Grammar& g, const string& token,
            vector<string>& sentence, vector<string>& tokens)
{
    if (! bracketed(token)) {
        sentence.push_back(token);
    } else {
        Grammar::const_iterator it = g.find(token);
        if (it == g.end()) {
            throw logic_error("empty rule");
        }

        const RuleCollection& c = it->second;
        const Rule& r = c[nrand(c.size())];

        for (Rule::const_reverse_iterator i = r.rbegin();
             i != r.rend(); ++i) {
            tokens.push_back(*i);
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
