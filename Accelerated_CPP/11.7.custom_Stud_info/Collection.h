#ifndef GUARD_Collection_h
#define GUARD_Collection_h

#include <algorithm>
#include <list>
#include <stdexcept>

#include "grade.h"
#include "Student_info.h"
#include "Vec.h"

//typedef std::list<Student_info> Collection;
typedef Vec<Student_info> Collection;

Collection extract_fails(Collection& students,
                         bool ptrCriterion(const Student_info& s));

#endif
