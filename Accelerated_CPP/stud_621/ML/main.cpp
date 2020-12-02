#include <iostream>  // cin, cout, endl
#include <vector>  // vector
 
#include "Student_info.h"  // Student_info
#include "did_all_hw.h"  // did_all_hw
#include "write_analysis.h"  // write_analysis
 
#include "median_analysis.h"  // median_analysis
#include "average_analysis.h"  // average_analysis
#include "optimistic_median_analysis.h"  // optimistic_median_analysis
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
 
// Compare the Grading Scheme
// (S6.2.3/114)
int main()
{
  // students who did and didn't do all their homework
  vector<Student_info> did, didnt;
 
  // read the student records and partition them
  Student_info student;
  while (read(cin, student)) {
    if (did_all_hw(student))
      did.push_back(student);
    else
      didnt.push_back(student);
  }
 
  // verify that the analyses will show us something
  if (did.empty()) {
    cout << "No student did all the homework!" << endl;
    return 1;
  }
  if (didnt.empty()) {
    cout << "No student did all the homework!" << endl;
    return 1;
  }
 
  // do the analyses
  write_analysis(cout, "median", median_analysis, did, didnt);
  write_analysis(cout, "average", average_analysis, did, didnt);
  write_analysis(cout, "median of homework turned in",
                 optimistic_median_analysis, did, didnt);
 
  return 0;
}
