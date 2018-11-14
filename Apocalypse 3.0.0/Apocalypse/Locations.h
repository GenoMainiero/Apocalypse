#pragma once
#ifndef LOCATIONS_H
#define LOCATIONS_H
#include <Windows.h>
#include <iostream>
#include <string>
#include "Inventory.h"
#include "StringClass.h"
using namespace std;

void Outputt(string s)
{
	int x = 0; int randNum = rand() % (4);
	while (s[x] != '\0')
	{
		cout << s[x];
		Sleep(25 + rand() % 25);
		x++;
	}
}

StringContainer * stringContainerLoc = new StringContainer();

class Room
{
	string description;
	string shortDesc;
	//used to tell if a room is actually a blockage
	bool isBlockage;
	bool toShort;
	// the below two bools are used to keep track if food/water has already been taken from a room
	bool firstf;
	bool firstw;
public:
	Room* North;
	Room* South;
	Room* East;
	Room* West;
	Inventory Stock;
	// Default constructor. Gives dummy description and set all ptrs to null
	Room()
	{
		North = South = East = West = nullptr;
		description = shortDesc = stringContainerLoc->standInDescription;
		firstf = firstw = toShort = 0;
	}
	// Constructor to give new room a description when declared.
	Room(string d)
	{
		North = South = East = West = nullptr;
		shortDesc = description = d;
	}
	Room(string d, bool b)
	{
		North = South = East = West = nullptr;
		isBlockage = b;
		shortDesc = description = d;
	}
	bool getfirstf() { return firstf; }
	bool getfirstw() { return firstw; }
	void setfirstf(bool f) { firstf = f; }
	void setfirstw(bool w) { firstw = w; }

	bool getShort() { return toShort; }
	void setShort(bool s) { toShort = s; }

	// Can be used to change the description of a room
	void setDescription(string d)
	{
		description = d;
	}
	void setShortDesc(string banana)
	{
		shortDesc = banana;
	}
	// reads description of a room.
	void Describe()
	{
		if (toShort == 0)
		{
			cout << description;
			//Outputt(description);
		}
		else
		{
			cout << shortDesc;
			//Outputt(shortDesc);
		}
		Outputt("\n");
	}
	void setStatus(bool b)
	{
		isBlockage = b;
	}
	bool getStatus()
	{
		return isBlockage;
	}
};

void EdgeOfMap(int stoppage)
{
	Outputt(stringContainerLoc->blockedByOutput);
	switch (stoppage)
	{
	case 1:
		Outputt(stringContainerLoc->floodOutput);
		break;
	case 2:
		Outputt(stringContainerLoc->chemicalSpillOutput);
		break;
	case 3:
		Outputt(stringContainerLoc->largeFireOutput);
		break;
	case 4:
		Outputt(stringContainerLoc->rubbleOutput);
		break;
	default:
		Outputt(stringContainerLoc->somethingOutput);
		break;
	}
	Outputt(stringContainerLoc->previousLocationOutput); Sleep(500);
}


bool Blocked()
{
	string deathAnswer;
	cout << stringContainerLoc->locationWarning;
	while (deathAnswer != "y" || "Y" || "n" || "N")
	{
		getline(cin, deathAnswer);
		switch (deathAnswer[0])
		{
		case 'y':
			return 1;
			break;
		case 'Y':
			return 1;
			break;
		case 'n':
			return 0;
			break;
		case 'N':
			return 0;
		default:
			Outputt(stringContainerLoc->answerQuestion);
			break;
		}
	}
}


// Used to move between rooms
Room* Movement(Room* locale, string direction)
{
	bool status = 0;
	if (direction == stringContainerLoc->north)
	{
		if (locale->North == nullptr)
		{
			EdgeOfMap(4);
		}
		else if (locale->North->getStatus() == 1)
		{
			locale->North->Describe();
			status = Blocked();
			if (status == 0)
			{
				Outputt(stringContainerLoc->returningOutput);
				return locale;
			}
			else
			{
				return locale->North;
			}
			
		}
		else
		{
			locale = locale->North;
		}
		return locale;
	}
	else if (direction == stringContainerLoc->east)
	{
		if (locale->East == nullptr)
		{
			EdgeOfMap(2);
			return locale;
		}
		else if (locale->East->getStatus() == 1)
		{
			locale->East->Describe();
			status = Blocked();
			if (status == 0)
			{
				Outputt(stringContainerLoc->returningOutput);
				return locale;
			}
			else
			{
				return locale->East;
			}
		}
		else
		{
			locale = locale->East;
			return locale;
		}
		return locale;
	}
	else if (direction == stringContainerLoc->south)
	{
		if (locale->South == nullptr)
		{
			EdgeOfMap(1);
			return locale;
		}
		else if (locale->South->getStatus() == 1)
		{
			locale->South->Describe();
			status = Blocked();
			if (status == 0)
			{
				Outputt(stringContainerLoc->returningOutput);
				return locale;
			}
			else
			{
				return locale->South;
			}
		}
		else
		{
			locale = locale->South;
			return locale;
		}
		return locale;
	}
	else if (direction == stringContainerLoc->west)
	{
		if (locale->West == nullptr)
		{
			EdgeOfMap(3);
			return locale;
		}
		else if (locale->West->getStatus() == 1)
		{
			locale->West->Describe();
			status = Blocked();
			if (status == 0)
			{
				Outputt(stringContainerLoc->returningOutput);
				return locale;
			}
			else
			{
				return locale->West;
			}
		}
		else
		{
			locale = locale->West;
			return locale;
		}
		return locale;
	}
	else
	{
		cout << stringContainerLoc->commandNotRecognizedOutput;
		return locale;
	}
}


// Used to connect the rooms together
void Connect(Room* room1, string direction, Room* room2)
{
	if (direction[0] == 'n')
	{
		room1->North = room2;
		room2->South = room1;
	}
	else if (direction[0] == 'e')
	{
		room1->East = room2;
		room2->West = room1;
	}
	else if (direction[0] == 's')
	{
		room1->South = room2;
		room2->North = room1;
	}
	else if (direction[0] == 'w')
	{
		room1->West = room2;
		room2->East = room1;
	}
}
#endif