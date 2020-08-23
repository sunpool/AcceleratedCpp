#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include "Core.h"
#include "grade.h"

#include "Str/Str.h"
using myStr = Str;


// global func
std::istream& read_hw(std::istream& in, std::vector<double>& hws)
{
    if (in)
    {
        hws.clear();
        // old way to parse array:
        // double hw;
        // while (in >> hw)
        //     hws.push_back(hw);

        // new way:
        std::copy(std::istream_iterator<double>(in), std::istream_iterator<double>(), std::back_inserter(hws));
        in.clear();
    }
    return in;
}

/*
 * Core
 *
 * */
std::istream& Core::read_common(std::istream& in)
{
    in >> n >> midterm >> final;
    return in;
}

std::istream& Core::read(std::istream& in)
{
    read_common(in);
    read_hw(in, hws);
    return in;
}

// TODO, friend func for ifstream getline in Str class 
void Core::read_row(const std::string& s)
{
    std::istringstream row(s);
    read_common(row);
    ::read_hw(row, hws);
}

double Core::grade() const
{
    return ::grade(midterm, final, hws);
}

/*
 * Grad
 *
 * */
std::istream& Grad::read(std::istream& in)
{
    read_common(in);
    in >> thesis;
    read_hw(in, hws);
    return in;
}

// TODO, friend func for ifstream getline in Str class 
void Grad::read_row(const std::string& s)
{
    std::istringstream row(s);
    read_common(row);
    row >> thesis;
    ::read_hw(row, hws);
}

double Grad::grade() const
{
    return std::min(Core::grade(), thesis);
}
