#include <iostream>  // ostream, endl;
#include <vector>  // vector
#include <string>  // string
#include "Student_info.h"  // Student_info
 
using std::ostream;
using std::endl;
using std::string;
using std::vector;
 
// Output result to compare the two groups of students who did and
// who didn't do all of their homework.
// (S6.2.3/113)
void write_analysis(ostream& out,
                    const string& name,
                    double analysis(const vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt)
{
  out << name << ": median(did) = " << analysis(did) <<
                 ": median(didnt) = " << analysis(didnt) << endl;
  return;
}
