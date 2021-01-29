#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include <algorithm>
#include <ostream>
#include <iostream>
#include <vector>

#include "average.h"
#include "grade.h"
#include "median.h"
#include "Student_info.h"

//double average_analysis(const std::vector<Student_info>& students);
//double median_analysis(const std::vector<Student_info>& students);
double optimistic_median(const Student_info& s);
//double optimistic_median_analysis(const std::vector<Student_info>& students);

//double doAnalysis(const std::vector<Student_info>& students,
//                  double ptrAnalysisMethod(const Student_info&));

template<class T, class S>
T doAnalysis(const std::vector<S>& students,
             T ptrAnalysisMethod(const S&)){
    vector<T> grades;

    transform(students.begin(), students.end(),
              back_inserter(grades), ptrAnalysisMethod);
    return median(grades);

}

void write_analysis(std::ostream& out,
                    const std::string& name,
                    double ptrAnalysisMethod(const Student_info&),
                    const std::vector<Student_info>& did,
                    const std::vector<Student_info>& didnt);

#endif
