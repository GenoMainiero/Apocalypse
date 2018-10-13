//Introduction to Apocalypse, Valid Commands, Help Command, Validating User Input

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Help()
{
	cout << "For Cardinal Directions, use the following commands: North, East, South, West";
	cout << "\nFor Actions, use the following commands: Search, Open, Close, Take, Drop, Eat, Drink, Use";
	cout << "\nYou may only enter one command at a time.";
	cout << "\nTo exit the game at any time, type exit.";
	cout << "\nTo show your inventory, type inventory. ";
}

void Inventory()
{
	cout << "Here is your inventory:\n";
	//possible array of items? or maybe if else for has_item boolean
	string item;
	cout << "Which item would you like to use?\n";
	cin >> item;
	//if in the right room, can use, otherwise, error message
}


int main()
{
	bool GameOver = 0;
	
	//Game Introduction + Storyline
		cout << " Welcome to Apocalypse! \n\n " << endl;
		cout << " You are currently the only living person in a large city following a series of natural disasters. " << endl;
		cout << " There is also reason to believe that others may have also survided in other cities. " << endl;
		cout << " A nearby radio tower can be used to communicate with other survivors. " << endl;
		cout << " Your mission is to find this radio tower and communicate with the other survivors." << endl;
		cout << " However, you will also need to find food and water. " << endl;
		cout << " \nThe following is a list of commands to help you navigate through the game:\n " << endl;
		Help();

		cout << "\n\n As you begin by standing in the middle of the road, what is your first move?\n " << endl;

	do {
		string input; //string for input
		char inputchar; //character for switch statement
		getline(cin, input);
		
		//converts input to lowercase this if statement assigns a char for use in the switch statement
		transform(input.begin(), input.end(), input.begin(), (int(*)(int))tolower); 

		if (input == "help")
			inputchar = 'a';
		else if (input == "search")
			inputchar = 'b';
		else if (input == "open")
			inputchar = 'c';
		else if (input == "close")
			inputchar = 'd';
		else if (input == "take")
			inputchar = 'e';
		else if (input == "drop")
			inputchar = 'f';
		else if (input == "eat")
			inputchar = 'g';
		else if (input == "drink")
			inputchar = 'h';
		else if (input == "inventory")
			inputchar = 'i';
		else if (input == "use")
			inputchar = 'j';
		else if (input == "exit" || input == "quit")
			inputchar = 'u';
		else if (input == "north")
			inputchar = 'w';
		else if (input == "east")
			inputchar = 'x';
		else if (input == "south")
			inputchar = 'y';
		else if (input == "west")
			inputchar = 'z';
		else
		{
			inputchar = 'v';
		}

		//this is the heart of the text parser, which accepts the char and controls what happens next
		switch (inputchar)
		{
		case 'a': Help();
			break;
		case 'b': cout << "Searching..."; //filler statement until inventory is added
			break;
		case 'c': cout << "Opening...";
			break;
		case 'd': cout << "Closing...";
			break;
		case 'e': cout << "Taking...";
			break;
		case 'f': cout << "Dropping...";
			break;
		case 'g': cout << "Eating...";
			break;
		case 'h': cout << "Drinking...";
			break;
		case 'i': Inventory();
			break;
		case 'j': cout << "Using...";
			break;
		case 'u': cout << "Are you sure you want to exit? (Y/N)";
			char quit;
			cin >> quit;
				if (quit == 'y' || quit == 'Y')
				{
					GameOver = 1; 
					break;
				}
				else
				{
					cout << "Resuming game..."; //needs to be fixed...
					break;
				}
				break;	
		case 'v': cout << "Invalid Command! ";
			break;
		case 'w': cout << "Moving North... What would you like to do next?"; //this is a filler statement until the map and parser are combined
			break;
		case 'x': cout << "Moving East... What now? ";
			break;
		case 'y': cout << "Moving South... Where to now?";
			break;
		case 'z': cout << "Moving West... arrived, now what would you like to do?";
			break;	
		default: cout << "Not a valid command.."; 
			break;
		}
		cout << endl;
		} while (!GameOver);
		system("pause");
		return 0;
		// Still waiting for more action commands so we can add more code...
	}
