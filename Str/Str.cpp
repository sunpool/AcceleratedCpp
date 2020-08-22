#include "Str/Str.h"
#include "Vec/Vec.h"
#include <iostream>

// Str& Str::operator=(const Str& str) {
//     if(this != &str){
//         data.uncreate();
//         data.create(str.data.begin(), str.data.end());
//     }
// }

std::ostream& operator<<(std::ostream& os, const Str& str) {
    // for(auto& c: str.data) // fail due to "data" is private member
    for(auto i = 0; i != str.size(); i++)
        os << str[i];
        // *os++ = c; // should be recursive down as above 
    return os;
}

std::istream& operator>>(std::istream& is, Str& str){
    if(is) {
        str.data.clear();

        char c; 
        while( is.get(c) && isspace(c) );
        
        if(is) {
            do str.data.push_back(c); 
            while( is.get(c) && !isspace(c) );

            if(is)
                is.unget();
        }
        return is;
    }
}

Str& operator+(const Str& a, const Str& b) {
    Str c = a; 
    a += b; 
    return a;
}
