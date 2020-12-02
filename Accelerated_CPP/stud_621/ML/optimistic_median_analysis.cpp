#include <vector>  // vector
#include <algorithm>  // transform
#include "Student_info.h"  // Student_info
#include "optimistic_median.h" // optimistic_median
#include "median.h"  // median
 
using std::vector;
using std::transform;
 
// Auxiliary function
// (S6.2.3/115) - adjust accordingly
double optimistic_median_analysis(const vector<Student_info>& students)
{
  vector<double> grades;
  transform(students.begin(), students.end(),
            back_inserter(grades), optimistic_median);
  return median(grades);
}
