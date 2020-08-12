#include <iostream>
#include <vector>
#include <numeric>    
#include <algorithm>
#include <ios>
#include <iomanip>
#include <string>

using std::cout;     using std::endl;   using std::cin; 
using std::streamsize;      using std::setprecision;
using std::string;
using std::vector;

int main()
{
    cout << "enter student name: " << endl; 
    string name; 
    cin >> name; 

    double midterm, final; 
    cout << "enter midterm and final exam score: " << endl;
    cin >> midterm >> final; 

    vector<double> hws; 
    double hw; 
    cout << "Enter all homework grades, " "end by end of file: ";
    while(cin >> hw){
        hws.push_back(hw); 
    }
    std::copy(hws.begin(), hws.end(), std::ostream_iterator<double>(cout, ", "));

    streamsize prec = cout.precision(); 
    cout << "Your final grade is " << setprecision(3) 
        << 0.2 * midterm + 0.4 * final + 0.4 * std::accumulate(hws.begin(), hws.end(), 0.0) / hws.size() 
        << setprecision(prec) << endl; 

    return 0;
}
