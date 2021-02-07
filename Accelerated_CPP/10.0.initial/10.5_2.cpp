#include <fstream>
#include <iostream>
#include <istream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    int fail_count = 0;
    for (int i = 1; i < argc; ++i) {
        ifstream in(argv[i]);

        if (in) {
            string s;
            while (getline(in, s))
                cout << s << endl;
        } else {
            cerr << "can't open the file " << argv[i] << endl;
            ++fail_count;
        }
    }

    return fail_count;
}
