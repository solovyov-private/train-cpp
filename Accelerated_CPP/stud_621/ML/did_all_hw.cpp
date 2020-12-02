#include <algorithm>  // find
#include "Student_info.h"  // Student_info
 
// Has the student done all the homework?
// (S6.2.1/110)
bool did_all_hw(const Student_info& s)
{
  return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}
