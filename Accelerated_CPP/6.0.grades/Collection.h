#ifndef GUARD_Collection_h
#define GUARD_Collection_h

#include <list>
#include <vector>

#include "grade.h"
#include "Student_info.h"

//typedef std::list<Student_info> Collection;
typedef std::vector<Student_info> Collection;
Collection extract_fails(Collection& students);

#endif
