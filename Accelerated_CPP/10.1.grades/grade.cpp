#include "grade.h"

using std::domain_error;
using std::find;
using std::map;
using std::string;
using std::vector;

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0) {
        throw domain_error("No homework was done.");
    }

    return grade(midterm, final, median(hw));
}

string letter_grade(double grade)
{
    static const double numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };

    static const char* const letters[] = {
        "A+", "A", "A-",
        "B+", "B", "B-",
        "C+", "C", "C-",
        "D", "F"
    };

    static const size_t ngrades = sizeof(numbers) /
                                    sizeof(*numbers);

    for (size_t i = 0; i < ngrades; ++i) {
        if (grade >= numbers[i]) {
            return letters[i];
        }
    }

    return "\?\?\?";
}
