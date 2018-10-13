//Introduction to Apocalypse, Valid Commands, Help Command, Validating User Input

#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
using namespace std;

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

void Inventory()
{
	cout << "Here is your inventory:\n";
	//possible array of items? or maybe if else for has_item boolean
	string item;
	cout << "Which item would you like to use?\n";
	cin >> item;
	//if in the right room, can use, otherwise, error message
}

void Next()
{
	string Next[4] = { "What would you like to do next?", "What's next?", "Where to now?", "Arrived. Now what would you like to do?" };
	int randNum = rand() % (4);
	cout << Next[randNum];
}

void Error()
{
	string Error[4] = { "You cannot do that here.", "That is an unrecognized command.", "I did not understand what you said.", "Invalid command." };
	int randNum2 = rand() % (4);
	cout << Error[randNum2];
}


int main()
{
	bool GameOver = 0;
	//Game Introduction + Storyline
	//I made the intro look a little cooler. Hope you like it! - Geno
	/*string welcome1 = "Welcome to Apocalypse!";
	string welcome = "\n\nYou are the only living person in a large city following a series of natural disasters.\nThere is reason to believe that others may have survived in neighboring cities.\nA nearby radio tower can be used to communicate with these survivors.\nYour mission is to find this radio tower and get rescued.\n\nThe following is a list of commands to help you navigate through the game:\n";
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
	Sleep(2000);*/ //intro commented out to make debugging easier
	cout << "\n\nYou find yourself standing in the middle of a desolate road. What is your first move?\n " << endl;
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
		{
			exitloop:
			cout << "Are you sure you want to exit? (Y/N)";
			string exit;
			getline(cin, exit);
			if (exit == "y" || exit == "Y")
			{inputchar = 't';}
			else if (exit == "n" || exit == "N")
			{
				cout << "Resuming game...\n";
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
			//food int = food int - 1; cout << "you have "<< food int<< "meals left";
			break;
		case 'h': cout << "Drinking...";
			//water int = water int - 1; cout << "you have "<< water int<< "bottles of water left";
			break;
		case 'i': Inventory();
			break;
		case 'j': cout << "Using...";
			break;
		case 't': cout << "Thanks for playing!";
			GameOver = 1; break;
		case 'u': cout << "Game resumed."; 
			break;
		case 'v': Error();
			break;
		case 'w': cout << "Moving North... "; Next();
			break;
		case 'x': cout << "Moving East... "; Next();
			break;
		case 'y': cout << "Moving South... "; Next();
			break;
		case 'z': cout << "Moving West... "; Next();
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
