#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::list;
using std::max;
using std::setprecision;
using std::streamsize;
using std::string;
using std::vector;

int main() {
    list<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    for (
            list<Student_info>::iterator i = students.begin();
            i != students.end();
            ++i
        ) {
            cout << i->name << string(maxlen + 1 - i->name.size(), ' ');

            try{
                double final_grade = grade(*i);
                streamsize prec = cout.precision();
                cout << "Your final grade: " << setprecision(3) << final_grade
                                             << setprecision(prec) << endl;
            } catch(domain_error e) {
                cout << endl << e.what() << endl;
                return 1;
            }
        }
}

list<Student_info> extract_fails(list<Student_info>& students) {
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            students.erase(iter);
        } else {
            ++iter;
        }
    }
    return fail;
}
