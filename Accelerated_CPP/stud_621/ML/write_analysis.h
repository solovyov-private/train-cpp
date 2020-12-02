#ifndef GUARD_WRITE_ANALYSIS_H
#define GUARD_WRITE_ANALYSIS_H
 
// write_analysis.h
 
#include <iostream>  // ostream;
#include <vector>  // vector
#include <string>  // string
#include "Student_info.h"  // Student_info
 
void write_analysis(std::ostream&,
                    const std::string&,
                    double analysis(const std::vector<Student_info>&),
                    const std::vector<Student_info>&,
                    const std::vector<Student_info>&);
 
#endif // GUARD_WRITE_ANALYSIS_H
