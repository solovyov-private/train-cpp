#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

struct Student_info
{
    public:
        std::string name;
        double midterm, final;
        std::vector<double> homework;

        Student_info() { std::cerr << "init" << std::endl; }

        Student_info(const Student_info& z) {
            std::cerr << z.name << " copy" << std::endl; 
            s_copy(z);
        }

        Student_info& operator=(const Student_info& z) {
            if (this != &z) s_copy(z);
            std::cerr << z.name << " copy" << std::endl; 
            return *this;
        }

        ~Student_info() { std::cerr << "destruct" << std::endl; }

    private:
        void s_copy(const Student_info& z) {
            name = z.name;
            midterm = z.midterm;
            final = z.final;
            homework = z.homework;
        }
};

bool compare(const Student_info& x, const Student_info& y);

std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif
