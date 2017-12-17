#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class IpHeader
{
	string sourceIp,DestinationIp;
	bool CheckIp(string ip);
	bool String2Int(const std::string& str, int& result);
public :
	IpHeader(string sourceIp, string DestinationIp)
	{
		try {
			if (!CheckIp(sourceIp))
				throw string("Invalid Ip Header - SourceIp is invalid");
			else if (!CheckIp(DestinationIp))
			{
				throw string("Invalid Ip Header - Destination Ip is invalid");
			}
			else
			{
				this->sourceIp = sourceIp;
				this->DestinationIp = DestinationIp;
				throw string("Valid Ip Header");
			}
		}
		catch (...)
		{
			throw;
		}
	}
};
bool IpHeader::CheckIp(string s)
{
	vector<string> parts = vector<string>();
	string temp;
	int a = 0;
	
		while (s.find_first_of('.') != string::npos)
		{

			temp = s.substr(0, s.find_first_of("."));
			if (temp.length() > 3)
			{
				return false;
				
			}
			if (!this->String2Int(temp, a))
			{
				return false;

			}
			parts.push_back(temp);
			s = s.substr(s.find_first_of(".") + 1);
		}
		parts.push_back(s);
		int result = 0;
		if (parts.size() != 4) {
			return false;

		}
		for (int i = 0; i < parts.size(); i++)
		{
			String2Int(parts[i], a);
			if (a > 255)
			{
				return false;

			}
			
		}
		return true;
	
}
bool IpHeader::String2Int(const std::string& str, int& result) {
	istringstream buffer(str);
	if (!(buffer >> result))
	{
		result = 0;
		return false;
	}
	return true;
}
int main ()
{
	string sourceIp, DestinationIp;

	try {
		cout << "Enter source and destination Ip" << endl;
		getline(cin, sourceIp);
		getline(cin, DestinationIp);
		IpHeader header1(sourceIp, DestinationIp);
	}
	catch (string &exp)
	{
		cout << exp << endl;
	}
	try {
		cout << "Enter source and destination Ip" << endl;
		getline(cin, sourceIp);
		getline(cin, DestinationIp);
		IpHeader header1(sourceIp, DestinationIp);
	}
	catch (string &exp)
	{
		cout << exp << endl;
	}
	return 0;
}