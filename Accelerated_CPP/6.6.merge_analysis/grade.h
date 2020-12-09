#ifndef GUARD_grade
#define GUARD_grade

#include <algorithm>
#include <stdexcept>
#include <vector>

#include "median.h"
#include "Student_info.h"

bool did_all_hw(const Student_info& s);
bool fgrade(const Student_info& s);

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(const Student_info& s);
double grade_aux(const Student_info& s);

#endif

