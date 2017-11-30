

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class ShopItemOrder
{
public:
	ShopItemOrder(string name, int qty, int unitprice)
	{
		set_name(name);
		set_qty(qty);
		this->set_unitPrice(unitprice);
	}
	void set_name(string name)
	{
		this->name = name;
	}
	void set_qty(int qty)
	{
		if(qty>0)
			this->qty = qty;
	}
	void set_unitPrice(int unitPrice)
	{
		if(unitPrice>0)
			this->unitPrice = unitPrice;
	}
	string get_name()
	{
		return this->name;
	}
	int get_qty()
	{
		return this->qty;
	}
	int get_unitPrice()
	{
		return this->unitPrice;
	}
	int GetOrderTotalPrice()
	{
		return qty * unitPrice;
	}
	void PrintOrder()
	{
		cout << "Order details: " << endl << "Item name: " << this->name << endl << "item unit price: " << this->unitPrice << endl << "number of items ordered: " << this->qty << endl;
	}
	
private:
	string name;
	int qty;
	int unitPrice;
};
int main()
{
	ShopItemOrder o("Hleb",100 , 10);
	cout << o.GetOrderTotalPrice()<<endl;
	o.PrintOrder();
		return 0;
}



