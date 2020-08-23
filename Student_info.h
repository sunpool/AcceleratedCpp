#ifndef Guard_Student_info
#define Guard_Student_info

#include <vector>
#include <string>
#include <iostream>

#include "Handle.h"
#include "Core.h"

#include "Str/Str.h"
using myStr = Str;

class Student_info
{
public:
    Student_info() {}; 
    Student_info(std::istream& is) { read(is); };

    myStr name() const { return pt ? pt->name() : throw std::runtime_error("uninitialized student"); };
    // bool valid() const { return !hws.empty(); };
    std::istream& read(std::istream&); 
    void read_row(std::string&); 
    double grade() const { return pt ? pt->grade() : throw std::runtime_error("uninitialized student"); };

    static bool compare(const Student_info& a, const Student_info& b) {
        return a.name() < b.name();
    }

private:
    Handle<Core> pt; 
};

auto compare = [](const Student_info& a, const Student_info& b)
{
    return a.name() < b.name();
};
std::istream& read_hw(std::istream&, std::vector<double>& );
// std::istream& read(std::istream&, Student_info& );

#endif
