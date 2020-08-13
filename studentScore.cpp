#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <string>
#include<stdexcept>

using std::cout;
using std::endl;
using std::cin;
using std::streamsize;
using std::setprecision;
using std::string;
using std::vector;

struct Student_info
{
    string name;
    double midterm, final;
    vector<double> hws;
};

double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if ( size == 0)
        throw std::domain_error("Median of empty vector is undefinded");

    // auto cmp = [](const Student_info& a, const Student_info& b) {
    //     return a.name < b.name;
    // }
    std::sort(begin(vec), end(vec));
    vec_sz mid = size / 2;

    return size & 1 ? vec[mid] : (vec[mid + 1] + vec[mid]) / 2.0;
}


double grade(double midterm, double final, double hw)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * hw;
}

double grade(double mid, double final, const vector<double>& hws)
{
    if (hws.size() == 0)
        throw std::domain_error("student has done no homework");
    return grade(mid, final, median(hws));
}

double grade( const Student_info& s)
{
    return grade(s.midterm, s.final, s.hws);
}

std::istream& read_hw(std::istream& in, vector<double>& hws)
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

std::istream& read(std::istream& in, Student_info& s)
{
    cout << "Enter Name, midterm score, and final score: " << endl;
    in >> s.name >> s.midterm >> s.final;
    cout << "Enter homework scores: " << endl;
    read_hw(in, s.hws);
    return in;
}

int main()
{
    vector<Student_info> students;
    Student_info sif;

    while ( read(cin, sif))
    {
        students.push_back(sif);
    }

    streamsize prec = cout.precision();
    cout << setprecision(3);
    // cout << "size of students: " << students.size() << endl;

    for (auto& s : students)
    {
        try
        {
            double final_grade = grade(s);
            cout << s.name << ": " << final_grade << endl;
        }
        catch (std::domain_error e)
        {
            cout << "Error: " << endl;
            cout << e.what() << endl;
        }
    }
    cout << setprecision(prec) << endl;
    cout << "完成!" << endl;
    return 0;
}
