
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
class MinLengthValidator : public StringValidator
{
	int _minSize;
public:
	MinLengthValidator(int minSize)
	{
		_minSize = minSize;
	}
	bool isValid(string input)
	{
		return input.size() > _minSize;
	}
};
class MaxLengthValidator : public StringValidator
{
	int _maxSize;
public:
	MaxLengthValidator(int maxSize)
	{
		_maxSize = maxSize;
	}
	bool isValid(string input)
	{
		return input.size() < _maxSize;
	}
};
class PatternValidator : public StringValidator
{
private:
	string pattern;
public:
	PatternValidator(string pattern)
	{
		regReplace(pattern, "D", "[0-9]");
		regReplace(pattern, "A", "\\w");
		regReplace(pattern, "?", ".");
		this->pattern = pattern;
	}
	void regReplace(string &pattern, string symbol, string regsymb)
	{
		int prev = 0;
		int index = pattern.find(symbol, prev);
		while (index != -1)
		{
			pattern.replace(index, 1, regsymb);
			prev = index;
			index = pattern.find(symbol, prev);
		}
	}
	bool isValid(string input)
	{
		regex rgx(pattern);
		smatch match;
		return regex_search(input, rgx);

	}
};

// Your code here

void printValid(StringValidator &validator, string input)
{
	cout << "The string '" << input << "' is "
		<< (validator.isValid(input) ? "valid" : "invalid")<<endl;
}
int main()
{
	cout << "MinLengthValidator" << endl;
	MinLengthValidator min(6);
	printValid(min, "hello");
	printValid(min, "welcome");
	cout << endl;
	cout << "MaxLengthValidator" << endl;
	MaxLengthValidator max(6);
	printValid(max, "hello");
	printValid(max, "welcome");
	cout << endl;
	cout << "PatternValidator" << endl;
	PatternValidator digit("D");
	printValid(digit, "there are 2 types of sentences in the world");
	printValid(digit, "valid and invalid ones");
	cout << endl;
	return 0;
}
