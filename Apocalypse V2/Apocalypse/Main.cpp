#include "Locations.h"
#include "Inventory.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;
bool DebugMode = 0;
bool tapet = 0, radiot = 0, glovest = 0, lightt = 0, breadt = 0, watert = 0;
bool firsttime = 0;
bool glovesu = 0, radfix = 0, lightu = 0;
Inventory inv;

string LowerCase(string l)
{
	transform(l.begin(), l.end(), l.begin(), (int(*)(int))tolower);
	return l;
}

void Output(string s)
{
	if (DebugMode == 0)
	{
		int x = 0; int randNum = rand() % (4);
		while (s[x] != '\0')
		{
			cout << s[x];
			Sleep(25 + rand() % 25);
			x++;
		}
	}
	else if (DebugMode == 1)
	{
		cout << s;
	}
}

void Take(string t)
{
	if (t == "food" || t == "bread")
	{
		inv.setFood(inv.getFood() + 1);
		breadt = 1;
	}
	else if (t == "water")
	{
		inv.setWater(inv.getWater() + 1);
		watert = 1;
	}
	else if (t == "crowbar")
	{
		inv.setCrowBar(1);
	}
	else if (t == "gloves")
	{
		inv.setElectricalInsulatingGloves(1); 
		glovest = 1;
	}
	else if (t == "tape")
	{
		inv.setElectricalTape(1);
		tapet = 1;
	}
	else if (t == "flashlight")
	{
		inv.setFlashLight(1);
		lightt = 1;
	}
	else if (t == "radio")
	{
		inv.setRadio(1);
		radiot = 1;
	}
	Output("Adding to inventory..."); Sleep(500);
	Output("\nSuccessfully added to inventory.");
}

void Help()
{
	cout << "                                   Help Menu                      " << endl;
	cout << "                                  -----------                     ";
	cout << "\nTo move throughout the city, use the following commands: North, East, South, West";
	cout << "\nTo interact with items, use the following commands: Search, Take, Eat, Drink, Use";
	cout << "\nTo show your inventory, type inventory or inv.";
	cout << "\nTo show your current location, type location.";
	cout << "\nYou may only enter one command per line.";
	cout << "\nTo exit the game at any time, type exit or quit.";
}

void MoveHelp()
{
	Output("To move throughout the city, use the following commands: North, East, South, West");
	Output("\nFor more help at any time, type help.");
}

string Use()
{
	string item;
	Output("Which item would you like to use?\n");
	cin >> item;
	//if in the right room, can use, otherwise, error message
	transform(item.begin(), item.end(), item.begin(), (int(*)(int))tolower);
	return item;
}

void InventoryCheck()
{
	Output("Here is your inventory:\n");
	cout << "Food: " << inv.getFood() << "     ";
	cout << "Water: " << inv.getWater() << endl;
	if (inv.getCrowBar())
		cout << "Crowbar\n";
	if (glovest == 1)
		cout << "Electrical Insulating *Gloves*\n";
	if (tapet == 1)
		cout << "Electrical *Tape*\n";
	if (lightt == 1)
		cout << "Flashlight\n";
	if (radiot == 1)
		cout << "Radio\n";
}

void Next()
{
	//These strings can be outputted after descriptions of areas are read
	string Next[4] = { "What would you like to do next?", "What's next?", "What is your next move?", "Now what would you like to do?" };
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

void ErrorInv()
{
	Output("You do not have this item.");
}

int main()
{
	bool gameover = 0;
	bool restart = 0; //to "die" or restart, use "restart = 1". all variables will reset and intro will play.

	while (!gameover)
	{
		tapet = 0, radiot = 0, glovest = 0, lightt = 0, breadt = 0, watert = 0;
		firsttime = 0;
		glovesu = 0, radfix = 0, lightu = 0;
		restart = 0;
		if (firsttime == 0)
		{
			inv.setFood(3); inv.setWater(1);
			firsttime = 1;
		}
		string item;
		Room* street = new Room("\nYou find yourself standing in the middle of a desolate road. In front of you is a radio tower.");
		Room* safeHouse = new Room("\nA safe house full of useful things.");
		Room* radioTower = new Room("\nYou enter a radio tower, but it is too dark to see anything.");

		if (lightu == 1)
		{
			Room* radioTower = new Room("\nA radio tower illuminated by your flashlight.");
		}
		else
		{
			Room* radioTower = new Room("\nYou enter a radio tower, but it is too dark to see anything.");
		}

		Connect(street, "west", safeHouse);
		Connect(street, "north", radioTower);

		Room* current = street;
		//Game Introduction + Storyline
		//I made the intro look a little cooler. Hope you like it! - Geno
		string welcome1 = "Welcome to Apocalypse!";
		string welcome = "\n\nYou are the only living person in a large city following a series of natural disasters.\nThere is reason to believe that others have survived in neighboring cities.\nA nearby radio tower can be used to communicate with these survivors.\nYour mission is to find this radio tower and get rescued.\n\nThe following is a list of commands to help you navigate through the game:\n";
		if (DebugMode == 0)
		{
			int x = 0;
			while (welcome1[x] != '\0')
			{
				cout << welcome1[x];
				Sleep(25 + rand() % 25);
				x++;
			}
			x = 0; Sleep(1000);
			while (welcome[x] != '\0')
			{
				cout << welcome[x];
				Sleep(25 + rand() % 25);
				x++;
			}
			Sleep(750);
			Help();
			Sleep(2000);

			Output("\n\nYou find yourself standing in the middle of a desolate road. What is your first move?\n");
		}
		else if (DebugMode == 1)
		{
			cout << welcome1 << welcome;
			Help();
			cout << "\n\nYou find yourself standing in the middle of a desolate road. What is your first move?\n";
		}
		//intro can be commented out to make debugging easier (line 90-109) with /* text */
		while (!gameover && !restart)
		{
			string input; //string for input
			string yn;
			char inputchar; //character for switch statement
			getline(cin, input);

			//converts input to lowercase this if statement assigns a char for use in the switch statement
			input = LowerCase(input);
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
			else if (input == "inventory" || input == "inv")
				inputchar = 'i';
			else if (input == "use")
				inputchar = 'j';
			else if (input == "location")
				inputchar = 'k';
			else if (input == "move")
				inputchar = 's';
			else if (input == "exit" || input == "quit")
			{
			exitloop:
				cout << "Are you sure you want to exit? (Y/N)\n";
				string exit;
				getline(cin, exit);
				if (exit == "y" || exit == "Y" || exit == "yes")
				{
					inputchar = 't';
				}
				else if (exit == "n" || exit == "N" || exit == "no")
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
			case 'b': Output("Searching...\n"); //filler statement until inventory is added
				if (current == street)
					Output("There is nothing of interest in this area.");
				else if (current == safeHouse)
				{
					if (lightt == 0 && breadt == 0 && watert == 0)
						Output("A *flashlight* is on the table in front of you. Beside you is a loaf of *bread* and a bottle of *water*.");
					else if (lightt == 1 && breadt == 0 && watert == 0)
						Output("Beside you is a loaf of *bread* and a bottle of *water*.");
					else if (lightt == 0 && breadt == 1 && watert == 0)
						Output("A *flashlight* is on the table in front of you. Beside you is a bottle of *water*.");
					else if (lightt == 0 && breadt == 0 && watert == 1)
						Output("A *flashlight* is on the table in front of you. Beside you is a loaf of *bread*.");
					else if (lightt == 1 && breadt == 1 && watert == 0)
						Output("Beside you is a bottle of *water*.");
					else if (lightt == 0 && breadt == 1 && watert == 1)
						Output("A *flashlight* is on the table in front of you.");
					else if (lightt == 1 && breadt == 0 && watert == 1)
						Output("Beside you is a loaf of *bread*.");
					else if (lightt == 1 && breadt == 1 && watert == 1)
						Output("There is nothing of interest in this area.");
				}
				// Asterisks indicate keywords to be typed under Take()
				else if (current == radioTower)
				{
					if (lightu == 1)
					{
						if (tapet == 0 && glovest == 0 && radiot == 0)
							Output("Electrical *tape* is laying on a nearby shelf. There are electrical *gloves* on the floor, and a *radio* is on the desk.");
						else if (tapet == 1 && glovest == 0 && radiot == 0)
							Output("There are electrical *gloves* on the floor, and a *radio* is on the desk.");
						else if (tapet == 0 && glovest == 1 && radiot == 0)
							Output("Electrical *tape* is laying on a nearby shelf. There is a *radio* is on the desk.");
						else if (tapet == 0 && glovest == 0 && radiot == 1)
							Output("Electrical *tape* is laying on a nearby shelf. There are electrical *gloves* on the floor.");
						else if (tapet == 1 && glovest == 1 && radiot == 0)
							Output("A *radio* is on the desk.");
						else if (tapet == 0 && glovest == 1 && radiot == 1)
							Output("Electrical *tape* is laying on a nearby shelf.");
						else if (tapet == 1 && glovest == 0 && radiot == 1)
							Output("There are electrical *gloves* on the floor.");
						else if (tapet == 1 && glovest == 1 && radiot == 1)
							Output("There is nothing of interest in this area.");
					}
					else
						Output("It is too dark to see anything in this room.");
				}
				break;
			case 'c': Output("Opening...");
				break;
			case 'd': Output("Closing...");
				break;
			case 'e':
				if (current == street)
				{
					Output("There is nothing to take in this area.");
					break;
				}
				else if (current == safeHouse)
				{
					string itemTaken;
					Output("What would you like to take?\n");
					cin >> itemTaken;
					itemTaken = LowerCase(itemTaken);
					if (itemTaken == "flashlight" && lightt == 0)
					{
						Take(itemTaken);
						getline(cin, input);
					}
					else if (itemTaken == "bread" && breadt == 0)
					{
						Take(itemTaken);
						getline(cin, input);
					}
					else if (itemTaken == "water" && watert == 0)
					{
						Take(itemTaken);
						getline(cin, input);
					}
					else
					{
						Error();
						getline(cin, input);
					}

				}
				else if (current == radioTower)
				{
					string itemTaken;
					Output("What would you like to take?\n");
					cin >> itemTaken;
					itemTaken = LowerCase(itemTaken);
					if (lightu == 1)
					{
						if (itemTaken == "tape" && tapet == 0)
						{
							Take(itemTaken);
							getline(cin, input);
						}
						else if (itemTaken == "gloves" && glovest == 0)
						{
							Take(itemTaken);
							getline(cin, input);
						}
						else if (itemTaken == "radio" && radiot == 0)
						{
							Take(itemTaken);
							getline(cin, input);
						}
						else
						{
							Error();
							getline(cin, input);
						}
					}
					else
					{
						Error();
						getline(cin, input);
					}

				}
				break;
			case 'f': Output("Dropping...");
				break;
			case 'g':
				if (inv.getFood() > 0)
				{
					inv.setFood(inv.getFood() - 1);
					Output("Eating..."); Sleep(500); Output("\nYummy!");
				}
				else
					Output("You don't have any food left!");
				break;
			case 'h':
				if (inv.getWater() > 0)
				{
					inv.setWater(inv.getWater() - 1);
					Output("Drinking..."); Sleep(500); Output("\nThat was refeshing!");
				}
				else
					Output("You are all out of water!");
				break;
			case 'i': InventoryCheck();
				break;
			case 'j':
				InventoryCheck();
				Output("What would you like to use?\n");
				cin >> item;
				item = LowerCase(item);
				if (item == "food" || item == "water")
					Output("Try the command *eat* for food, or *drink* for water!");
				else if (item == "gloves")
				{
					if (glovest == 1)
					{
						Output("You put on the gloves. You are now safe from electical shock.");
						glovesu = 1; glovest = 0;
					}
					else
						ErrorInv();
				}
				else if (item == "tape")
				{
					if (tapet == 1)
					{
						if (radiot == 1)
						{
							if (glovesu == 1)
							{
								Output("The radio has been fixed!");
								radfix = 1; tapet = 0;
							}
							else
								Output("You shouldn't do this yet! You might get shocked!");
						}
						else
							Output("You don't have any items that need fixing!");
					}
					else
						ErrorInv();
				}
				else if (item == "radio")
				{
					if (radiot == 1)
					{
						if (radfix == 1)
						{
							if (current = radioTower)
							{
								Output("The radio crackles, then becomes silent. You speak into the radio, and hear a response.\nYou have successfully made contact with other survivors, and they are coming to rescue you. Congratulations!\nYou have survived...\n\nApocalypse.");
								radiot = 0; gameover = 1;
							}
							else
							{
								Output("The radio doesn't have a strong enough signal here.");
							}
						}
						else
							Output("This radio is clearly broken.");
					}
					else
						ErrorInv();
				}
				else if (item == "flashlight")
				{
					if (lightt == 1)
					{
						if (current == radioTower)
						{
							Output("The flashlight flickers on and illuminates the room.");
							lightu = 1;
						}
						else
							Output("This item has no effect here.");
					}
					else
						ErrorInv();
				}
				else
				{
					ErrorInv();
				}
				getline(cin, input);
				break;
			case 'k': current->Describe();
				break;
			case 's': MoveHelp();
				break;
			case 't': Output("Thanks for playing!\nWould you like to play again?(Y/N)\n");
				getline(cin, yn);
				if (yn == LowerCase("Y") || yn == LowerCase("Yes"))
				{
					restart = 1; break;
				}
				else
				{
					gameover = 1; break;
				}
			case 'u': Output("Game resumed.");
				break;
			case 'v': Error();
				break;
				//For cases w-z, function Movement() can be used to output prewritten errors/information
				//A similar function Description() will output the description of the room the first time it is visited. 
			case 'w': Output("Moving North... ");
				current = Movement(current, "north");
				current->Describe();
				Next();
				break;
			case 'x': Output("Moving East... ");
				current = Movement(current, "east");
				current->Describe();
				Next();
				break;
			case 'y': Output("Moving South... ");
				current = Movement(current, "south");
				current->Describe();
				Next();
				break;
			case 'z': Output("Moving West... ");
				current = Movement(current, "west");
				current->Describe();
				Next();
				break;
			default: Error();
				break;
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}