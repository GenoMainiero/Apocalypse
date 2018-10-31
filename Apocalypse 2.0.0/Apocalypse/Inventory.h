#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H
#include "ItemsArray.h"
#include <list>
#include <vector>
#include <iostream>
using namespace std;

class Inventory
{
private:
	vector<Item*> itemVector;
public:
	vector<Item*> getInventory()
	{
		return itemVector;
	}
	Item * getItem(int index)
	{
		return itemVector[index];
	}
	void addItem(Item *item)
	{
		itemVector.push_back(item);
		item->setPossess(1);
	}
	void removeItem(Item *item)
	{
		for (int i = 0; i < 20; i++)
		{
			if (itemVector[i]->getName() == item->getName())
				itemVector.erase(itemVector.begin() + i);
			else
				cout << "Item is not in the Inventory";
		}
	}
};
#endif