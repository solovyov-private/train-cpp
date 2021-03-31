#include <iostream>
#include <string>

class Base
{
public:
    void b_pub() {}
private:
    void b_priv() {}
protected:
    void b_prot() {}
};

// class Deriv: private Base // приватное наследование - только для этого класса, для потомков - не
// class Deriv: protected Base // защищенное наследование - доступны для потомков
class Deriv: public Base // публичное наследование
{
public:
    void d_pub() { b_pub(); b_prot(); }

};

class Student
{
private:
    int age;
    std::string name;
public:
    Student(int x, std::string nm): age(x), name(nm) { age = x; name = nm; }
};

class ElderStudent : public Student
{
private:
    int groupID;
public:
    ElderStudent(int x, std::string nm, int gID): Student(x, nm) { groupID = gID; }
};

int main() {
    Base b;
    b.b_pub();
    Deriv d;
    d.d_pub();
    ElderStudent x(1, "cool", 10);
    return 0;
}
