#include <vector>
#include <string>
#include <algorithm>
#include<stdexcept>

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

