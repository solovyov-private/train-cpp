#include "Collection.h"
#include "grade.h"

Collection extract_fails(Collection& students) {
    Collection fail;
    Collection::iterator iter = students.begin();

    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else {
            ++iter;
        }
    }
    return fail;
}
