#include "Student_info.h"
#include <iterator>
#include <algorithm>
#include <sstream>

#include "Core.h"

std::istream& Student_info::read(std::istream& is) {
    char ch; 
    is >> ch; 

    if(ch == 'U')
        pt = new Core(is);
    else 
        pt = new Grad(is); 

    return is;
}

void Student_info::read_row(std::string& st) {
    if( st[0] == 'U' )
        pt = new Core(st.substr(1));
    else 
        pt = new Grad(st.substr(1));
}
