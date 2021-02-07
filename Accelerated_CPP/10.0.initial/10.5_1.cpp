#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

using namespace std;

int main()
{
    ifstream in("in");
    ofstream out("out");

    string s;

    while (getline(in, s))
        out << s << endl;

    return 0;
}
