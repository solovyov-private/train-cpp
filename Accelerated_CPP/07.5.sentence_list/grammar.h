#ifndef GUARD_GRAMMAR_H
#define GUARD_GRAMMAR_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

#include "split.h"

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> RuleCollection;
typedef std::map<std::string, RuleCollection> Grammar;

bool bracketed(const std::string& s);
int nrand(int n);
std::vector<std::string> genSentence(const Grammar& g);
void genAux(const Grammar& g,
             const std::string& word, std::vector<std::string>& ret);

Grammar readGrammar(std::istream& in);

#endif
