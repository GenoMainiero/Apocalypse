// simple code for help commands

#include <iostream>
#include <string>

using namespace std;

int main()
{
	//use string for help command
	string help;
	
	//video game name
	cout << " Welcome to Apocalypse! " << endl;

	//creates white space
	cout << " \n\n ";
	
	//video game storyline
	cout << " You are currently in a large city following a series of natural disasters, you are believed to be the only living person within this city." << endl;
	cout << " There is also reason to believe that others may have also survided in other cities " << endl;
	cout << " A nearby radio tower can be used to communicate with other survivors, your mission is to find this radio tower and communicate with the other surviors." << endl;
	cout << " However, you will also need to find food and water. " << endl;

	//creates a white space
	cout << " \n\n ";
	
	//video game list of commands shows at start
	cout << " The following are a list of commands to help you navigate through the game " << endl;  

	// How to use Directions
	cout << " For Cardinal Directions, use the following commands: North, East, South, West " << endl;

	// Actions
	cout << " For Actions, use the following commands: Throw, Jump, Look, Open, Close, Take, Drop, Eat, Drink " << endl;

	//Program notifies user of help command option
	cout << " If you need help at any time, please type in help " << endl;
	
	// user enters help
	cin >> help;
	
	// returns all of above input/output
	system("pause");
	return 0;

}
