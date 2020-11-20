#include <iomanip>
#include <ios>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::streamsize;
using std::to_string;

int main(){
	cout << "Enter limit to count: ";
	double max;
	cin >> max;

	streamsize prec = to_string(max).length();
	streamsize q_prec = prec * 2;

	for (double i = 0; i < max; i += 0.1) {
		cout << std::fixed << setw(prec) << i << "|" << setw(q_prec) << i*i << endl;
	}
}
