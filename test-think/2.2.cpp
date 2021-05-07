#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    int size;
    cin >> size;

    for (int i = 1; i < size; i++) {
        for (int z = 0; z < abs(size / 2 - i); z++)
            cout << ' ';
        for (int z = 0; z < (size - abs(size - i * 2)) - 1; z++)
            cout << '#';
        cout << endl;
    }
}
