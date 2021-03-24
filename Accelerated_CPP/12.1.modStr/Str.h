#ifndef CUSTOM_STR_H
#define CUSTOM_STR_H

#include <algorithm>
#include <cstring>
#include <cstddef>
#include <iostream>
#include <memory>

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
    
        char& operator[](size_type i) { return data[i]; }
        const char& operator[](size_type i) const { return data[i]; }
    
        size_type size() const { return length - 1; }

	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return data + length - 1; }
	const_iterator end() const { return data + length - 1; }

        Str& operator+=(const Str&);
    
    private:
	size_type length;
        iterator data;

	std::allocator<char> alloc;

	void create(size_type, char);

	template<class In> void create(In, In);
	void uncreate();
};



template<class In>
void Str::create(In b, In e)
{
    length = e - b + 1;
    data = alloc.allocate(length);
    std::uninitialized_copy(b, e, data);
    alloc.construct(data + length - 1, '\0');

}

void Str::create(size_type n, char c)
{
    length = n + 1;
    data = alloc.allocate(length);
    std::uninitialized_fill(data, data + n, c);
    std::uninitialized_fill(data + n, data + length, '\0');
}

void Str::uncreate()
{
    if (data) {
	std::cout << length << std::endl;
	iterator tmp = data + length;
        while (tmp != data)
            alloc.destroy(--tmp);

        alloc.deallocate(data, length);
    }

    length = 0;
}


#endif
