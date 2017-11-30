#include <iostream>
#include <string>
using namespace std;
const double sheepneed = 0.11, horseneed = 0.068, cowneed = 0.086;
class FarmAnimal {
public:
	FarmAnimal(double water_consumption, double weight);
	double getWaterConsumption();
	double getWeight();
private:
	double water_consumption;
	double weight;
};
FarmAnimal::FarmAnimal(double water_consumption, double weight)
{
	this->water_consumption = water_consumption;
	this->weight = weight;
}

double FarmAnimal::getWaterConsumption() 
{
	return water_consumption;
}

double FarmAnimal::getWeight()
{
	return weight;
}

class Sheep : public FarmAnimal
{
public:
	Sheep(double weight) : FarmAnimal(sheepneed, weight) { }
};

class Horse : public FarmAnimal
{
public:
	Horse(double weight) : FarmAnimal(horseneed, weight) { }
};

class Cow : public FarmAnimal
{
public:
	Cow(double weight) : FarmAnimal(cowneed, weight) { }
};

class ConsumptionAccumulator
{
public:  ConsumptionAccumulator();
	double getTotalConsumption();
	void addConsumption(FarmAnimal animal);
private:
	double total_consumption;
};
ConsumptionAccumulator::ConsumptionAccumulator() : total_consumption(0) { }
double ConsumptionAccumulator::getTotalConsumption()
{
	return total_consumption;
}
void ConsumptionAccumulator::addConsumption(FarmAnimal animal) 
{ 
	total_consumption += animal.getWaterConsumption() * animal.getWeight();
}
int main() {
	ConsumptionAccumulator accumulator;
	string line;
	int indx = 0;
	cout << "Input the animal and it's weight in format [animal] [weight].(For examle: sheep 80)" << endl;
	do
	{
		getline(cin, line);
		if (line.find("sheep") != string::npos)
		{
			
			indx = line.find("sheep");
			Sheep sh(atof((line.substr(indx + 6, line.length() - indx - 5)).c_str()));
			accumulator.addConsumption(sh);
		}
		if (line.find("horse") != string::npos)
		{
			indx = line.find("horse");
			Horse h(atof((line.substr(indx + 6, line.length() - indx - 5)).c_str()));
			accumulator.addConsumption(h);
		}
		if (line.find("cow") != string::npos)
		{
			indx = line.find("cow");
			Horse h(atof((line.substr(indx + 4, line.length() - indx - 3)).c_str()));
			accumulator.addConsumption(h);
		}
	} while (!line.empty());
	cout << "Your animal(s) need the " << accumulator.getTotalConsumption() << " L of water" << endl;
	return 0;
}