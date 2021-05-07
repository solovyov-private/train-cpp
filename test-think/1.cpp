#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    for (int i = 1; i < 8; i++) { 
        for (int j = 0; j < 4 - abs(4 - i); j++)
            cout << '#';
        cout << endl;
    }
}
