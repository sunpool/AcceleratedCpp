#include "Str/Str.h"
#include "Vec/Vec.h"


Str& Str::operator=(const Str& str) {
    if(this != &str){
        data.uncreate();
        data.create(str.data.begin(), str.data.end()); 
    }
}

std::instream& operator>>(std::instream& is, Str& str) {

} 

std::ostream& operator<<(std::ostream& os, const Str& str) {
    if(os) {
        os << str.c_str();
    }

    return os;
}

