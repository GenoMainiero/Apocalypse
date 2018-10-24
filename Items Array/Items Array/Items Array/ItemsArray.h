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
	void setName( string na)
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

	bool getPosses()
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



;
#endif
