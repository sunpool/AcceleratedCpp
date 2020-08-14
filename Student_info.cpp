#include "Student_info.h"
#include <iterator>

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
        copy(istream_iterator<double>(in), istream_iterator<double>(), back_inserter(hws));
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



