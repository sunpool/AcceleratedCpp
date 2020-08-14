#include <iostream>
#include <numeric>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <vector>
#include <string>
#include <stdexcept> 

#include "Student_info.h" 
#include "median.h"
#include "grade.h"

using std::cout;
using std::endl;
using std::cin;
using std::streamsize;
using std::setprecision;
using std::string;
using std::vector;

int main()
{
    vector<Student_info> students;
    Student_info sif;

    string::size_type maxl = 0;
    cout << "Enter student records as: Name midterm final hw1 hw2 hw3 ..." << endl;
    while ( sif.read(cin) )
    {
        maxl = std::max(maxl, sif.name().size());
        students.push_back(sif);
        cout << sif.name() << endl;
    }
    cout << "Total number of students: " << students.size() << endl;
    for(vector<Student_info>::size_type i = 0; i != students.size(); i++){
        cout << "name: " << students[i].name() << endl; 
    }

    streamsize prec = cout.precision();
    cout << setprecision(3);

    std::sort(begin(students), end(students), compare);

    for (auto& s : students)
    {
        try
        {
            double final_grade = s.grade();
            cout << s.name()
                 << string( maxl + 1 - s.name().size(), ' ')
                 << ": " << final_grade << endl;
        }
        catch (std::domain_error e)
        {
            cout << "Error: " << endl;
            cout << e.what() << endl;
            return 1;
        }
    }
    cout << setprecision(prec) << endl;
    cout << "完成!" << endl;
    return 0;
}
