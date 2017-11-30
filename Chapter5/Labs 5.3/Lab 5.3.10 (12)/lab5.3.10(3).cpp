
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class FlightBooking {
public:
	FlightBooking(int id, int capacity);
	void printStatus();
	bool reserveSeats(int seats);
	bool cancelReservations(int seats);
	int GetID()
	{
		return this->id;
	}
private:
	int id;
	int capacity;
	int reserved;
};
void FlightBooking::printStatus()
{
	double resperc = this->reserved;
	double capperc = this->capacity;
	std::cout << "Fligth  " << this->id << " : " << this->capacity << "/" << this->reserved << " (" << (resperc / capperc) * 100 << "%) seats reserved" << std::endl;
}
bool FlightBooking::cancelReservations(int seats)
{
	if (seats < this->reserved && seats>0)
	{
		this->reserved -= seats;
		return true;
	}
	return false;
}
FlightBooking::FlightBooking(int id, int capacity)
{
	this->id = id;
	this->capacity = capacity;
	this->reserved = 0;
}
bool FlightBooking::reserveSeats(int seats)
{
	if (seats > 0)
	{
		if((seats+this->reserved)< (capacity*105/100))
			this->reserved += seats;
		else
			this->reserved = capacity * 105 / 100;
		
		return true;
	}
	return false;
}
int main()
{
	int reserved = 0,
		capasity = 0,
		id = 0,
		seats = 0;
	bool UnknownFlight;
	vector<FlightBooking> AviaLine = vector<FlightBooking>();
	string command = "";
	while (command != "quit")
	{
		UnknownFlight = true;
		cout << "What would you like to do?(hint: to see available commands type '?') " <<endl;
		getline(cin,command);
		if (command == "?")
		{
			cout << "The command create[id][cap] will try to create a new empty flight with ID [id] and capacity [cap]" << endl;
			cout << "The command delete[id] will try to remove the flight with ID [id]" << endl;
			cout << "The command add[id][n] will try to add n reservations to the flight with ID [id]."<<endl;
			cout << "The command cancel[id][n] will try to cancel n reservations from the flight with ID [id]." << endl;
		}
		if (command.find("create") != -1)
		{
			command = command.substr(command.find(" ")+ 1);
			int id = atoi(command.c_str());
			for (int i = 0; i < AviaLine.size(); i++)
			{
				if (AviaLine[i].GetID() == id)
				{
					id += rand() % 100;
					cout << "Your Id wasn't unique. Your new id is: " << id << endl;
					
				}
			}
			command = command.substr(command.find(" ") + 1);
			 capasity = atoi(command.c_str());
			FlightBooking* newFlight= new FlightBooking(id, capasity);
			AviaLine.push_back(*newFlight);
			UnknownFlight = false;
		}
			
		else if (command.find("delete") != -1)
		{
			command = command.substr(command.find(" ") + 1);
			id = atoi(command.c_str());
			for (int i = 0; i < AviaLine.size(); i++)
			{
				if (AviaLine[i].GetID() == id)
				{
					AviaLine.erase(AviaLine.begin()+i);	
					UnknownFlight = false;
					break;
				}
			}
		}
		else if (command.find("add") != -1)
		{
			command = command.substr(command.find(" ") + 1);
			id = atoi(command.c_str());
			command = command.substr(command.find(" ") + 1);
			seats = atoi(command.c_str());
			for (int i = 0; i < AviaLine.size(); i++)
			{
				if (AviaLine[i].GetID() == id)
				{
					AviaLine[i].reserveSeats(seats);
					UnknownFlight = false;
					break;
				}
			}
		}
		else if (command.find("cancel") != -1)
		{
			command = command.substr(command.find(" ") + 1);
			id = atoi(command.c_str());
			command = command.substr(command.find(" ") + 1);
			seats = atoi(command.c_str());
			for (int i = 0; i < AviaLine.size(); i++)
			{
				if (AviaLine[i].GetID() == id)
				{
					AviaLine[i].cancelReservations(seats);
					UnknownFlight = false;
					break;
				}
			}
		}
		else cout << "Unknown command"<<endl;
		for (int i = 0; i < AviaLine.size(); i++)
		{
			AviaLine[i].printStatus();
		}
		if (UnknownFlight)
		{
			cout << "Unknown Flight. Inpun an existing flight id" << endl;
		}
	}
	
	return 0;
}
