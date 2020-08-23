#ifndef Guard_Core_h
#define Guard_Core_h

#include <vector>
#include <iostream>

// Str/Str.h is not compitable with ifstream and istringstream fns yet
#include <string>
#include "Str/Str.h"
using myStr = Str;

class Core
{
public:
    Core(): midterm(0), final(0) {}
    Core(std::istream& is) { read(is); }
    // if non-const fns parameter, later you cannot call like new
    // Core(str.substr(1));
    Core(const std::string& st) { read_row(st); }

    // Core(const Core&);
    // Core& operator=(const Core&);

    myStr name() const { return n; }
    bool valid() const { return !hws.empty(); }

    virtual std::istream& read(std::istream&);
    // note: if parameter is not const, then cannot use temporary input like
    // read_row( string(i, j);
    virtual void read_row(const std::string&);
    virtual double grade() const;
    virtual ~Core() {}

protected:
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> hws;

private:
    myStr n;
};


class Grad : public Core
{
public:
    Grad(): thesis(0) {}
    Grad(std::istream& is) { read(is); }
    Grad(const std::string& st) { read_row(st); }

    std::istream& read(std::istream&);
    void read_row(const std::string&);
    double grade() const;

private:
    double thesis;
};

inline bool compare_name(const Core& a, const Core& b)
{
    return a.name() < b.name();
}

inline bool compare_grade(const Core& a, const Core& b)
{
    return a.grade() < b.grade();
}

// only member function should be able to change the state of the object, so
// move following to member function
// std::istream& read_hw(std::istream&, std::vector<double>& );
// std::istream& read(std::istream&, Core& );

#endif
