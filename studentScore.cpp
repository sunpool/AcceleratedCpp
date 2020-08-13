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

double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if ( size == 0)
        throw std::domain_error("Median of empty vector is undefinded");

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

int main()
{
    cout << "enter student name: " << endl;
    string name;
    cin >> name;

    double midterm, final;
    cout << "enter midterm and final exam score: " << endl;
    cin >> midterm >> final;
    cout << midterm << final << endl;

    vector<double> hws;
    double hw;
    cout << "Enter all homework grades, " "end by end of file: ";
    while (cin >> hw)
    {
        hws.push_back(hw);
    }
    std::copy(hws.begin(), hws.end(), std::ostream_iterator<double>(cout, ", "));

    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << grade(midterm, final, hws)
         << setprecision(prec) << endl;

    return 0;
}
