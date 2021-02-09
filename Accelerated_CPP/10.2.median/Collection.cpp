#include "Collection.h"

// OLD VARIANT
//Collection extract_fails(Collection& students) {
//    Collection fail;
//    Collection::iterator iter = students.begin();
//
//    while (iter != students.end()) {
//        if (fgrade(*iter)) {
//            fail.push_back(*iter);
//            iter = students.erase(iter);
//        } else {
//            ++iter;
//        }
//    }
//    return fail;
//}

// variant 1
//Collection extract_fails(Collection& students) {
//    Collection fail;
//    remove_copy_if(students.begin(), students.end(),
//                   back_inserter(fail), pgrade);
//    students.erase(remove_if(students.begin(), students.end(),
//                             fgrade), students.end());
//    return fail;
//}

// variant 2
Collection extract_fails(Collection& students,
                         bool ptrCriterion(const Student_info& s)) {
    Collection::iterator iter;

    iter = stable_partition(students.begin(),
                            students.end(), ptrCriterion);

    Collection fail(iter, students.end());
    students.erase(iter, students.end());
    return fail;
}
