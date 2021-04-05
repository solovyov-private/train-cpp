#ifndef CUSTOM_STR_H
#define CUSTOM_STR_H

#include <algorithm>
#include <cstring>
#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>

class Str
{
friend std::istream& operator>>(std::istream&, Str&);

public:
    typedef char* iterator;
    typedef const char* const_iterator;
    typedef size_t size_type;

    Str() { create(0, '\0'); }

    Str(size_type n, char c) { create(n, c); }

    Str(const Str& s) { create(s.begin(), s.end()); }
    ~Str() { uncreate(); }
    
    Str(const char* cp) { create(cp, cp + std::strlen(cp)); }
    
    template<class In> Str(In b, In e) { create(b, e); }

    char& operator[](size_type i) { return chars[i]; }
    const char& operator[](size_type i) const { return chars[i]; }
    Str& operator=(const Str&);

    const char* c_str() const;
    const char* data() const;
    size_type copy(iterator s, size_type len) const;

    size_type size() const { return length - 1; }

    iterator begin() { return chars; }
    const_iterator begin() const { return chars; }
    iterator end() { return chars + length - 1; }
    const_iterator end() const { return chars + length - 1; }

    Str& operator+=(const Str&);
    
private:
    size_type length;
    iterator chars;
    
    std::allocator<char> alloc;
    
    void create(size_type, char);
    
    template<class In>
    void create(In, In);

    void uncreate();
};


Str& Str::operator=(const Str& rhs)
{
    if (&rhs != this) {
        uncreate();

        create(rhs.begin(), rhs.end());
    }
    return *this;
}

const char* Str::c_str() const
{
    return this->chars;
}

const char* Str::data() const
{
    return this->chars;
}

Str::size_type Str::copy(iterator s, size_type len) const
{
    if (len > size())
        throw std::out_of_range("len to copy > size()");

    std::copy(chars, chars + len, s);
    return len;
}

template<class In>
void Str::create(In b, In e)
{
    length = e - b + 1;
    chars = alloc.allocate(length);
    std::uninitialized_copy(b, e, chars);
    alloc.construct(chars + length - 1, '\0');

}

void Str::create(size_type n, char c)
{
    length = n + 1;
    chars = alloc.allocate(length);
    std::uninitialized_fill(chars, chars + n, c);
    std::uninitialized_fill(chars + n, chars + length, '\0');
}

void Str::uncreate()
{
    if (chars) {
        iterator tmp = chars + length;

        while (tmp != chars)
            alloc.destroy(--tmp);

            alloc.deallocate(chars, length);
    }

    length = 0;
}

Str& Str::operator +=(const Str& s) {
    size_type new_length = length + s.size();
    iterator new_chars = alloc.allocate(new_length);
    std::uninitialized_copy(chars, chars + length - 1, new_chars);
    std::uninitialized_copy(s.begin(), s.end(), new_chars + length - 1);
    alloc.construct(new_chars + new_length - 1, '\0');

    uncreate();

    length = new_length;
    chars = new_chars;
    return *this;
}

Str operator+(const Str& lhs, const Str& rhs)
{
    Str tmp = lhs;
    tmp += rhs;
    return tmp;
}

inline bool operator <(const Str& lhs, const Str& rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) < 0);
}

inline bool operator <=(const Str& lhs, const Str& rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) <= 0);
}

inline bool operator >(const Str& lhs, const Str& rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) > 0);
}

inline bool operator >=(const Str& lhs, const Str& rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) >= 0);
}

inline bool operator ==(const Str& lhs, const Str& rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) == 0);
}

inline bool operator !=(const Str& lhs, const Str& rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) != 0);
}

#endif
