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
	Item()
	{
		name = "dummy item";
		possess = 0;
		count = 0;
	}
	Item(string na, bool po, int c)
	{
		name = na; possess = po; count = c;
	}
	void setName(string na)
	{
		na = name;
	}
	string getName()
	{
		return name;
	}

	void setPossess(bool po)
	{
		po = possess;
	}

	bool getPossess()
	{
		return possess;
	}

	void setCount(int co)
	{
		co = count;
	}

	int getCount()
	{
		return count;
	}

};
#endif