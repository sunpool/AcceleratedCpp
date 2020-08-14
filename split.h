#include <string>
#include <iterator>
#include <cctype>
#include <algorithm>

bool non_space(char ch)
{
    return ! isspace(ch);
}

bool is_space(char ch)
{
    return isspace(ch);
}

/* 
 * Example usage: 
 * string str;
 * while(getline(cin,str))
 *  split(str, ostream_iterator<string>(cout, " "));
 *
 * split(str, back_inserter(vec))
 *
 *  */
template<class Out>
void split(const string& str, Out os)
{
    typedef std::string::const_iterator iter;

    iter i = str.begin();
    while ( i != str.end())
    {
        i = find_if(i, end(str), non_space);

        iter j = find_if(i, end(str), is_space);

        if (i != j )
            *os++ = std::string(i, j);

        i = j;
    }
}
