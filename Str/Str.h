#ifndef Guard_Str_h
#define Guard_Str_h

#include "Vec/Vec.h"
#include "Handle.h"

class Str final {
    public: 
        typedef Vec::size_type size_type;

        friend std::istream& operator>>(Str&);

        Str(){};
        Str(size_type n, char c): data(new Vec(n, c)) {};
        // what happens to data that created at initialization stage?
        Str(const Str& str) { data.create(str.data.begin(), str.data.end()); };
        ~Str(){};

        Str& operator=(const Str&);

        size_type size() const { return data.size(); }; 
        void reserve(size_type n) { data.reserve(n); };

    private:
        Vec<char> data;
};

std::ostream& operator<<(std::ostream& os, const Str& str);
Str& operator+(const Str& a, const Str& b);

#endif
