#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>

#include "Vec.h"

class Student_info
{
    public:
        // Constructors
        Student_info();
        Student_info(std::istream&);

        // Other
        std::string name() const { return n; }
        bool valid() const { return ! homework.empty(); }

        std::istream& read(std::istream&);
        double grade() const;

        std::string n;
        double midterm, final;
        Vec<double> homework;
};

bool compare(const Student_info&, const Student_info&);

#endif
