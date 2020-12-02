#include "Student_info.h"  // Student_info
#include "grade.h"  // grade
#include "average.h"  // average
 
// Compute the final grade using average of homework
// (S6.2.3/115)
double average_grade(const Student_info& s)
{
  return grade(s.midterm, s.final, average(s.homework));
}
