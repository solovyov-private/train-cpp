#include <vector>  // vector
#include <algorithm>  // transform
#include "Student_info.h"  // Student_info
#include "average_grade.h"  // average_grade
#include "median.h"  // median
 
using std::vector;
using std::transform;
 
// Perform average analysis
// (S6.2.3/115)
double average_analysis(const vector<Student_info>& students)
{
  vector<double> grades;
  transform(students.begin(), students.end(),
            back_inserter(grades), average_grade);
  return median(grades);
}
