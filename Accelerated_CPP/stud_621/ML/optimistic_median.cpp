#include <vector>  // vector
#include <algorithm>  // remove_copy, back_inserter
#include "Student_info.h"  // Student_info
#include "grade.h"  // grade
#include "median.h"  // median
 
using std::vector;
 
// median of the nonzero elements of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info& s)
{
  vector<double> nonzero;
  remove_copy(s.homework.begin(), s.homework.end(),
              back_inserter(nonzero), 0);
  if (nonzero.empty())
    return grade(s.midterm, s.final, 0);
  else
    return grade(s.midterm, s.final, median(nonzero));
}
