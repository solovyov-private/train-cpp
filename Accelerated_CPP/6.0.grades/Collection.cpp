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

bool pgrade(const Student_info& s)
{
    return !fgrade(s);
}

//
Collection extract_fails(Collection& students) {
    Collection fail;
    remove_copy_if(students.begin(), students.end(),
                   back_inserter(fail), pgrade);
    students.erase(remove_if(students.begin(), students.end(),
                             fgrade), students.end());
    return fail;
}
