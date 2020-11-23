#include <iostream>
#include <string>
#include <vector>

#include "PI.h"
#include "split.h"
#include "stream.h"

using std::string;
using std::vector;

int main()
{
    vector<string> lines = getLines();

    vector<Variation> collection = browseLines(lines);

    lines = generateVariations(collection);

    printLines(lines);

    return 0;
}
