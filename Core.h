#ifndef Guard_Core_h
#define Guard_Core_h

#include <vector>
#include <string>
#include <iostream>

class Core
{
public:
    Core(): midterm(0), final(0) {};
    Core(std::istream& is) { read(is); };
    ~Core() {};

    // Core(const Core&);
    // Core& operator=(const Core&);

    std::string name() const { return n; };
    bool valid() const { return !hws.empty(); };

    virtual std::istream& read(std::istream&);
    virtual void read_row(std::string&);
    virtual double grade() const;

protected:
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> hws;

private:
    std::string n;
};


class Grad : public Core
{
public:
    Grad(): thesis(0) {};
    Grad(std::istream& is) { read(is); };

    std::istream& read(std::istream&);
    void read_row(std::string&);
    double grade() const;

private:
    double thesis;
};

inline bool compare_name(const Core& a, const Core& b)
{
    return a.name() < b.name();
};

inline bool compare_grade(const Core& a, const Core& b)
{
    return a.grade() < b.grade();
};

// only member function should be able to change the state of the object, so
// move following to member function
// std::istream& read_hw(std::istream&, std::vector<double>& );
// std::istream& read(std::istream&, Core& );

#endif
