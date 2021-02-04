#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

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

        bool passed() const;

    private:
        std::string n;
        double midterm, final;
        std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);

#endif
