#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
        for (int j = 7, k = 0; j > 0; j-=2, k++) {
            for (int z = 0; z < k; z++)
                cout << ' ';
            for (int z = 0; z < j; z++)
                cout << '#';
            cout << endl;
        }
}
