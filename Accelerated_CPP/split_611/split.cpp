#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::find_if;
using std::isspace;
using std::string;
using std::vector;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

bool is_palindrome(const string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

vector<string> split(const string& s)
{
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = s.begin();

    while (i != s.end()) {
        i = find_if(i, s.end(), not_space);

        iter j = find_if(i, s.end(), space);

        if (i != s.end())
            ret.push_back(string(i, j));
        i = j;
    }

    return ret;
}

int main()
{
    string a;
    while (getline(cin, a)) {
    
        vector<string> vec = split(string(a));
    
        for (
                vector<string>::size_type i = 0;
                i != vec.size();
                ++i
            ){
            cout << vec[i] << endl;
        }
    }
}
