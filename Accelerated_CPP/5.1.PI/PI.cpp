#include "PI.h"
#include "split.h"

using std::string;
using std::vector;


// Construct all possible variations for each line
// and add struct item
//
vector<Variation> browseLine(const string& s)
{
    vector<Variation> collection;
    vector<string> words = splitToWords(s);

    for (vector<string>::size_type i = 0; i != words.size(); ++i) {
        Variation variation = {words.size() - i, words};
        collection.push_back(variation);
        rotate(words.begin(), words.begin() + 1, words.end());
    }

    return collection;
}


// Combine variations for all lines and sort
//
vector<Variation> browseLines(vector<string>& lines)
{
    vector<Variation> collection;

    for (vector<string>::size_type i = 0; i != lines.size(); ++i) {
        vector<Variation> tmp_collection = browseLine(lines[i]);
        collection.insert(collection.end(), tmp_collection.begin(), tmp_collection.end());
    }

    sort(collection.begin(), collection.end(), compare);

    return collection;
}


// Generate variations to a splitted strings
//
vector<string> generateVariations(vector<Variation> collection)
{
    vector<string> firstParts;
    vector<string> lines;
    vector<string> secondParts;

    string::size_type maxWidth = 0;

    for (vector<Variation>::size_type i = 0; i != collection.size(); ++i) {
        Variation variation = collection[i];
        string firstPart, secondPart;

        for (vector<string>::size_type j = variation.sz; j < variation.words.size(); ++j)
            firstPart += variation.words[j] + " ";

        firstParts.push_back(firstPart);

        if (firstPart.size() > maxWidth)
            maxWidth = firstPart.size();

        for (vector<string>::size_type j = 0; j < variation.sz; ++j)
            secondPart += variation.words[j] + " ";

        secondParts.push_back(secondPart);
    }

    for (vector<string>::size_type i = 0; i < firstParts.size(); ++i) {
        // Expand firstPart to maxWidth
        // 
        std::stringstream tmp;
        tmp << std::setw(maxWidth) << firstParts[i];
        
        string line = tmp.str() + "\t" + secondParts[i];
        lines.push_back(line);
    }

    return lines;
}


// Convert strings to lower case
// 
vector<string> toLowCase(const vector<string>& words){
	vector<string> lc_words;

	for(vector<string>::size_type i = 0; i != words.size(); ++i){
        string word = words[i];
        std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return std::tolower(c);});

		lc_words.push_back(word);
	}

	return lc_words;
}

// Comparator to sort collection
//
bool compare(const Variation& x, const Variation& y)
{
    return toLowCase(x.words) < toLowCase(y.words);
}
