#pragma once
#ifndef ITEMS_ARRAY
#define ITEMS_ARRAY
#include <string>
using namespace std;



class Item
{
private:
	string name;
	bool possess;
	int count;

public:
	Item(){}
	Item(string na, int co)
	{
		name = na; count = co;
	}

	void setPossess(bool po)
	{
		po = possess;
	}

	bool getPossess()
	{
		return possess;
	}

	

};



;
#endif
