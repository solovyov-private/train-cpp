#include <vector>  // vector
#include <algorithm>  // transform
#include "Student_info.h"  // Student_info
#include "grade_aux.h"  // grade
#include "median.h"  // median
 
using std::vector;
using std::transform;
 
// S6.2.2/112
double median_analysis(const vector<Student_info>& students)
{
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
  return median(grades);
}
