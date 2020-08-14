#include <stdexcept> 
#include <vector> 

#include "grade.h"
#include "Student_info.h" 
#include "median.h"

using std::vector;

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
