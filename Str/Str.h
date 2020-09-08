#ifndef Guard_Str_h
#define Guard_Str_h

#include "../Vec/Vec.h"
// #include "../Vec/Vec_clone.cpp"
#include <iostream>
#include <algorithm>
#include "../Handle.h"

// NOTE: no includesion of the Vec_clone.cpp file, but implicitly need the .o
// file at link time
// error message was saying there are duplicated definition
template<>
Vec<char>* clone(const Vec<char>* );

class Str final {
        friend std::istream& operator>>(std::istream&, Str&);
        friend bool operator<(const Str&, const Str&);

    public: 
        typedef Vec<char>::size_type size_type;
        typedef char* iterator;
        typedef const char* const_iterator;
        typedef char& reference;
        typedef const char const_reference;
        typedef char value_type;

        Str(): data(new Vec<char>){}
        // note, how data is initialized. data() takes in constructor
        // parameters, no need to do new Vec(), which will be a pointer
        // paramter that matches nothing
        Str(size_type n, char c): data(new Vec<char>(n, c)) {}

        // TODO, what happens to the default copy constructor then? 
        Str(const char* sch): data(new Vec<char>) { std::copy(sch, sch + std::strlen(sch), std::back_inserter(*data));
        }
        template<class In> Str(In b, In e): data(new Vec<char>) {
            std::copy(b, e, std::back_inserter(*data));
        }

        Str& operator+=(const Str& b) {
            data.make_unique(); 
            std::copy(b.begin(), b.end(), std::back_inserter(*data));
            return *this;
        }

        // used in < operator for lexicographical_compare()
        iterator begin() { return data->begin(); }
        const_iterator begin() const { return data->begin(); }
        iterator end() { return data->end(); }
        const_iterator end() const { return data->end(); }

        // // auto converter to std::string for fns like cout << std.name();
        // operator std::string() { return std::string(begin(), end()); }

        char& operator[](size_type i) {
            data.make_unique();
            return (*data)[i]; 
        }
        const char& operator[](size_type i) const { return (*data)[i]; }

        size_type size() const { return data->size(); } 
        // void reserve(size_type n) { data.reserve(n); };

    private:
        Handle<Vec<char>> data;
};

std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);

#endif
