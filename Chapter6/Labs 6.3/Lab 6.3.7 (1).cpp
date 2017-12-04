#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class IpAddress
{
protected:
	string _ipaddr;

public:
	IpAddress(string ipaddr)
	{
		this->_ipaddr = ipaddr;
	}
	IpAddress(IpAddress &Ipaddr)
	{
		IpAddress* newIp = new IpAddress(Ipaddr._ipaddr);
	}
	
	void PrintIp()
	{
		cout << this->_ipaddr<< endl;
	}
};
class IPAddressChecked :public IpAddress
{
	bool String2Int(const std::string& str, int& result);
	bool CheckIP();

public:
	IPAddressChecked(string ip):IpAddress(ip){}
	void PrintIp()
	{
		if(CheckIP())
			cout << this->_ipaddr<<" - Correct" << endl;
		else
			cout << this->_ipaddr << " - Not Correct" << endl;
	}
};
bool IPAddressChecked::String2Int(const std::string& str, int& result)
{
	istringstream buffer(str);
	if (!(buffer >> result))
	{
		result = 0;
		return false;
	}
	if (result < 0)
	{
		result = -result;
	}
	return true;
}
bool IPAddressChecked::CheckIP()
{
	vector<string> parts = vector<string>();
	string temp, s;
	s = _ipaddr;
	
	int a = 0;
	while (s.find_first_of('.') != string::npos)
	{

		temp = s.substr(0, s.find_first_of("."));
		if (temp.length() > 3)
		{
			return false;
		}
		if (!String2Int(temp, a))
		{
			return false;
		}
		parts.push_back(temp);
		s = s.substr(s.find_first_of(".") + 1);
	}
	parts.push_back(s);
	int result = false;
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
int main(void) {
	cout << "Input IP address you don't want to check" << endl;
	string ip1;
	getline(cin, ip1);
	IpAddress first(ip1);
	first.PrintIp();
	cout << "Input 2  IP addresses that you  want to check" << endl;
	string ip2,ip3;
	getline(cin, ip2);
	getline(cin, ip3);
	IPAddressChecked second(ip2), third(ip3);
	second.PrintIp();
	third.PrintIp();
	return 0;
}
