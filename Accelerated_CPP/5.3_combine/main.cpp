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

//typedef list<Student_info> Collection;
typedef vector<Student_info> Collection;

Collection extract_fails(Collection& students);

int main() {
    Student_info record;
    string::size_type maxlen = 0;

    Collection students;

    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    auto startTime = std::chrono::high_resolution_clock::now();

//    students.sort(compare); // list
    sort(students.begin(), students.end(), compare); // vector

    Collection failed_students = extract_fails(students);

    for (
            Collection::iterator i = students.begin();
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
            Collection::iterator i = failed_students.begin();
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


Collection extract_fails(Collection& students) {
    Collection fail;
    Collection::iterator iter = students.begin();

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
