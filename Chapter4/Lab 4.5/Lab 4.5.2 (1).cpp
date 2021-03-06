#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool String2Int(const std::string& str, int& result)
{
    std::string::const_iterator i = str.begin();

    if (i == str.end())
        return false;

    bool negative = false;

    if (*i == '-')
    {
        negative = true;
        ++i;

        if (i == str.end())
            return false;
    }

    result = 0;

    for (; i != str.end(); ++i)
    {
        if (*i < '0' || *i > '9')
            return false;

        result *= 10;
        result += *i - '0';
    }

    if (negative)
    {
        result = -result;
    }

    return true;
}
int main(void) {
    string s;
	cout<< "Input Ip Address which you want to check";
    getline(cin,s);
    vector<string> parts = vector<string>();
    string temp;
    int a = 0;
    while (s.find_first_of('.') != string::npos)
    {

        temp = s.substr(0, s.find_first_of("."));
        if (temp.length() > 3)
        {
            cout<< "Too many characters in a part";
            return 0;
        }
        if (!String2Int(temp, a))
        {
            cout<< "Only digits and dots allowed";
            return 0;
        }
        parts.push_back(temp);
        s = s.substr(s.find_first_of(".") + 1);
    }
    parts.push_back(s);
    int result = 0;
    if(parts.size() != 4){
		cout<<"Incorrect parts count.";
		return 0;
	}
	for (int i = 0; i < parts.size(); i++)
    {
        String2Int(parts[i],a);
        if(a > 255 )
        {
            cout<<"Too big a value of a part";
            return 0;
        }

    }
    cout<<"Correct Ip";
	return 0;
}
