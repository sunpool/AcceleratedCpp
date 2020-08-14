#include "Student_info.h"
#include <iterator>
#include <algorithm>
#include <sstream>
#include "grade.h"

using std::string;
using std::vector;
using std::istream;
using std::istream_iterator;
using std::back_inserter;

istream& read_hw(istream& in, vector<double>& hws)
{
    if (in)
    {
        hws.clear();
        // old way to parse array:
        // double hw;
        // while (in >> hw)
        //     hws.push_back(hw);

        // new way:
        std::copy(istream_iterator<double>(in), istream_iterator<double>(), back_inserter(hws));
        in.clear();
    }
    return in;
}

double Student_info::grade() const
{
    return ::grade(midterm, final, hws);
}

std::istream& Student_info::read(std::istream& in)
{
    in >> n >> midterm >> final;
    ::read_hw(in, hws);
    return in;
}

void Student_info::read_row(string& s)
{
    std::istringstream row(s);
    row >> n >> midterm >> final;
    ::read_hw(row, hws);
}
