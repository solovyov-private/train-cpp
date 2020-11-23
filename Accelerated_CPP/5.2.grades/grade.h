#ifndef GUARD_grade
#define GUARD_grade

#include <vector>
#include "Student_info.h"

bool fgrade(const Student_info& s);

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(const Student_info& s);

#endif

