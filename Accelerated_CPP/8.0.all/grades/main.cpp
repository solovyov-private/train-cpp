#include <algorithm>
#include <chrono>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "Collection.h"
#include "analysis.h"
#include "average.h"
#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::list;
using std::map;
using std::max;
using std::setprecision;
using std::streamsize;
using std::string;
using std::vector;

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

    Collection failed_students;

    failed_students = extract_fails(students, pgrade);
//    failed_students = extract_fails(students, did_all_hw);

    vector<Student_info> did, didnt;

    for (
            Collection::iterator i = students.begin();
            i != students.end();
            ++i
    ) {
            cout << i->name << string(maxlen + 1 - i->name.size(), ' ');

            if (did_all_hw(*i))
                did.push_back(*i);
            else
                didnt.push_back(*i);

            try {
                double final_grade = grade(*i);
                char gradeECTC = gradeToECTC(final_grade);
                streamsize prec = cout.precision();
                cout << "Your final grade: " << setprecision(4) << std::showpoint
                                             << final_grade << setprecision(prec)
                                             << " - " << gradeECTC << endl;
            } catch(domain_error e) {
                cout << e.what();
            }
    }

    cout << endl << "Students failed:" << endl;

    for (
            Collection::iterator i = failed_students.begin();
            i != failed_students.end();
            ++i
    ) {
            cout << i->name << " " << setprecision(4) << std::showpoint
                 << grade(*i) << " - " << gradeToECTC(grade(*i)) << endl;
    }

    if (did.empty()) {
        cout << "No one completed homework" << endl;
    }

    if (didnt.empty()) {
        cout << "All completed homework" << endl;
    }
    
    try {
        write_analysis(cout, "median", grade_aux, did, didnt);
    } catch (domain_error e) {
        cout << "error" << endl;
    }

    try {
        write_analysis(cout, "average", average_grade, did, didnt);
    } catch (domain_error e) {
        cout << "error" << endl;
    }

    try {
        write_analysis(cout, "median of homework turned in", optimistic_median, did, didnt);
    } catch (domain_error e) {
        cout << "error" << endl;
    }

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
    cout << "Elapsed time: " << duration.count() << "μs" << endl;

    return 0;
}
