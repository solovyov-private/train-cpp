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
	cout << "Enter limit to calculate squares: ";
	double limit;
	cin >> limit;

	streamsize prec     = to_string(limit).length();
	streamsize q_prec   = prec * 2;

	for (double i = 0; i < limit; i += 0.1) {
		cout << std::fixed << setw(prec) << i << "|" << setw(q_prec) << i*i << endl;
	}
}
