#ifndef GUARD_grade
#define GUARD_grade

#include <algorithm>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "median.h"
#include "Student_info.h"


double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& hw);
std::string letter_grade(double grade);

#endif

