#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H
#include "ItemsArray.h"
#include <list>
#include <vector>
#include <iostream>
#include "StringClass.h"
using namespace std;

StringContainer * stringContainerInv = new StringContainer();

class Inventory
{
private:
	vector<Item*> itemVector;
public:
	bool itworked = 0;
	vector<Item*> getInventory()
	{
		return itemVector;
	}
	Item * getItem(int index)
	{
		return itemVector[index];
	}
	int getSize()
	{
		return itemVector.size();
	}
	Item * getBack()
	{
		return itemVector.back();
	}
	void addItem(Item *item)
	{
		itemVector.push_back(item);
		item->setPossess(1);
	}
	void removeItem(int index)
	{
		for (int i = 0; i < itemVector.size(); i++)
		{
			if (itemVector[i]->getName() == itemVector[index]->getName())
			{
				itemVector.erase(itemVector.begin() + i);
				itworked = 1;
			}
		}
		/*if (!itworked)
			cout << stringContainerInv->itemNotInInventory;*/
	}
};
#endif