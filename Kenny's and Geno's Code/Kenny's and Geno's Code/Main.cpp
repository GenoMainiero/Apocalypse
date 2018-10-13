//Introduction to Apocalypse, Valid Commands, Help Command, Validating User Input

#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
using namespace std;

void Output(string s)
{
	int x = 0; int randNum = rand() % (4);
	while (s[x] != '\0')
	{
		cout << s[x];
		Sleep(50 + rand() % 50);
		x++;
	}
}

void Help()
{
	cout << "                                   Help Menu                      " << endl;
	cout << "                                  -----------                     ";
	cout << "\nTo move throughout the city, use the following commands: North, East, South, West";
	cout << "\nTo interact with items, use the following commands: Search, Open, Close, Take, Drop, Eat, Drink, Use";
	cout << "\nTo show your inventory, type inventory. ";
	cout << "\nYou may only enter one command per line.";
	cout << "\nTo exit the game at any time, type exit or quit.";
}

void MoveHelp()
{
	cout << "To move throughout the city, use the following commands: North, East, South, West";
	cout << "\nFor more help at any time, type help.";
}

void Use()
{
	string item;
	Output("Which item would you like to use?\n");
	cin >> item;
	//if in the right room, can use, otherwise, error message
}

void Inventory()
{
	Output("Here is your inventory:\n");
	//possible array of items? or maybe if else for has_item boolean
	//Will update when Eyad posts objects for inventory
}

void Next()
{
	//These strings can be outputted after descriptions of areas are read
	string Next[4] = { "What would you like to do next?", "What's next?", "Where to now?", "Arrived. Now what would you like to do?" };
	int randNum = rand() % (4);
	int x = 0;
	string NextA = Next[randNum];
	Output(NextA);
}

void Description(int b)
{
	string Description[1] = { "This is a sample description." };
	Output(Description[b]);
}

void Movement(int a)
{
	string Movement[4] = { "A chemical spill blocks your path. There is no way around it.", "Ahead is a flood that may be electrified. You'd better not risk it.",
		"It's too dark to see anything...", "There are several burning buildings in this direction, but one looks mostly undamaged." };
	Output(Movement[a]);
}

void Error()
{
	string Error[4] = { "You cannot do that here.", "That is an unrecognized command.", "I did not understand what you said.", "Invalid command." };
	int randNum2 = rand() % (4);
	int x = 0;
	string ErrorA = Error[randNum2];
	Output(ErrorA);
}


int main()
{
	bool GameOver = 0;
	//Game Introduction + Storyline
	//I made the intro look a little cooler. Hope you like it! - Geno
	string welcome1 = "Welcome to Apocalypse!";
	string welcome = "\n\nYou are the only living person in a large city following a series of natural disasters.\nThere is reason to believe that others have survived in neighboring cities.\nA nearby radio tower can be used to communicate with these survivors.\nYour mission is to find this radio tower and get rescued.\n\nThe following is a list of commands to help you navigate through the game:\n";
	int x = 0;
	while (welcome1[x] != '\0')
	{
		cout << welcome1[x];
		Sleep(50 + rand() % 50);
		x++;
	}
	x = 0; Sleep(1000);
	while (welcome[x] != '\0')
	{
		cout << welcome[x];
		Sleep(25 + rand() % 50);
		x++;
	}
	Sleep(750);
	Help();
	Sleep(2000);
	Output("\n\nYou find yourself standing in the middle of a desolate road. What is your first move?\n");
	//intro can be commented out to make debugging easier (line 90-109) with /* text */
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
		else if (input == "move")
			inputchar = 's';
		else if (input == "exit" || input == "quit")
		{
			exitloop:
			cout << "Are you sure you want to exit? (Y/N)";
			string exit;
			getline(cin, exit);
			if (exit == "y" || exit == "Y")
			{inputchar = 't';}
			else if (exit == "n" || exit == "N")
			{
				Output("Resuming game...\n");
				inputchar = 'u';
				Sleep(1000);
			}
			else
			{
				Error();
				cout << endl;
				goto exitloop;
			}
		}
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
		case 'b': Output("Searching..."); //filler statement until inventory is added
			break;
		case 'c': Output("Opening...");
			break;
		case 'd': Output("Closing...");
			break;
		case 'e': Output("Taking...");
			break;
		case 'f': Output("Dropping...");
			break;
		case 'g': Output("Eating...");
			//food int = food int - 1; cout << "you have "<< food int<< "meals left";
			break;
		case 'h': Output("Drinking...");
			//water int = water int - 1; cout << "you have "<< water int<< "bottles of water left";
			break;
		case 'i': Inventory();
			break;
		case 'j': Inventory(); Use();
			break;
		case 's': MoveHelp();
			break;
		case 't': Output("Thanks for playing!");
			GameOver = 1; break;
		case 'u': Output("Game resumed."); 
			break;
		case 'v': Error();
			break;
		//For cases w-z, function Movement() can be used to output prewritten errors/information
		//A similar function Description() will output the description of the room the first time it is visited. 
		case 'w': Output("Moving North... "); /*if canmove, output description then output next-> */ Next();
			//else, run function Movement(); takes integer depending on error ie. 1 = chemical spill, 2 = electrified water, etc...
			break;
		case 'x': Output("Moving East... "); Next();
			break;
		case 'y': Output("Moving South... "); Next();
			break;
		case 'z': Output("Moving West... "); Next();
			break;	
		default: Error();
			break;
		}
		cout << endl;
		} while (!GameOver);
		system("pause");
		return 0;
		// Still waiting for more action commands so we can add more code...
	}
