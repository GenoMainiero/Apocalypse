#include "Locations.h"
#include "Inventory.h"
#include "ItemsArray.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include "StringClass.h"

using namespace std;
bool DebugMode = 0;
bool tapet = 0, radiot = 0, glovest = 0, lightt = 0, breadt = 0, watert = 0;
bool firsttime = 0;
bool boolyboi = 0; bool Dog = 0; bool NoDog = 0;
bool glovesu = 0, radfix = 0, lightu = 0, radu = 0, conversation = 0, convover = 0;
int hunger = 15;
int thirst = 10;
int convo = 0;
bool StormHappening = 0;
int StormMovements = 6;
string name;
string selection;
StringContainer * stringContainer = new StringContainer();

Inventory * playerInv = new Inventory();
Item * flashlight = new Item(stringContainer->flashlightCommand,0, 1);
Item * radio = new Item(stringContainer->radioCommand, 0, 1);
Item * gloves = new Item(stringContainer->glovesCommand, 0, 1);
Item * tape = new Item(stringContainer->tapeCommand, 0, 1);
Item * water = new Item(stringContainer->waterCommand, 1, 2);
Item * food = new Item(stringContainer->foodCommand, 1, 3);

int outputDelay = 5;

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
	cout << stringContainer->helpMenu[0] << endl;
	cout << stringContainer->helpMenu[1];
	cout << stringContainer->helpMenu[2];
	cout << stringContainer->helpMenu[3];
	cout << stringContainer->helpMenu[4];
	cout << stringContainer->helpMenu[5];
	cout << stringContainer->helpMenu[6];
	cout << stringContainer->helpMenu[7];
	cout << stringContainer->helpMenu[8];
}

void MoveHelp()
{
	Output(stringContainer->moveHelpMenu[0]);
	Output(stringContainer->moveHelpMenu[1]);
}

string Use()
{
	string item;
	Output(stringContainer->useItemQuestion);
	cin >> item;
	//if in the right room, can use, otherwise, error message
	transform(item.begin(), item.end(), item.begin(), (int(*)(int))tolower);
	return item;
}

void AddInv()
{
	Output(stringContainer->addingToInventoryOutput); Sleep(500);
	Output(stringContainer->addedToInvetoryOutput);
}
void InventoryCheck()
{
	Output(stringContainer->inventoryCheckStrings[0]);
	for (int i = 0; i < (playerInv->getSize()); i++)
	{
		if (playerInv->getItem(i)->getName() == stringContainer->inventoryCheckStrings[1])
		{
			cout << stringContainer->inventoryCheckStrings[2] << playerInv->getItem(1)->getCount() << endl;
		}
		else if (playerInv->getItem(i)->getName() == stringContainer->inventoryCheckStrings[3])
		{
			cout << stringContainer->inventoryCheckStrings[4] << playerInv->getItem(0)->getCount() << stringContainer->inventoryCheckStrings[5];
		}
		else
		{
			switch (playerInv->getItem(i)->getPossess())
			{
			case 1:
				cout << playerInv->getItem(i)->getName() << endl;
			default:
				break;
			}
			
		}
	}
}

void Next()
{
	//These strings can be outputted after descriptions of areas are read
	//string Next[4] = { "What would you like to do next?", "What's next?", "What is your next move?", "Now what would you like to do?" };
	int randNum = rand() % (4);
	int x = 0;
	string NextA = stringContainer->nextStrings[randNum];
	Output(NextA);
}

void Error()
{
	int randNum2 = rand() % (4);
	int x = 0;
	string ErrorA = stringContainer->errorStrings[randNum2];
	Output(ErrorA);
}

void ErrorInv()
{
	Output(stringContainer->errorInvOutput);
}

int main()
{
	bool gameover = 0;
	bool restart = 0; //to "die" or restart, use "restart = 1". all variables will reset and intro will play.

	while (!gameover)
	{
		tapet = 0, radiot = 0, glovest = 0, lightt = 0, breadt = 0, watert = 0;
		glovesu = 0, radfix = 0, lightu = 0; restart = 0;
		convo = 0; StormHappening = 0; StormMovements = 5;

		for (int i = 0; i < (playerInv->getSize()); i++)
		{
			playerInv->getItem(i)->setPossess(0);
		}
		

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
		Room* chemFire = new Room(stringContainer->chemFireDescription, 1);
		Room* street = new Room(stringContainer->streetDescription); //("\nYou start in the middle of a wide street that is filled with debris of once tall building now brought down to to its mere foundation. \nThe street is filled with cracks and rocks all over the place. \nPieces of the road is missing and you can see cars on fire or already burned. \nTelephone wires and electrical wires are all over the place and have lost current due to the power plant exploding.\n The sky is an orange red color due to the radiation around the world and the clouds where dark grey even black from the ashes of the building that have been burned by fire.");
		Room* eastStreet = new Room(stringContainer->eastStreetDescription);
		Room* safeHouse = new Room(stringContainer->safeHouseLongDescription);
		Room* radioTower = new Room(stringContainer->radioTowerDescription);
		Room* radioShack = new Room(stringContainer->radioShackDescription);
		Room* militaryBase = new Room(stringContainer->militartBaseLongDescription);
		Room* airport = new Room(stringContainer->airportLongDescription);
		Room* clothingStore = new Room(stringContainer->clothingStoreDescription);
		Room* bank = new Room(stringContainer->bankLongDescription);
		Room* hospital = new Room(stringContainer->hospitalLongDescription);
		Room* hazard = new Room(stringContainer->hazardDescription, 1);
		Room* hazard1 = new Room(stringContainer->hazard1Description, 1);
		Room* boundary = new Room(stringContainer->boundryDescription, 1);

		hospital->setShortDesc(stringContainer->ShortHospital);
		radioShack->setShortDesc(stringContainer->ShortRadioShack);
		safeHouse->setShortDesc(stringContainer->ShortSafehouse);
		militaryBase->setShortDesc(stringContainer->ShortMilitart);
		airport->setShortDesc(stringContainer->ShortAirport);
		bank->setShortDesc(stringContainer->ShortBank);

		Connect(street, stringContainer->west, safeHouse);
		Connect(street, stringContainer->east, eastStreet);
		Connect(eastStreet, stringContainer->east, hazard);
		Connect(eastStreet, stringContainer->north, clothingStore);
		Connect(clothingStore, stringContainer->east, hospital);
		Connect(clothingStore, stringContainer->north, radioShack);
		Connect(hospital, stringContainer->south, hazard);
		Connect(hospital, stringContainer->north, airport);
		Connect(airport, stringContainer->west, radioShack);
		Connect(radioShack, stringContainer->west, radioTower);
		Connect(radioTower, stringContainer->west, militaryBase);
		Connect(militaryBase, stringContainer->south, bank);
		Connect(bank, stringContainer->south, safeHouse);
		Connect(radioTower, stringContainer->south, hazard1);
		Connect(street, stringContainer->north, hazard1);
		Connect(hazard1, stringContainer->west, bank);
		Connect(hazard1, stringContainer->east, clothingStore);
	
			for (int i = 0; i < 3; i++)
			{
				bank->Stock.removeItem(i);
				safeHouse->Stock.removeItem(i);
				clothingStore->Stock.removeItem(i);
				hospital->Stock.removeItem(i);
				radioShack->Stock.removeItem(i);
				militaryBase->Stock.removeItem(i);
				radioTower->Stock.removeItem(i);
			}
			playerInv->getItem(0)->setCount(2);
			playerInv->getItem(1)->setCount(3);
		
		// this is how to add items to a room
		bank->Stock.addItem(flashlight);
		safeHouse->Stock.addItem(food);
		safeHouse->Stock.addItem(tape);
		clothingStore->Stock.addItem(gloves);
		hospital->Stock.addItem(food);
		hospital->Stock.addItem(water);
		radioShack->Stock.addItem(radio);
		militaryBase->Stock.addItem(water);

		Room* current = street;
		//Game Introduction + Storyline
		//I made the intro look a little cooler. Hope you like it! - Geno
		string welcome1 = stringContainer->welcomeMenuOutputs[0];
		string welcome = stringContainer->welcomeMenuOutputs[1];
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
			street->Describe();
			Output(stringContainer->firstMoveQuestion);
		}
		else if (DebugMode == 1)
		{
			cout << welcome1 << welcome;
			Help();
			cout << stringContainer->firstMoveQuestion;
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
				Output(stringContainer->hungerOuputs[0]);
				outputDelay += 10;
				break;
			case 2:
				Output(stringContainer->hungerOuputs[1]);
				outputDelay += 10;
				break;
			case 1:
				Output(stringContainer->hungerOuputs[2]);
				outputDelay += 10;
				break;
			case 0:
				Output(stringContainer->hungerOuputs[3]);
				goto RestartLabel;
				break;
			default:
				break;
			}

			switch (thirst)
			{
			case 3:
				Output(stringContainer->thirstOutputs[0]);
				outputDelay += 10;
				break;
			case 2:
				Output(stringContainer->thirstOutputs[1]);
				outputDelay += 10;
				break;
			case 1:
				Output(stringContainer->thirstOutputs[2]);
				outputDelay += 10;
				break;
			case 0:
				Output(stringContainer->thirstOutputs[3]);
				goto RestartLabel;
				break;
			default:
				break;
			}
			if (StormHappening == 1 && StormMovements < 1 && current != safeHouse)
			{
				Output("You did not make it to safety, and you perish in the storm.\n");
				goto RestartLabel;
			}
			else if (StormHappening == 1 && current != safeHouse)
			{
				switch (StormMovements)
				{
				case 4: Output("\nRemember your way back to the safehouse, and do not stray from the path.\n");
					break;
				}
			}
			if (current == clothingStore && StormHappening == 1 && Dog == 0 && NoDog == 0)
			{

				Output("You have found a dog, would you like to keep it? (Y/N): ");
				getline(cin, yn);
				if (yn == "Y" || yn == "y" || yn == "yes")
				{

					Output("The dog is now following you!\n");
					Dog = 1; Next(); cout << endl;

				}
				else if (yn == "n" || yn == "N" || yn == "no")
				{
					Output("The dog has died and it's your fault! You should feel terrible!\n");
					Next(); cout << endl; NoDog = 1;
				}

			}
			else if (current == bank && StormHappening == 1 && Dog == 0 && NoDog == 0)
			{

				Output("You have found a dog, would you like to keep it? (Y/N): ");
				getline(cin, yn);
				if (yn == "Y" || yn == "y" || yn == "yes")
				{

					Output("The dog is now following you!\n");
					Dog = 1; Next(); cout << endl;
				}
				else if (yn == "n" || yn == "N" || yn == "no")
				{
					Output("The dog has died and it's your fault! You should feel terrible!\n");
					Next(); cout << endl; NoDog = 1;
				}

			}
			if (current == eastStreet && Dog == 1 && eastStreet->getfirstw() == 0)
			{
				Output("The dog has found food and water for you! It has automatically been added to your inventory.\n");
				playerInv->getItem(1)->setCount(playerInv->getItem(1)->getCount() + 2);
				playerInv->getItem(0)->setCount(playerInv->getItem(0)->getCount() + 2);
				eastStreet->setfirstw(1);
			}
			if (current == radioTower && Dog == 1 && radioTower->getfirstw() == 0)
			{
				Output("The dog has found food and water for you! It has automatically been added to your inventory.\n");
				playerInv->getItem(1)->setCount(playerInv->getItem(1)->getCount() + 2);
				playerInv->getItem(0)->setCount(playerInv->getItem(0)->getCount() + 2);
				radioTower->setfirstw(1);
			}

			getline(cin, input); //Main input for the game
			if (lightu == 1)
			{
				radioTower->setDescription(stringContainer->flashlightUserOutput);
			}
			else
			{
				radioTower->setDescription(stringContainer->radioTowerDescription);
			}
			//converts input to lowercase this if statement assigns a char for use in the switch statement
			input = LowerCase(input);
			if (input == stringContainer->helpCommand)
				inputchar = 'a';
			else if (input == stringContainer->searchCommand)
				inputchar = 'b';
			else if (input == stringContainer->openCommand)
				inputchar = 'c';
			else if (input == stringContainer->closeCommand)
				inputchar = 'd';
			else if (input == stringContainer->takeCommand)
				inputchar = 'e';
			else if (input == stringContainer->dropCommand)
				inputchar = 'f';
			else if (input == stringContainer->eatCommand)
				inputchar = 'g';
			else if (input == stringContainer->drinkCommand)
				inputchar = 'h';
			else if (input == stringContainer->inventoryCommand || input == stringContainer->inventoryCommand2)
				inputchar = 'i';
			else if (input == stringContainer->useCommand)
				inputchar = 'j';
			else if (input == stringContainer->locationCommand)
				inputchar = 'k';
			else if (input == stringContainer->moveCommand)
				inputchar = 's';
			else if (input == stringContainer->exitCommand || input == stringContainer->quitCommand)
			{
			exitloop:
				cout << stringContainer->exitQuestionOutput;
				string exit;
				getline(cin, exit);
				if (exit == "y" || exit == "Y" || exit == "yes")
				{
					inputchar = 't';
				}
				else if (exit == "n" || exit == "N" || exit == "no")
				{
					Output(stringContainer->resumeGameOutput);
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
			else if (input == stringContainer->north)
				inputchar = 'w';
			else if (input == stringContainer->east)
				inputchar = 'x';
			else if (input == stringContainer->south)
				inputchar = 'y';
			else if (input == stringContainer->west)
				inputchar = 'z';
			else
			{
				inputchar = 'v';
			}
			
			//this is the heart of the text parser, which accepts the char and controls what happens next
			
			if (StormHappening == 0)
			{
				switch (inputchar)
				{
				case 'a': Help();
					break;
				case 'b': Output(stringContainer->searchingOutput); //filler statement until inventory is added
					if (current->Stock.getSize() > 0)
					{
						if (current != radioTower)
						{
							Output(stringContainer->foundItemsOutput);
							for (int i = 0; i < (current->Stock.getSize()); i++)
							{
								if (current->Stock.getItem(i)->getPossess() == 1)
								{
									cout << current->Stock.getItem(i)->getName() << endl;
								}
							}
						}
						else
						{
							if (lightu)
							{
								Output(stringContainer->foundItemsOutput);
								for (int i = 0; i < (current->Stock.getSize()); i++)
								{
									if (current->Stock.getItem(i)->getPossess() == 1)
									{
										cout << current->Stock.getItem(i)->getName() << endl;
									}
								}
							}
							else
								Output(stringContainer->tooDarkOutput);
						}
					}
					else
						Output(stringContainer->nothingOfInterestOutput);
					break;
				case 'c': Output(stringContainer->openingOutput);
					break;
				case 'd': Output(stringContainer->closingOutput);
					break;
				case 'e':
					if (current->Stock.getSize() > 0)
					{
						Output(stringContainer->takeQuestionOutput);
						getline(cin, item);
						Take(item, current);
					}
					else
						Output(stringContainer->nothingOfInterestOutput);
					break;
				case 'f': Output(stringContainer->droppingOutput);
					break;
				case 'g':
					if (playerInv->getItem(1)->getCount() > 0)
					{
						playerInv->getItem(1)->setCount(playerInv->getItem(1)->getCount() - 1);
						hunger += 2;
						outputDelay = 25;
						Output(stringContainer->eatingOutput); Sleep(500); Output(stringContainer->yummyOutput);
					}
					else
						Output(stringContainer->outOfFoodOutput);
					break;
				case 'h':
					if (playerInv->getItem(0)->getCount() > 0)
					{
						playerInv->getItem(0)->setCount(playerInv->getItem(0)->getCount() - 1);
						thirst += 3;
						outputDelay = 25;
						Output(stringContainer->drinkingOutput); Sleep(500); Output(stringContainer->refreshingOutput);
					}
					else
						Output(stringContainer->outOfWater);
					break;
				case 'i': InventoryCheck();
					break;
				case 'j':
					InventoryCheck();
					Output(stringContainer->useQuestionOutput);
					cin >> item;
					item = LowerCase(item);
					if (item == stringContainer->foodCommand || item == stringContainer->waterCommand)
						Output(stringContainer->eatAndDrinkPrompt);
					else if (item == stringContainer->glovesCommand)
					{
						if (glovest == 1)
						{
							Output(stringContainer->puttingGlovesOnOutPut);
							glovesu = 1; glovest = 0;
						}
						else
							ErrorInv();
					}
					else if (item == stringContainer->tapeCommand)
					{
						if (tapet == 1)
						{
							if (radiot == 1)
							{
								if (glovesu == 1)
								{
									Output(stringContainer->radioFixedOutput);
									radfix = 1; tapet = 0;
								}
								else
									Output(stringContainer->mightGetShocked);
							}
							else
								Output(stringContainer->noItemsNeedFixing);
						}
						else
							ErrorInv();
					}
					else if (item == stringContainer->radioCommand)
					{
						if (radiot == 1)
						{
							if (radfix == 1)
							{
								if (current == radioTower)
								{
									radu = 1;
									string WhatSay = stringContainer->whatToSayOutput;
									if (convover == 0)
									{
										Output(stringContainer->radioCrackleOutput);
										Sleep(1500);
										Output(stringContainer->radioStirsOutput);
										Output(stringContainer->nameQuestionOutput);
										getline(cin, name); getline(cin, name);
										Output("\"Greetings, "); Output(name); Output(stringContainer->carolineGreetingOutput);
									ConvoError:
										Output(WhatSay);
										Output(stringContainer->whereAreYou);
										getline(cin, selection);
										if (LowerCase(selection) == "a")
										{
											Output(stringContainer->survivorOutput);
										ConvoError1:
											Output(WhatSay);
											Output(stringContainer->survivorsQuestionOutput);
											getline(cin, selection);
											if (LowerCase(selection) == "a")
											{
												Output(stringContainer->survivorsConvo[0]);
												Output(stringContainer->survivorsConvo[1]);
												Output(stringContainer->survivorsConvo[2]);
												Output(stringContainer->survivorsConvo[3]);
												convover = 1; 
												StormHappening = 1;
												
												break;
											}
											else if (LowerCase(selection) == "b")
											{
												Output(stringContainer->airplaneConvo[0]);
												Output(stringContainer->airplaneConvo[1]);
												Output(stringContainer->airplaneConvo[2]);
												Output(stringContainer->airplaneConvo[3]);
												convover = 1;
												StormHappening = 1;
												break;
											}
											else { Output(stringContainer->invalidSelectionOutput); goto ConvoError1; }
										}
										else if (LowerCase(selection) == "b")
										{
											Output(stringContainer->airplaneSentOutput);
										ConvoError2:
											Output(WhatSay);
											Output(stringContainer->planeMeetQuestionOutput);
											getline(cin, selection);
											if (LowerCase(selection) == "a")
											{
												Output(stringContainer->radioactiveWaveConvo[0]);
												Sleep(1000);
												Output(stringContainer->radioactiveWaveConvo[1]);
												Output(stringContainer->radioactiveWaveConvo[2]);
												convover = 1;
												StormHappening = 1;
												break;
											}
											else if (LowerCase(selection) == "b")
											{
												Output(stringContainer->prepareToLeaveAirportPrompt);
												convover = 1; StormHappening = 1; StormMovements = 3; break;
											}
											else { Output(stringContainer->invalidSelectionOutput); goto ConvoError2; }
										}
										else { Output(stringContainer->invalidSelectionOutput); goto ConvoError; }
									}
									else if (convover == 1)
									{
										Output(stringContainer->radioNoResponseOutput);
									}
									radiot = 0;
									break;
								}
								else
								{
									Output(stringContainer->radioWeakSignal);
								}
							}
							else
								Output(stringContainer->radioBroken);
						}
						else
							ErrorInv();
					}
					else if (item == stringContainer->flashlightCommand)
					{
						if (lightt == 1)
						{
							if (current == radioTower)
							{
								Output(stringContainer->flashlightOnOutput);
								lightu = 1;
							}
							else
								Output(stringContainer->itemNoEffectOutput);
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
					Output(stringContainer->playAgainPrompt);
					getline(cin, yn);
					if (LowerCase(yn) == LowerCase("Y") || LowerCase(yn) == LowerCase(stringContainer->yesCommand))
					{
						restart = 1; break;
					}
					else
					{
						gameover = 1; break;
					}
				case 'u': Output(stringContainer->gameResumed);
					break;
				case 'v': Error();
					break;
					//For cases w-z, function Movement() can be used to output prewritten errors/information
					//A similar function Description() will output the description of the room the first time it is visited. 
				case 'w': Output(stringContainer->movingNorthOutput);
					testRoom = Movement(current, stringContainer->north);
					if (testRoom->getStatus() == 1)
					{
						Output(stringContainer->diedInWasteLandOutput);
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
						if (current == airport && radu == 1)
						{
							Output("You arrive at the airport just as the airplane lands.\nA man exits the plane and sees you standing there.");
							Output("\"You must be "); Output(name); Output(". Welcome aboard.\"\n\n"); Output(stringContainer->congradulationsOutput);
							gameover = 1; goto RestartLabel;
						}
						
					}
					current->Describe();
					current->setShort(1);
					Next();
					break;
				case 'x': Output(stringContainer->movingEastOutput);
					testRoom = Movement(current, stringContainer->east);
					if (testRoom->getStatus() == 1)
					{
						Output(stringContainer->badMoveOutput);
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
						if (current == airport && radu == 1)
						{
							Output(stringContainer->congradulationsOutput);
							gameover = 1; goto RestartLabel;
						}
						
					}
					current->Describe();
					current->setShort(1);
					Next();
					break;
				case 'y': Output(stringContainer->movingSouthOutput);
					testRoom = Movement(current, stringContainer->south);
					if (testRoom->getStatus() == 1)
					{
						Output(stringContainer->lastMoveDead);
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
					current->setShort(1);
					Next();
					break;
				case 'z': Output(stringContainer->movingWestOutput);
					testRoom = Movement(current, stringContainer->west);
					if (testRoom->getStatus() == 1)
					{
						Output(stringContainer->lightBeaconsDead);
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
					current->setShort(1);
					Next();
					break;
				default: Error();
					break;
				}
			}
			else if (StormHappening == 1 && inputchar == 'w' || 'x' || 'y' || 'z' || 'g' || 'h' || 'i' || 's' || 't' || 'u' || 'v')
			{
				if (StormMovements > 0)
				{
					switch (inputchar)
					{
					case 'g':
						if (playerInv->getItem(1)->getCount() > 0)
						{
							playerInv->getItem(1)->setCount(playerInv->getItem(1)->getCount() - 1);
							hunger += 2;
							outputDelay = 25;
							Output(stringContainer->eatingOutput); Sleep(500); Output(stringContainer->yummyOutput);
						}
						else
							Output(stringContainer->outOfFoodOutput);
						break;
					case 'h':
						if (playerInv->getItem(0)->getCount() > 0)
						{
							playerInv->getItem(0)->setCount(playerInv->getItem(0)->getCount() - 1);
							thirst += 2;
							outputDelay = 25;
							Output(stringContainer->drinkingOutput); Sleep(500); Output(stringContainer->refreshingOutput);
						}
						else
							Output(stringContainer->outOfWater);
						break;
					case 'i': InventoryCheck();
						break;
					case 's': MoveHelp();
						break;
					case 't':
						//There was a RestartLabel here, writing this incase it breaks something
						Output(stringContainer->playAgainPrompt);
						getline(cin, yn);
						if (yn == LowerCase("Y") || yn == LowerCase(stringContainer->yesCommand))
						{
							restart = 1; break;
						}
						else
						{
							gameover = 1; break;
						}
					case 'u': Output(stringContainer->gameResumed);
						break;
					case 'v': Error();
						break;
						//For cases w-z, function Movement() can be used to output prewritten errors/information
						//A similar function Description() will output the description of the room the first time it is visited. 
					case 'w': Output(stringContainer->movingNorthOutput);
						testRoom = Movement(current, stringContainer->north);
						if (testRoom->getStatus() == 1)
						{
							Output(stringContainer->diedInWasteLandOutput);
							goto RestartLabel;
							break;
						}
						else
						{
							if (current != testRoom)
							{
								hunger--;
								thirst--;
								StormMovements--;
							}
							current = testRoom;
							if (current == airport && radu == 1)
							{
								Output(stringContainer->congradulationsOutput);
								gameover = 1; goto RestartLabel;
							}
							
						}
						current->Describe();
						current->setShort(1);
						Next();
						break;
					case 'x': Output(stringContainer->movingEastOutput);
						testRoom = Movement(current, stringContainer->east);
						if (testRoom->getStatus() == 1)
						{
							Output(stringContainer->badMoveOutput);
							goto RestartLabel;
							break;
						}
						else
						{
							if (current != testRoom)
							{
								hunger--;
								thirst--;
								StormMovements--;
							}
							current = testRoom;
							if (current == airport && radu == 1)
							{
								Output(stringContainer->congradulationsOutput);
								gameover = 1; goto RestartLabel;
							}
							
						}
						current->Describe();
						current->setShort(1);
						Next();
						break;
					case 'y': Output(stringContainer->movingSouthOutput);
						testRoom = Movement(current, stringContainer->south);
						if (testRoom->getStatus() == 1)
						{
							Output(stringContainer->lastMoveDead);
							goto RestartLabel;
							break;
						}
						else
						{
							if (current != testRoom)
							{
								hunger--;
								thirst--;
								StormMovements--;
							}
							current = testRoom;
							if (current == safeHouse && StormHappening == 1)
							{
								Output(stringContainer->madeItToSafeHouseOutput);
								Sleep(2000);
								StormHappening = 0;
								Output(stringContainer->stormOverOutput);
							}
						}
						current->Describe();
						current->setShort(1);
						Next();
						break;
					case 'z': Output(stringContainer->movingWestOutput);
						testRoom = Movement(current, stringContainer->west);
						if (testRoom->getStatus() == 1)
						{
							Output(stringContainer->lightBeaconsDead);
							goto RestartLabel;
							break;
						}
						else
						{
							if (current != testRoom)
							{
								hunger--;
								thirst--;
								StormMovements--;
							}
							current = testRoom;
							if (current == safeHouse && StormHappening == 1)
							{
								Output(stringContainer->madeItToSafeHouseOutput);
								Sleep(2000);
								StormHappening = 0;
								Output(stringContainer->stormOverOutput);
							}
						}
						current->Describe();
						current->setShort(1);
						Next();
						break;
					default: Error();
						break;
					}
				}
			}
			else { Output(stringContainer->mustMovetoSafeHouseOutput); }
			cout << endl;
		}
	}
	system("pause");
	return 0;
}
void Take(string t, Room*r)
{
	boolyboi = 0;
	for (int i = 0; i < (r->Stock.getSize()); i++)
	{
		if (t == r->Stock.getItem(i)->getName())
		{
			if (t == stringContainer->foodCommand)
			{
				if (r->getfirstf() == 0)
				{
					playerInv->getItem(1)->setCount(playerInv->getItem(1)->getCount() + 1);
					r->Stock.removeItem(i);
					r->setfirstf(1); AddInv(); boolyboi = 1;
				}
			}
			else if (t == stringContainer->waterCommand)
			{
				if (r->getfirstw() == 0)
				{
					playerInv->getItem(0)->setCount(playerInv->getItem(0)->getCount() + 1);
					r->Stock.removeItem(i);
					r->setfirstw(1); AddInv(); boolyboi = 1;
				}
			}
			else
			{
				if (r->Stock.getItem(i)->getCount() != 0)
				{
					Item * vessel = new Item(r->Stock.getItem(i)->getName(), 1, 1);
					playerInv->addItem(vessel);

					if (r->Stock.getItem(i)->getName() == stringContainer->radioCommand)
					{
						radiot = 1; AddInv(); boolyboi = 1;
					}
					else if (r->Stock.getItem(i)->getName() == stringContainer->tapeCommand)
					{
						tapet = 1; AddInv(); boolyboi = 1;
					}
					else if (r->Stock.getItem(i)->getName() == stringContainer->glovesCommand)
					{
						glovest = 1; AddInv(); boolyboi = 1;
					}
					else if (r->Stock.getItem(i)->getName() == stringContainer->flashlightCommand)
					{
						lightt = 1; AddInv(); boolyboi = 1;
					}
					r->Stock.removeItem(i);
				}
			}
		}
	}
	if (boolyboi == 0)
	{
		Output(stringContainer->itemCouldNotBeFoundLast);
	}
}