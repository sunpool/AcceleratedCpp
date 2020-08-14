#include "Student_info.h"

using std::string;
using std::vector;
using std::istream;

istream& read_hw(istream& in, vector<double>& hws)
{
    if (in)
    {
        hws.clear();
        double hw;
        while (in >> hw)
            hws.push_back(hw);
        in.clear();
    }
    return in;
}

istream& read(istream& in, Student_info& s)
{
    // cout << "Enter Name, midterm score, and final score: " << endl;
    in >> s.name >> s.midterm >> s.final;
    // cout << "Enter homework scores: " << endl;
    read_hw(in, s.hws);
    return in;
}



