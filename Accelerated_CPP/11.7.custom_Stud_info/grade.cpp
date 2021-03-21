#include "Student_info.h"
#include "grade.h"

using std::domain_error;
using std::find;
using std::map;
using std::string;

double grade(const Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const Vec<double>& hw)
{
    if (hw.size() == 0) {
        throw domain_error("No homework was done.");
    }

    return grade(midterm, final, median(hw));
}
