// simple code for help commands

#include <iostream>
#include <string>

using namespace std;





int main()
{
	//input string from user
	string help;
	
	//video game name
	cout << " Welcome to Apocalypse! " << endl;

	//creates white space
	cout << " \n\n ";
	
	//video game storyline
<<<<<<< HEAD
	cout << "You are currently in a large city following a series of natural disasters.\n You are believed to be the only living person within this city." << endl;
	cout << " There is reason to believe that others may have survived in neighboring cities " << endl;
	cout << " A nearby radio tower can be used to communicate with these survivors.\n Your mission is to find this radio tower and communicate with the other surviors." << endl;
=======
	cout << " You are currently in a large city following a series of natural disasters, you are believed to be the only living person within this city." << endl;
	cout << " There is also reason to believe that others may have also survided in other cities. " << endl;
	cout << " A nearby radio tower can be used to communicate with other survivors, your mission is to find this radio tower and communicate with the other surviors." << endl;
	cout << " However, you will also need to find food and water. " << endl;
>>>>>>> e6c054eec27601207de96233222ef826a9d4174f

	//creates a white space
	cout << " \n\n ";
	
<<<<<<< HEAD
	//video game list of commands shows at start
	cout << "The following are a list of commands to help you navigate through the game:" << endl;  
=======
	//video game lists help commands
	cout << " The following are a list of commands to help you navigate through the game: " << endl;  
>>>>>>> e6c054eec27601207de96233222ef826a9d4174f

	//white space
	cout << " \n\ ";
	
	// How to use Directions
	cout << " For Movement, use the following commands: North, East, South, West, Jump. " << endl;

	// Actions
<<<<<<< HEAD
	cout << " For Actions, use the following commands: Jump, Search, Open, Close, Take, Drop, Eat, Drink, Use" << endl;
=======
	cout << " For Actions, use the following commands: Search, Open, Close, Grab, Drop, Use. " << endl;

	cout << "\n ";

//Program notifies user of help command option
	cout << " If you need help, please type in help. " << endl; 

	getline(cin, help);

	//if else statement makes sure the right word "help" is being typed. 
	if (help == "help")
	{
		cout << " For Movement, use the following commands: North, East, South, West, Jump. " << endl;
		cout << " For Actions, use the following commands: Search, Open, Close, Grab, Drop, Use. " << endl;
	}
	else
	{// while repeats itself until the right word "help" is typed, then it exits.
		while (help != "help")
		{
			cout << " Invalid Input, please type help for the help command " << endl;
			getline(cin, help);
		}
		//once help is typed then show help command again.
		cout << " For Movement, use the following commands: North, East, South, West, Jump. " << endl;
		cout << " For Actions, use the following commands: Search, Open, Close, Grab, Drop, Use. " << endl;
	}

	//other code follows to continue playing the game
>>>>>>> e6c054eec27601207de96233222ef826a9d4174f

	system("pause");
	return 0;

}
