#ifndef GUARD_GRAMMAR_HPP
#define GUARD_GRAMMAR_HPP

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
void genAux(const Grammar& g, const std::string& token,
            std::vector<std::string>& sentence, std::vector<std::string>& tokens);

Grammar readGrammar(std::istream& in);

template<class OutputIterator>
void genSentence(const Grammar& g, OutputIterator outIt)
{
    std::vector<std::string> sentence;
    std::vector<std::string> tokens;
    tokens.push_back("<sentence>");

    while (!tokens.empty()) {
        std::string token = tokens.back();
        tokens.pop_back();
        genAux(g, token, sentence, tokens);
    }

    std::copy(sentence.begin(), sentence.end(), outIt);
}

#endif
