#include "Locations.h"
#include "Inventory.h"
#include "ItemsArray.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;
bool firsttf = 0, firsttw = 0;
bool DebugMode = 1;
bool tapet = 0, crowbart = 0, radiot = 0, glovest = 0, lightt = 0, breadt = 0, watert = 0;
bool firsttime = 0;
bool glovesu = 0, radfix = 0, lightu = 0;
int hunger = 15;
int thirst = 10;

Inventory * playerInv = new Inventory();
Item * flashlight = new Item("flashlight",0, 1);
Item * radio = new Item("radio", 0, 1);
Item * gloves = new Item("gloves", 0, 1);
Item * tape = new Item("tape", 0, 1);
Item * water = new Item("water", 1, 1);
Item * food = new Item("food", 1, 3);
Item * crowbar = new Item("crowbar", 0, 1);

int outputDelay = 25;

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
			Sleep(outputDelay + rand() % 25);
			x++;
		}
	}
	else if (DebugMode == 1)
	{
		cout << s;
	}
}
void Take(string, Room*);

void Help()
{
	cout << "                                   Help Menu                      " << endl;
	cout << "                                  -----------                     ";
	cout << "\nTo move throughout the city, use the following commands: North, East, South, West";
	cout << "\nTo interact with items, use the following commands: Search, Take, Eat, Drink, Use";
	cout << "\nItems may have *asterisks* to denote the keyword you should use to interact with it.";
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
	for (int i = 0; i < (playerInv->getSize()); i++)
	{
		if (playerInv->getItem(i)->getName() == "food")
		{
			cout << "Food: " << playerInv->getItem(1)->getCount() << "     ";
		}
		else if (playerInv->getItem(i)->getName() == "water")
		{
			cout << "Water: " << playerInv->getItem(0)->getCount() << endl;
		}
		else
		{
			switch (playerInv->getItem(i)->getPossess())
			{
			case 1:
				cout << playerInv->getItem(i)->getName();
			default:
				break;
			}
			
		}
	}
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
			playerInv->addItem(water);
			playerInv->addItem(food);
			firsttime = 1;
			hunger = 15;
			thirst = 10;
		}
		string item;
		/*
		Room* testRoom = new Room();
		Room* chemFire = new Room("Chemical Fire! Ouch!!!", 1);
		Room* street = new Room("\nYou find yourself standing in the middle of a desolate road.");
		Room* eastStreet = new Room("\nYou are in the middle of a street. You see a safe house in the distance to the west.");
		Room* safeHouse = new Room("\nA safe house full of useful things.");
		Room* radioTower = new Room("\nYou enter a radio tower, but it is too dark to see anything.");
		Room* radioShack = new Room("\nYou are now in the Radio Shack store, essential communication supplies can be found here.");
		Room* militaryBase = new Room("\nYou find yourself in a Military Base.");
		Room* airport = new Room("\nThis is the airport where you will be rescued after successfully communicating with others.");
		Room* clothingStore = new Room("\nYou are now inside the clothing store H&M, oh you fancy huh?");
		Room* bank = new Room("\nYou are inside Chase bank, feel free to check around to see what you can find.");
		Room* hospital = new Room("\nA hospital in which medical supplies can be retrieved.");
		Room* hazard = new Room("\nBe careful! This is a hazardous area that cannot be accessed!!",1);
		Room* hazard1 = new Room("\nThis is a hazardous area that can be accessed; However, you're at risk!", 1);
		Room* boundary = new Room("\nThis is a danger area! You cannot go here!", 1);*/

		Room* testRoom = new Room();
		Room* chemFire = new Room("Chemical Fire! Ouch!!!", 1);
		Room* street = new Room("\nYou start in the middle of a wide street that is filled with debris of once tall building now brought down to to its mere foundation. \nThe street is filled with cracks and rocks all over the place. \nPieces of the road is missing and you can see cars on fire or already burned. \nTelephone wires and electrical wires are all over the place and have lost current due to the power plant exploding.\n The sky is an orange red color due to the radiation around the world and the clouds where dark grey even black from the ashes of the building that have been burned by fire.");
		Room* eastStreet = new Room("\nYou are in the middle of a street. You see a safe house in the distance to the west.");
		Room* safeHouse = new Room("\nYou arrive to the only building that withstood the apocalypse.\n This building has been marked as the safe house for the town and people who survived take refuge in its high structure.\n The building consists of 28 floors and its design reminds you of those 1980’s hotels.\n You can see ruble of the other buildings creating a perfect path to the doors that are lined with a gold trim.\n The building truly resembles a beacon of hope.");
		Room* radioTower = new Room("\nYou enter a radio tower, but it is too dark to see anything.");
		Room* radioShack = new Room("\nYou are now in the Radio Shack store, essential communication supplies can be found here.");
		Room* militaryBase = new Room("\nYou find yourself in a Military Base.");
		Room* airport = new Room("\nYou finally arrive to the airport where the airplanes have all departed before the apocalypse hit.\n The sight of the airport being deserted gives you a sense of depression and makes you feel alone. However there is hope that with all the materials you have you are able to create a means of contacted for a ride to salvation.");
		Room* clothingStore = new Room("\nYou are now inside the clothing store H&M, oh you fancy huh?");
		Room* bank = new Room("\nYou see a colossal building that has greek lettering on it.\n This is the central bank of the city.\n It has the designs of Ancient Greek buildings with its huge pillars supporting its triangular roof the seems to have caved in a bit.\n One of the pillars is actually broken in half and part of the ruling is missing.\n Yet it still has a way to appear magnificent in a time of despair.\n The entrance is a humungous bi - folding door that has gold trim around to show that it is full of wealth.\n The steps has rouble around it and there is a lonely tree stump that is seen next to it.\n Maybe there is something useful in the security boxes.");
		Room* hospital = new Room("\nThe city hospital once a place for health and hope is now a wasteland.\n This hospital had about 7 buildings all interconnected by bridges but now there is but just one building up and seems to be stable.\n The place is deserted and gives a haunting vibe.\n Inside there is medicine that was left from before the apocalypse which can help in restoring my health in bad times.");
		Room* hazard = new Room("\nBe careful! This is a hazardous area that cannot be accessed!!", 1);
		Room* hazard1 = new Room("\nThis is a hazardous area that can be accessed; However, you're at risk!", 1);
		Room* boundary = new Room("\nThis is a danger area! You cannot go here!", 1);

		Connect(street, "west", safeHouse);
		Connect(street, "east", eastStreet);
		Connect(eastStreet, "east", hazard);
		Connect(eastStreet, "north", clothingStore);
		Connect(clothingStore, "east", hospital);
		Connect(clothingStore, "north", radioTower);
		Connect(hospital, "south", hazard);
		Connect(hospital, "north", airport);
		Connect(airport, "west", radioShack);
		Connect(radioShack, "west", radioTower);
		Connect(radioTower, "west", militaryBase);
		Connect(militaryBase, "south", bank);
		Connect(bank, "south", safeHouse);
		Connect(radioTower, "south", hazard1);
		
		// this is how to add items to a room
		safeHouse->Stock.addItem(flashlight);
		safeHouse->Stock.addItem(tape);
		safeHouse->Stock.addItem(food);


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

			switch (hunger)
			{
			case 3:
				Output("You are fairly hungry.\n");
				outputDelay += 10;
				break;
			case 2:
				Output("You are dangerously hungry. Eat soon.\n");
				outputDelay += 10;
				break;
			case 1:
				Output("You are very weak. If you do not eat, you will perish.\n");
				outputDelay += 10;
				break;
			case 0:
				Output("You have died from hunger...\n");
				goto RestartLabel;
				break;
			default:
				break;
			}

			switch (thirst)
			{
			case 3:
				Output("You are very thirsty.\n");
				outputDelay += 10;
				break;
			case 2:
				Output("You are dangerously thirsty. Drink some water.\n");
				outputDelay += 10;
				break;
			case 1:
				Output("The world is spinning. If you do not drink some water, you will soon perish.\n");
				outputDelay += 10;
				break;
			case 0:
				Output("You have died from thirst...\n");
				goto RestartLabel;
				break;
			default:
				break;
			}

			getline(cin, input);

			if (lightu == 1)
			{
				radioTower->setDescription("\nA radio tower illuminated by your flashlight.");
			}
			else
			{
				radioTower->setDescription("\nYou enter a radio tower, but it is too dark to see anything.");
			}
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
				Output("You found the following items...\n");
				for (int i = 0; i < (current->Stock.getSize()); i++)
				{
					if (current->Stock.getItem(i)->getPossess() == 1)
					{
						cout << current->Stock.getItem(i)->getName() << endl;
					}
				}
				break;
			case 'c': Output("Opening...");
				break;
			case 'd': Output("Closing...");
				break;
			case 'e':
				if (current->Stock.getSize() > 0)
				{
					Output("What would you like to take?");
					getline(cin, item);
					Take(item, current);
				}
				else
					Output("There is nothing of interest in this area.");
				break;
			case 'f': Output("Dropping...");
				break;
			case 'g':
				if (playerInv->getItem(1)->getCount() > 0)
				{
					playerInv->getItem(1)->setCount(playerInv->getItem(1)->getCount() - 1);
					hunger += 2;
					outputDelay = 25;
					Output("Eating..."); Sleep(500); Output("\nYummy!");
				}
				else
					Output("You don't have any food left!");
				break;
			case 'h':
				if (playerInv->getItem(0)->getCount() > 0)
				{
					playerInv->getItem(0)->setCount(playerInv->getItem(0)->getCount() - 1);
					thirst += 2;
<<<<<<< HEAD
					Output("Drinking..."); Sleep(500); Output("\nThat was refreshing!");
=======
					outputDelay = 25;
					Output("Drinking..."); Sleep(500); Output("\nThat was refeshing!");
>>>>>>> 1faaef9468a0a297116891f165ca1420480c12e4
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
			case 't': 
				RestartLabel:
				Output("Thanks for playing!\nWould you like to play again?(Y/N)\n");
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
				testRoom = Movement(current, "north");
				if (testRoom->getStatus() == 1)
				{
					Output("Sorry, you have died in the wasteland.\n");
					goto RestartLabel;
					break;
				}
				else
				{
					if (current != testRoom)
					{
						hunger--;
						thirst--;
					}
					current = testRoom;
				}
				current->Describe();
				Next();
				break;
			case 'x': Output("Moving East... ");
				testRoom = Movement(current, "east");
				if (testRoom->getStatus() == 1)
				{
					Output("You should not have done that. You perished alone in the city\n");
					goto RestartLabel;
					break;
				}
				else
				{
					if (current != testRoom)
					{
						hunger--;
						thirst--;
					}
					current = testRoom;
				}
					
				current->Describe();
				Next();
				break;
			case 'y': Output("Moving South... ");
				testRoom = Movement(current, "south");
				if (testRoom->getStatus() == 1)
				{
					Output("That move was your last... You have died!\n");
					goto RestartLabel;
					break;
				}
				else
				{
					if (current != testRoom)
					{
						hunger--;
						thirst--;
					}
					current = testRoom;
				}
				current->Describe();
				Next();
				break;
			case 'z': Output("Moving West... ");
				testRoom = Movement(current, "west");
				if (testRoom->getStatus() == 1)
				{
					Output("The light at the end of the tunnel beckons... You have died.\n");
					goto RestartLabel;
					break;
				}
				else
				{
					if (current != testRoom)
					{
						hunger--;
						thirst--;
					}
					current = testRoom;
				}
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

void Take(string t, Room*r)
{
	for (int i = 0; i < (r->Stock.getSize()); i++)
	{
		if (t == r->Stock.getItem(i)->getName())
		{
			if (t == "food")
			{
				if (firsttf == 0)
				{
					playerInv->getItem(1)->setCount(playerInv->getItem(1)->getCount() + 1);
					r->Stock.getItem(i)->setPossess(0);
					firsttf = 1;
				}
			}
			else if (t == "water")
			{
				if (firsttw == 0)
				{
					playerInv->getItem(0)->setCount(playerInv->getItem(0)->getCount() + 1);
					r->Stock.getItem(i)->setPossess(0);
					firsttw = 1;
				}
			}
			else
			{
				if (r->Stock.getItem(i)->getCount() != 0)
				{
					Item * vessel = new Item(r->Stock.getItem(i)->getName(), 1, 1);
					playerInv->addItem(vessel);
					r->Stock.getItem(i)->setPossess(0);
					r->Stock.getItem(i)->setCount(0);
				}
			}
		}
	}

	Output("Adding to inventory..."); Sleep(500);
	Output("\nSuccessfully added to inventory.");
}