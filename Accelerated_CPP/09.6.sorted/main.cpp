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
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    auto startTime = std::chrono::high_resolution_clock::now();

    sort(students.begin(), students.end(), compare); // vector

    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i) {
        if(students[i].valid()){
            cout << students[i].name()
                 << string(maxlen + 1 - students[i].name().size(), ' ');

            cout << ((students[i].passed()) ? "P" : "F") << endl;
        }
    }

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
    cout << "Elapsed time: " << duration.count() << "μs" << endl;

    return 0;
}
