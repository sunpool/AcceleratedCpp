#ifndef Guard_Student_info
#define Guard_Student_info

#include <vector>
#include <string>
#include <iostream>

class Student_info
{
public:
    Student_info(): midterm(0), final(0) {};
    Student_info(std::istream& is) { read(is); };

    // Student_info(const Student_info&);
    // Student_info& operator=(const Student_info&);

    bool valid() const { return !hws.empty(); };
    std::istream& read(std::istream&);
    void read_row(std::string&);
    double grade() const;
    std::string name() const { return n; };

private:
    std::string n;
    double midterm, final;
    std::vector<double> hws;
};

auto compare = [](const Student_info& a, const Student_info& b)
{
    return a.name() < b.name();
};
std::istream& read_hw(std::istream&, std::vector<double>& );
std::istream& read(std::istream&, Student_info& );

#endif
