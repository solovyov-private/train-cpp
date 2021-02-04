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

template<class T, class S>
void write_analysis(std::ostream& out,
                    const std::string& name,
                    T ptrAnalysisMethod(const S&),
                    const std::vector<S>& did,
                    const std::vector<S>& didnt)
{
    out << name << ": median(did) = " << doAnalysis(did, ptrAnalysisMethod)
        << ", median(didnt) = " << doAnalysis(didnt, ptrAnalysisMethod) << std::endl;
}

#endif
