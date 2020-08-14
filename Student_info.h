#ifndef Guard_Student_info
#define Guard_Student_info

#include <vector>
#include <string>
#include <iostream>

struct Student_info
{
    std::string name;
    double midterm, final;
    std::vector<double> hws;
};

std::istream& read_hw(std::istream& , std::vector<double>& );
std::istream& read(std::istream& , Student_info& );

#endif
