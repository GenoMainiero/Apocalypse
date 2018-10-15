

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
	Room()
	{
		North = South = East = West = nullptr;
		description = "STANDIN DESCRIPTION\n";
	}
	Room(string d)
	{
		North = South = East = West = nullptr;
		description = d;
	}
	void setDescription(string d)
	{
		description = d;
	}
	void Describe()
	{
		cout << description << endl;
	}
	Room* Move(Room* locale, string direction)
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
};

int main1()
{
	string input;
	Room* testRoom = new Room();
	Room* theRoom = new Room("This is the first area. Wassup?");
	Room* leftRoom = new Room("Room to the west of start; a dead end");
	Room* rightRoom = new Room("Room to the east of start; a dead end");
	Room* upRoom = new Room("Room to the north of start; a dead end");
	Room* downRoom = new Room("Room to the south of start; a dead end");

	theRoom->West = leftRoom;
	leftRoom->East = theRoom;
	theRoom->East = rightRoom;
	rightRoom->West = theRoom;
	theRoom->North = upRoom;
	upRoom->South = theRoom;
	theRoom->South = downRoom;
	downRoom->North = theRoom;

	while (1 > 0)
	{
		theRoom->Describe();
		cout << "What direction do you wish to travel?" << endl;
		cin >> input;
		testRoom = theRoom->Move(theRoom, input);
		if (theRoom == testRoom || testRoom == nullptr)
		{
			cout << "Cannot go that way" << endl;
		}
		else
			theRoom = testRoom;
		if (input == "exit")
			break;
	}

	system("pause");
	return 0;
}
