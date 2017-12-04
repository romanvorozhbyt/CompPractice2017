#include <iostream>
#include <string>
#include <regex>
using namespace std;
class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(string input) = 0;
};
class ExactValidator : public StringValidator {
	string _password;
public :
	ExactValidator(string pass)
	{
		_password = pass;
	}
	virtual bool isValid(string input);

};
bool ExactValidator::isValid(string input)
{
	return _password._Equal(input);
}

class DummyValidator : public StringValidator {
public:
	virtual bool isValid(string input);
};
bool DummyValidator::isValid(string input)
{
	return true;
}

// Your code here

void printValid(StringValidator &validator, string input)
{
	cout << "The string '" << input << "' is "
		<< (validator.isValid(input) ? "valid" : "invalid")<<endl;
}
int main()
{
	
	DummyValidator dummy;
	printValid(dummy, "hello");
	cout << endl;
	ExactValidator exact("secret");
	printValid(exact, "hello");
	printValid(exact, "secret"); 
	return 0;
}