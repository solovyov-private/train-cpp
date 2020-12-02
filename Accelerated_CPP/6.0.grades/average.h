#ifndef GUARD_average_h
#define GUARD_average_h

#include <numeric>
#include <vector>

#include "grade.h"
#include "Student_info.h"

double average(const std::vector<double>& v);
double average_grade(const Student_info& s);

#endif
