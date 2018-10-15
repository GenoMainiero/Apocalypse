#pragma once
#ifndef LOCATIONS_H
#define LOCATIONS_H

#include <iostream>
#include <string>
using namespace std;


class Room
{
	string description;
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
	// Can be used to change the description of a room
	void setDescription(string d)
	{
		description = d;
	}
	// reads description of a room.
	void Describe()
	{
		cout << description << endl;
	}

};

// Used to move between rooms
Room* Movement(Room* locale, string direction)
{
	if (direction[0] == 'n')
	{
		locale = locale->North;
	}
	else if (direction[0] == 'e')
	{
		locale = locale->East;
	}
	else if (direction[0] == 's')
	{
		locale = locale->South;
	}
	else if (direction[0] == 'w')
	{
		locale = locale->West;
	}
	else
	{
		locale = locale;
	}
	return locale;

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