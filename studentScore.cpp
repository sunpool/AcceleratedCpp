#include <iostream>
#include <numeric>
#include <algorithm>
#include <ios>
#include <iomanip>
// #include <vector>
#include <string>
#include <stdexcept>
#include <fstream>

#include "Student_info.h"
#include "Vec/Vec.h"
// #include "median.h"
// #include "grade.h"
// #include "Handle.h"

using std::cout;
using std::endl;
using std::cin;
using std::streamsize;
using std::setprecision;
using std::string;
// using std::vector;

int main(int argc, char ** argv)
{
    Vec< Student_info > students;
    Student_info sif;

    string::size_type maxl = 0;
    if (argc > 1)
    {
        // string file = argv[1];
        // std::ifstream infile(file.c_str());
        std::ifstream infile(argv[1]);
        if(infile) {
            string str;
            while(getline(infile, str)){
                maxl = std::max(maxl, sif.name().size());
                sif.read_row(str);
                students.push_back(sif);
            }
        } else {
            std::cerr << "Cannot open file " << argv[1] << endl; 
        }
    }
    else
    {
        cout << "Enter student records as: Name midterm final hw1 hw2 hw3 ..." << endl;
        while ( sif.read(cin) )
        {
            maxl = std::max(maxl, sif.name().size());
            students.push_back(sif);
            cout << sif.name() << endl;
        }
    }

    cout << "Total number of students: " << students.size() << endl;
    for (Vec<Student_info>::size_type i = 0; i != students.size(); i++)
    {
        cout << "name: " << students[i].name() << endl;
    }

    streamsize prec = cout.precision();
    cout << setprecision(3);

    std::sort(std::begin(students), std::end(students), Student_info::compare);

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
