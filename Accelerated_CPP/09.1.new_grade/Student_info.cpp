#include "Student_info.h"
#include "grade.h"

using std::istream;
using std::vector;

Student_info::Student_info(): midterm(0), final(0) { }
Student_info::Student_info(istream& is) { read(is); }

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}

double Student_info::grade() const
{
    return total;
}

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        hw.clear();

        double x;
        while (in >> x) {
            hw.push_back(x);
        }

        in.clear();
    }

    return in;
}

istream& Student_info::read(istream& is)
{
    is >> n >> midterm >> final;

    read_hw(is, homework);

    total = ::grade(midterm, final, homework);

    return is;
}
