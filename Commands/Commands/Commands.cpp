#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Help()
{
	cout << "For Cardinal Directions, use the following commands: North, East, South, West";
	cout << "\nFor Actions, use the following commands: Search, Open, Close, Take, Drop, Eat, Drink, Use";
	cout << "\nYou may only enter one command at a time.";
}

void Use()
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
	do {
		string input; //string for input
		char inputchar; //character for switch statement
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), (int(*)(int))tolower); //convert input to lowercase
		//this if statement assigns a char for use in the switch statement
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
		else if (input == "use")
			inputchar = 'i';
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
		case 'i': Use();
			break;
		case 'u': cout << "Are you sure you want to exit? (Y/N)";
			char quit;
			cin >> quit;
			if (quit == 'y' || quit == 'Y')
			{
				GameOver = 1; break;
			}
			else { cout << "Resuming game..."; }//this is currently broken, outputs "you cannot do that here"... working on a fix...
		case 'v': cout << "You cannot do that here.";
			break;
		case 'w': cout << "Moving North..."; //this is a filler statement until the map and parser are combined
			break;
		case 'x': cout << "Moving East...";
			break;
		case 'y': cout << "Moving South...";
			break;
		case 'z': cout << "Moving West...";
			break;
		default: cout << "didn't work";
			break;
		}
		cout << endl;
	} while (!GameOver);
	system("pause");
	return 0;
}

