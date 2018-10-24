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
<<<<<<< HEAD
	Item(){}
	Item(string na, int co)
=======
	void setName(string na)
>>>>>>> 87aa550f047ba0acc1b41b0ffe74724c0a47d0e5
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
