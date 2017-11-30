#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Member {
public:
	Member(int id, string name);
	void printStatus();
	bool ExtendMembership(int monthes);
	bool CancelMembership();
	int GetID()
	{
		return this->id;
	}
private:
	int id;
	string name;
	int membership;
};
void Member::printStatus()
{
	std::cout << "Member   " << this->id << " :  name - " << this->name <<" subscription valid for "<<this->membership<<" monthes."<<endl;
}
bool Member::CancelMembership()
{
	if (membership != 0)
	{
		membership = 0;
		return true;
	}
	return false;
}
Member::Member(int id, string name)
{
	this->id = id;
	this->name = name;
	this->membership = 0;
}
bool Member::ExtendMembership(int monthes)
{
	if (monthes > 0)
	{
		this->membership += monthes;
		
		return true;
	}
	return false;
}
int main()
{
	int id = 0,
		membership = 0;
	string name = "";
	bool unknownMember;
	vector<Member> Gym = vector<Member>();
	string command = "";
	while (command != "quit")
	{
		unknownMember = true;
		cout << "What would you like to do?(hint: to see available commands type '?') " <<endl;
		getline(cin,command);
		if (command == "?")
		{
			cout << "the command 'create[id][name]' will try to create a new member with ID [id], name [name] and 0 months of subscription;" << endl;
			cout << "The command delete[id] will try to remove the member with ID [id]" << endl;
			cout << "The command extend [id][n] will try to extend the membership number of months of the member by [n]."<<endl;
			cout << "The command cancel[id][n] will try to set the number of months of subscription to 0 of the member with the ID [id]." << endl;
		}
		if (command.find("create") != -1)
		{
			command = command.substr(command.find(" ")+ 1);
			int id = atoi(command.c_str());
			for (int i = 0; i < Gym.size(); i++)
			{
				if (Gym[i].GetID() == id)
				{
					id += rand() % 100;
					cout << "Your Id wasn't unique. Your new id is: " << id << endl;
					
				}
			}
			name = command.substr(command.find(" ") + 1);
			Member* newFlight= new Member(id, name);
			Gym.push_back(*newFlight);
			unknownMember = false;
		}
			
		else if (command.find("delete") != -1)
		{
			command = command.substr(command.find(" ") + 1);
			id = atoi(command.c_str());
			for (int i = 0; i < Gym.size(); i++)
			{
				if (Gym[i].GetID() == id)
				{
					Gym.erase(Gym.begin()+i);
					unknownMember = false;
					break;
				}
			}
		}
		else if (command.find("extend") != -1)
		{
			command = command.substr(command.find(" ") + 1);
			id = atoi(command.c_str());
			command = command.substr(command.find(" ") + 1);
			membership = atoi(command.c_str());
			for (int i = 0; i < Gym.size(); i++)
			{
				if (Gym[i].GetID() == id)
				{
					Gym[i].ExtendMembership(membership);
					unknownMember = false;
					break;
				}
			}
		}
		else if (command.find("cancel") != -1)
		{
			command = command.substr(command.find(" ") + 1);
			id = atoi(command.c_str());
			for (int i = 0; i < Gym.size(); i++)
			{
				if (Gym[i].GetID() == id)
				{
					Gym[i].CancelMembership();
					unknownMember = false;
					break;
				}
			}
		}
		else cout << "Unknown command"<<endl;
		for (int i = 0; i < Gym.size(); i++)
		{
			Gym[i].printStatus();
		}
		if (unknownMember)
		{
			cout << "Unknown Flight. Inpun an existing flight id" << endl;
		}
	}
	
	return 0;
}
