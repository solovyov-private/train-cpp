#ifndef GUARD_grade
#define GUARD_grade

#include <vector>
#include "Student_info.h"

bool fgrade(const Student_info&);
double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

#endif

