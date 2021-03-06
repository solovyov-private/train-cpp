#include "Student_info.h"
#include "grade.h"

#include "Vec.h"

using std::istream;

Student_info::Student_info(): midterm(0), final(0) { }
Student_info::Student_info(istream& is) { read(is); }

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}

double Student_info::grade() const
{

    return ::grade(midterm, final, homework);
}

istream& read_hw(istream& in, Vec<double>& hw)
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

    return is;
}
