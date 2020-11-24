#include <algorithm>
#include <chrono>
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

list<Student_info> extract_fails(list<Student_info>& students);

int main() {
    list<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    auto startTime = std::chrono::high_resolution_clock::now();

    students.sort(compare);

    list<Student_info> failed_students = extract_fails(students);

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

    for (
            list<Student_info>::iterator i = failed_students.begin();
            i != failed_students.end();
            ++i
    ) {
            cout << "Students failed:" << endl;
            cout << i->name << string(maxlen + 1 - i->name.size(), ' ');
            cout << endl;
    }

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
    cout << "Elapsed time: " << duration.count() << "μs" << endl;
}


list<Student_info> extract_fails(list<Student_info>& students) {
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else {
            ++iter;
        }
    }
    return fail;
}
