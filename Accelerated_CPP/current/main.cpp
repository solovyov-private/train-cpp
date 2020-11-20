#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::max;
using std::setprecision;
using std::streamsize;
using std::string;
using std::vector;

int main() {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for (
            vector<Student_info>::size_type i =0;
            i < students.size();
            ++i
	    ) {
		    cout << students[i].name << string(maxlen+1-students[i].name.size(), ' ');

		    try{
				double final_grade = grade(students[i]);
				streamsize prec = cout.precision();
				cout << "Your final grade: " << setprecision(3) << final_grade
				                             << setprecision(prec) << endl;
			} catch(domain_error e) {
				cout << endl << e.what() << endl;
				return 1;
			}
	    }
}

vector<Student_info> extract_fails(vector<Student_info>& students) {
    vector<Student_info> fail;
    vector<Student_info>::size_type i = 0;

    while (i != students.size()) {
        if (fgrade(students[i])) {
            fail.push_back(students[i]);
            students.erase(students.begin() + i);
        }
        else {
            i++;
        }
    }
    return fail;
}

