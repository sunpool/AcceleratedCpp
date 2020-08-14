#ifndef Guard_grade
#define Guard_grade

#include <vector>
#include <string>
#include <iostream>
#include "Student_info.h"

double grade(double , double , double );
double grade(double , double , const std::vector<double>& );
double grade( const Student_info& );

#endif
