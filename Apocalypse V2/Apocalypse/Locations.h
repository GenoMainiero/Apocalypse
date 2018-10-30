#pragma once
#ifndef LOCATIONS_H
#define LOCATIONS_H
#include <Windows.h>
#include <iostream>
#include <string>
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

class Room
{
	string description;
	//used to tell if a room is actually a blockage
	bool isBlockage;
public:
	Room* North;
	Room* South;
	Room* East;
	Room* West;
	// Default constructor. Gives dummy description and set all ptrs to null
	Room()
	{
		North = South = East = West = nullptr;
		description = "STANDIN DESCRIPTION\n";
	}
	// Constructor to give new room a description when declared.
	Room(string d)
	{
		North = South = East = West = nullptr;
		description = d;
	}
	Room(string d, bool b)
	{
		North = South = East = West = nullptr;
		isBlockage = b;
		description = d;
	}
	// Can be used to change the description of a room
	void setDescription(string d)
	{
		description = d;
	}
	// reads description of a room.
	void Describe()
	{
		Outputt(description);
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
	Outputt("\nBlocked by ");
	switch (stoppage)
	{
	case 1:
		Outputt("flood.\n");
		break;
	case 2:
		Outputt("Chemical Spill.\n");
		break;
	case 3:
		Outputt("a large fire!\n");
		break;
	case 4:
		Outputt("rubble.\n");
		break;
	default:
		Outputt("something.\n");
		break;
	}
	Outputt("Returning to previous location..."); Sleep(500);
}

/*
bool Blocked(Room* hinder)
{
	string answer = "";
	hinder->Describe();
	cout << "Are you sure you would like to go this way? This could prove to be fatal.\n(Y/N):\t";
	while (1 > 0)
	{
		cin >> answer;
		if (answer == "y" || "Y")
		{
			// Insert Death Function
			return 1;
		}
		else if (answer == "n" || "N")
		{
			cout << "You turn back to your previous location.\n";
			return 0;
		}

	}
}
*/
// Used to move between rooms
Room* Movement(Room* locale, string direction)
{
	bool status = 0;
	if (direction == "north")
	{
		if (locale->North == nullptr)
		{
			EdgeOfMap(4);
		}
		else if (locale->North->getStatus() == 1)
		{
			// Filler statement until death function is clarified
			cout << "Cannot go that way.\n";
		}
		else
		{
			locale = locale->North;
		}
		return locale;
	}
	else if (direction == "east")
	{
		if (locale->East == nullptr)
		{
			EdgeOfMap(2);
			return locale;
		}
		else
		{
			locale = locale->East;
			return locale;
		}
	}
	else if (direction == "south")
	{
		if (locale->South == nullptr)
		{
			EdgeOfMap(1);
			return locale;
		}
		else
		{
			locale = locale->South;
			return locale;
		}
	}
	else if (direction == "west")
	{
		if (locale->West == nullptr)
		{
			EdgeOfMap(3);
			return locale;
		}
		else
		{
			locale = locale->West;
			return locale;
		}
	}
	else
	{
		cout << "Command not recognized...\n";
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