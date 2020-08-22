#ifndef Guard_Str_h
#define Guard_Str_h

#include "Vec/Vec.h"

class Str final {
        friend std::istream& operator>>(std::istream&, Str&);

    public: 
        typedef Vec<char>::size_type size_type;

        Str(){}
        // note, how data is initialized. data() takes in constructor
        // parameters, no need to do new Vec(), which will be a pointer
        // paramter that matches nothing
        Str(size_type n, char c): data(n, c) {}

        // TODO, what happens to the default copy constructor then? 
        Str(const char* sch) { 
            std::copy(sch, sch + std::strlen(sch), std::back_inserter(data));
        }
        template<class In> Str(In b, In e) {
            std::copy(b, e, std::back_inserter(data));
        }

        Str& operator+=(const Str& b) {
            std::copy(b.data.begin(), b.data.end(), std::back_inserter(data));
            return *this;
        }

        char& operator[](size_type i) {return data[i]; }
        const char& operator[](size_type i) const { return data[i]; }

        size_type size() const { return data.size(); } 
        // void reserve(size_type n) { data.reserve(n); };

    private:
        Vec<char> data;
};

std::ostream& operator<<(std::ostream&, const Str&);
Str& operator+(const Str&, const Str&);

#endif
