#include "Student_info.h"  // Student_info
#include "grade.h"  // grade
#include <stdexcept>  // domain_error
 
using std::domain_error;
 
// Auxiliary function to be parsed as argument to a function
// (S6.2.2/113)
double grade_aux(const Student_info& s)
{
  try {
    return grade(s);
  } catch (domain_error) {
    return grade(s.midterm, s.final, 0);
  }
}
