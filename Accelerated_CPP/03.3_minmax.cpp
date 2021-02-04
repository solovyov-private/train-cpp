#include <iostream>
#include <string>
#include <vector>

using std:: cout; using std::cin;
using std::endl; using std::vector;
using std::string;

int main(){
    string x;
    string max;
    string min;

    while (cin >> x) {
        if (max.size() < x.size() || max.empty()) {
                max = x;
        }

        if (min.size() > x.size() || min.empty()) {
                min = x;
        }
    }

    cout << "min: " << min << "\tmax: " << max << endl;
   
    return 0;
}
