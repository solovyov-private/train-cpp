#ifndef GUARD_grade
#define GUARD_grade

#include <algorithm>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "median.h"
#include "Student_info.h"
#include "Vec.h"


double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const Vec<double>& hw);
double grade(const Student_info& s);
bool fgrade(const Student_info& s);

#endif

