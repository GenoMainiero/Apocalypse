#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Help()
{
	cout << "For Cardinal Directions, use the following commands: North, East, South, West";
	cout << "\nFor Actions, use the following commands: Jump, Search, Open, Close, Take, Drop, Eat, Drink, Use";
}


int main()
{
	bool GameOver = 0;
	do {
		string input; //string for input
		char inputchar; //character for switch statement
		cin >> input; // accept input
		transform(input.begin(), input.end(), input.begin(), (int(*)(int))tolower); //convert input to lowercase
		//this if statement assigns a char for use in the switch statement
		if (input == "help")
			inputchar = 'a';
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
		{inputchar = 'v';}
		//this is the heart of the text parser, which accepts the char and controls what happens next
		switch (inputchar)
		{
		case 'a': Help();
			break;
		case 'u': cout << "Are you sure you want to exit? (Y/N)";
			char quit;
			cin >> quit;
			if (quit == 'y' || quit == 'Y')
				GameOver = 1; break;
			break;
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

