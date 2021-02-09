#include <iostream>
#include <vector>

#include "median.h"

using std::cout;
using std::endl;
using std::vector;

template<class T>
void printStructure(T& structure)
{
    cout << "Initial structure: ";
    for (auto& x : structure)
        cout << x << "  ";
    cout << "" << endl << endl;
}

int main() {
    vector<int> test_set1{1, 2, 3, 4, 5, 6};
    cout << "Meidan: " << median<int>(test_set1.begin(), test_set1.end()) << endl;

    printStructure(test_set1);

    vector<double> test_set2{1.5, 1.2, 3.3, 4.8, 5.9, 6.0};
    cout << "Median: " << median<double>(test_set2.begin(), test_set2.end()) << endl;

    printStructure(test_set2);

    int test_set3[]{1, 2, 3, 4, 5, 6};
    cout << "Median: " << median<int>(test_set3, test_set3 + sizeof(test_set3)
                                                         / sizeof(*test_set3)) << endl;

    printStructure(test_set3);

    return 0;
}
