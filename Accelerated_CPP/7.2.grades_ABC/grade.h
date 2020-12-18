#ifndef GUARD_grade
#define GUARD_grade

#include <algorithm>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "median.h"
#include "Student_info.h"

const std::map<char, std::map<std::string, double> > gradesMap{
    {'A', {{"limitMax", 100.00}, {"limitMin", 90}}},
    {'B', {{"limitMax",  89.99}, {"limitMin", 80}}},
    {'C', {{"limitMax",  79.99}, {"limitMin", 70}}},
    {'D', {{"limitMax",  69.99}, {"limitMin", 60}}},
    {'F', {{"limitMax",  59.99}, {"limitMin",  0}}}
};

bool did_all_hw(const Student_info& s);
bool fgrade(const Student_info& s);
bool pgrade(const Student_info& s);

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(const Student_info& s);
double grade_aux(const Student_info& s);

char gradeToECTC(const double& grade);

#endif

