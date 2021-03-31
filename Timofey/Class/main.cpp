#include <iostream>
#include <string>

struct Student
{
    int age;
    std::string name;

    Student (int _age = 0, std::string _name = "") { age = _age; name = _name; }
    ~Student() { }
    void aging() { ++age; }
    void print() const { std::cout << name << " is " << age << " years old." << std::endl; }
};

struct Stack
{
    double* s;
    int allocated;
    int top;
    Stack(int max_size = 100) { s = new double[max_size]; allocated = max_size; top = 0; }
    void push(double x) { if (top < allocated) s[top++] = x; }
    double pop() { if (top == 0) return -1; return s[--top]; }
    ~Stack() { delete[] s; allocated = 0; top = 0; }
};

int main() {
    Student a(17, std::string("Vasya")), b();
    a.aging();
    a.print();

    Student* ps = nullptr;
    ps = new Student(18, "Masha");
    delete ps;

    Stack A(6);

    return 0;
}
