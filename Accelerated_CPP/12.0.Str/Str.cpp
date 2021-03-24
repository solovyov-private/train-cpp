#include <algorithm>
#include <cstring>
#include <iostream>
#include "Vec.h"

class Str
{
    friend std::istream& operator>>(std::istream&, Str&);
public:
    Str& operator+=(const Str& s) {
        std::copy(s.data.begin(), s.data.end(),
                  std::back_inserter(data));
        return *this;
    }

    typedef Vec<char>::size_type size_type;

    Str() { }

    Str(size_type n, char c): data(n, c) { }

    Str(const char* cp) {
        std::copy(cp, cp + std::strlen(cp),
                  std::back_inserter(data));
    }

    template<class In>
    Str(In b, In e) {
        std::copy(b, e, std::back_inserter(data));
    }

    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }

    size_type size() const { return data.size(); }

private:
    Vec<char> data;
};

std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);

std::istream& operator>>(std::istream& is, Str& s)
{
    s.data.clear();

    char c;
    while (is.get(c) && isspace(c))
        ;

    if (is) {
        do s.data.push_back(c);
        while (is.get(c) && ! isspace(c));

        if (is)
            is.unget();
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Str& s)
{
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

Str operator+(const Str& s, const Str& t){
    Str r = s;
    r += t;
    return r;
}

int main()
{
    Str x;
    std::cin >> x;
    x += "xyi";
    std::cout << x[1] << std::endl;
    std::cout << x << std::endl;
}
