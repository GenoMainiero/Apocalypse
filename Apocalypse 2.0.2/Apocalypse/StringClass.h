#pragma once
#include <iostream>
using namespace std; 

class StringContainer {
public:
	//Help Method Strings
	string helpMenu[9] = { "                                   Help Menu                      ",
						  "                                  -----------                     ",
						  "\nTo move throughout the city, use the following commands : North, East, South, West",
						  "\nTo interact with items, use the following commands: Search, Take, Eat, Drink, Use",
						  "\nItems may have *asterisks* to denote the keyword you should use to interact with it.",
						  "\nTo show your inventory, type inventory or inv.",
						  "\nTo show your current location, type location.",
						  "\nYou may only enter one command per line.",
						  "\nTo exit the game at any time, type exit or quit." };

	string moveHelpMenu[2] = { "To move throughout the city, use the following commands: North, East, South, West",
							   "\nFor more help at any time, type help." };

	string useItemQuestion = "Which item would you like to use?\n";

	string inventoryCheckStrings[6] = { "Here is your inventory:\n",
										"food",
										"Food: ",
										"water",
										"Water: ",
										"     " };

	string nextStrings[4] = { "What would you like to do next?", "What's next?", "What is your next move?", "Now what would you like to do?" };

	string descriptionPlaceHolder = "This is a sample description.";

	string movementStrings[4] = { "A chemical spill blocks your path. There is no way around it.", "Ahead is a flood that may be electrified. You'd better not risk it.",
		"It's too dark to see anything...", "There are several burning buildings in this direction, but one looks mostly undamaged." };

	string errorStrings[4] = { "You cannot do that here.", "That is an unrecognized command.", "I did not understand what you said.", "Invalid command." };

	string errorInvOutput = "You do not have this item.";

	string chemFireDescription = "Chemical Fire! Ouch!!!";
	string streetDescription = "\nThis desolate road makes you very aware of how empty the city is.";
	string eastStreetDescription = "\nYou are in the middle of a street. You see a safe house in the distance to the west.";
	string safeHouseLongDescription = "\nYou arrive to the only building that withstood the apocalypse.\nThis building has been marked as the safe house for the town and people who survived take refuge in its high structure.\nThe building consists of 28 floors and its design reminds you of those 1980's hotels.\nYou can see ruble of the other buildings creating a perfect path to the doors that are lined with a gold trim.\nThe building truly resembles a beacon of hope.";
	string radioTowerDescription = "\nYou enter a radio tower, but it is too dark to see anything.";
	string radioShackDescription = "\nYou are now in the Radio Shack store, essential communication supplies can be found here.";
	string militartBaseLongDescription = "\nThis is where it all started. Such a big explosion and everything has changed.\nMany soldiers used to run around here and now this military base is nothing.";
	string airportLongDescription = "\nYou finally arrive to the airport where the airplanes have all departed before the apocalypse hit.\nThe sight of the airport being deserted gives you a sense of depression and makes you feel alone.\nHowever there is hope that with all the materials you have you are able to create a means of contacted for a ride to salvation.";
	string clothingStoreDescription = "\nYou are now inside the clothing store H&M, oh you fancy huh?";
	string bankLongDescription = "\nYou see a colossal building that has greek lettering on it.\nThis is the central bank of the city.\nIt has the designs of Ancient Greek buildings with its huge pillars supporting its triangular roof the seems to have caved in a bit.\nOne of the pillars is actually broken in half and part of the ruling is missing.\nYet it still has a way to appear magnificent in a time of despair.\nThe entrance is a humungous bi-folding door that has gold trim around to show that it is full of wealth.\nThe steps has rouble around it and there is a lonely tree stump that is seen next to it.\nMaybe there is something useful in the security boxes.";
	string hospitalLongDescription = "\nThe city hospital once a place for health and hope is now a wasteland.\nThis hospital had about 7 buildings all interconnected by bridges but now there is but just one building up and seems to be stable.\nThe place is deserted and gives a haunting vibe.\nInside there is medicine that was left from before the apocalypse which can help in restoring my health in bad times.";
	string hazardDescription = "\nBe careful! This is a hazardous area that cannot be accessed!!";
	string hazard1Description = "\nThis is a hazardous area that can be accessed; However, you're at risk!";
	string boundryDescription = "\nThis is a dangerous area! You cannot go here!";

	string north = "north", south = "south", west = "west", east = "east";

	string welcomeMenuOutputs[2] = { "Welcome to Apocalypse!", 
								  "\n\nYou are the only living person in a large city following a series of natural disasters.\nThere is reason to believe that others have survived in neighboring cities.\nA nearby radio tower can be used to communicate with these survivors.\nYour mission is to find this radio tower and get rescued.\n\nThe following is a list of commands to help you navigate through the game:\n" };
	string firstMoveQuestion = "\n\nWhat is your first move ? \n";

	string hungerOuputs[4] = { "You are fairly hungry.\n",
							   "You are dangerously hungry. Eat soon.\n",
							   "You are very weak. If you do not eat, you will perish.\n",
							   "You have died from hunger...\n" };

	string thirstOutputs[4] = { "You are very thirsty.\n",
								"You are dangerously thirsty. Drink some water.\n",
								"The world is spinning. If you do not drink some water, you will soon perish.\n",
								"You have died from thirst...\n" };

	string flashlightUserOutput = "\nA radio tower illuminated by your flashlight.";

	string helpCommand = "help", searchCommand = "search", openCommand = "open",
		closeCommand = "close", takeCommand = "take", dropCommand = "drop", eatCommand = "eat", drinkCommand = "drink",
		inventoryCommand = "inventory", inventoryCommand2 = "inv", useCommand = "use", locationCommand = "location",
		moveCommand = "move", exitCommand = "exit", quitCommand = "quit", foodCommand = "food", waterCommand = "water",
		glovesCommand = "gloves", tapeCommand = "tape", radioCommand = "radio", flashlightCommand = "flashlight",
		crowbarCommand = "crowbar", yesCommand = "yes", pauseCommand = "pause";

	string exitQuestionOutput = "Are you sure you want to exit? (Y/N)\n";
	string resumeGameOutput = "Resuming game...\n";

	string searchingOutput = "Searching...\n";
	string foundItemsOutput = "You found the following items...\n";

	string tooDarkOutput = "It is too dark to see anything in here...";
	string nothingOfInterestOutput = "There is nothing of interest in this area.";
	string openingOutput = "Opening...", closingOutput = "Closing...", droppingOutput = "Dropping...",
		eatingOutput = "Eating...", yummyOutput = "\nYummy!", drinkingOutput = "Drinking...",
		refreshingOutput = "\nThat was refeshing!";

	string takeQuestionOutput = "What would you like to take?\n";
	string outOfFoodOutput = "You don't have any food left!";
	string outOfWater = "You are all out of water!";
	string useQuestionOutput = "What would you like to use?\n";
	string eatAndDrinkPrompt = "Try the command *eat* for food, or *drink* for water!";
	string puttingGlovesOnOutPut = "You put on the gloves. You are now safe from electical shock.";
	string radioFixedOutput = "The radio has been fixed!";
	string mightGetShocked = "You shouldn't do this yet! You might get shocked!";
	string noItemsNeedFixing = "You don't have any items that need fixing!";
	string whatToSayOutput = "\nPlease select what you would like to say:\n";
	string radioCrackleOutput = "The radio crackles, then becomes silent. You say \"Hello\" into the radio, and await a response...\n";
	string radioStirsOutput = "Finally, the radio stirs, and you hear a woman's voice, calm and collected.\n";
	string nameQuestionOutput = "\"Hello. What is your name?\"\nName: ";
	string carolineGreetingOutput = ". My name is Caroline. How can we help you?\"";
	string whereAreYou = "A: Where are you?\nB: How can I get out of here?\n";
	string survivorOutput = "\n\"I am in a survivor community based in Brazil.\"";
	string survivorsQuestionOutput = "A: How many survivors are there?\nB: How can I get out of here?";

	string survivorsConvo[4] = { "\n\"We have several thousand survivors here, but we believe there are many more out there.\"",
								 "\n\"There is something that you need to know.\"",
								 "\n\"Our radar has detected a radioactive wave closing in on your current location.\nThere is a safehouse in your city that will be able to protect you.\nYou must get there as quickly as possible, do not stop, do not delay.\nAs soon as the wave passes, we will be at the airport waiting for you.\"\n",
								 "\nYou thank Caroline for her warning, and prepare to leave for the safehouse.\n" };

	string airplaneConvo[4] = { "\"We will send an airplane to pick you up at the airport.\"",
								"\n\"There is something that you need to know.\"",
								"\n\"Our radar has detected a radioactive wave closing in on your current location.\nThere is a safehouse in your city that will be able to protect you.\nYou must get there as quickly as possible, do not stop, do not delay.\nAs soon as the wave passes, we will be at the airport waiting for you.\"\n",
								"\nYou thank Caroline for her warning, and prepare to leave for the safehouse.\n" };

	string invalidSelectionOutput = "That is not a valid selection.\n";
	string airplaneSentOutput = "\n\"We will send an airplane to pick you up.\"";
	string planeMeetQuestionOutput = "A: When should I meet the plane?\nB: *Say nothing and leave for the airport.*\n";
	string radioactiveWaveConvo[3] = { "\n\"We will try to pick you up as soon as possible, but there is something you should know...\"\n",
									   "\n\"Our radar has detected a radioactive wave closing in on your current location.\nThere is a safehouse in your city that will be able to protect you.\nYou must get there as quickly as possible, do not stop, do not delay.\nAs soon as the wave passes, we will be at the airport waiting for you.\"\n",
									   "You thank Caroline for her warning, and prepare to leave for the safehouse.\n"};

	string prepareToLeaveAirportPrompt = "\nYou switch off the radio and prepare to leave for the airport.\n";

	string radioNoResponseOutput = "You try the radio, but there is no response...";
	string radioWeakSignal = "The radio doesn't have a strong enough signal here.";
	string radioBroken = "This radio is clearly broken.";

	string flashlightOnOutput = "The flashlight flickers on and illuminates the room.";
	string itemNoEffectOutput = "This item has no effect here.", itemNoUseOutput = "You have no use for this item right now.";

	string playAgainPrompt = "Thanks for playing!\nWould you like to play again?(Y/N)\n";
	string gameResumed = "Game resumed.";

	string movingNorthOutput = "Moving North... ", movingEastOutput = "Moving East...",
		movingWestOutput = "Moving West...", movingSouthOutput = "Moving South...";

	string diedInWasteLandOutput = "Sorry, you have died in the wasteland.\n";
	string congradulationsOutput = "\nCongratulations!\nYou have been rescued at the airport, and have successfully survived...\n\nApocalpyse.";

	string badMoveOutput = "You should not have done that. You perished alone in the city.\n";

	string lastMoveDead = "That move was your last... You have died!\n";
	string lightBeaconsDead = "The light at the end of the tunnel beckons... You have died.\n";

	string madeItToSafeHouseOutput = "You have successfully made it to the safe house.\nYou are tired from running and lay down for a nap while the storm passes...";
	string stormOverOutput = "\nThe storm is over. Caroline said that an airplane would meet you at the airport.";

	string mustMovetoSafeHouseOutput = "You don't have time for that right now, you must move to the safehouse to avoid the storm!";
	
	string addingToInventoryOutput = "Adding to inventory...";
	string addedToInvetoryOutput = "\nSuccessfully added to inventory.";

	string itemNotInInventory = "This item could not be found in your inventory.";

	string itemCouldNotBeFoundLast = "That item could not be found...";


	//INVENTORY CLASS STRINGS

	string standInDescription = "STANDIN DESCRIPTION\n";
	string blockedByOutput = "\nBlocked by ";
	string floodOutput = "flood.\n";
	string chemicalSpillOutput = "Chemical Spill.\n";
	string largeFireOutput = "a large fire!\n";
	string rubbleOutput = "rubble.\n";
	string somethingOutput = "something.\n";
	string previousLocationOutput = "Returning to previous location...";
	string locationWarning = "Are you sure you would like to go this way? This could prove to be fatal.\n(Y/N):\t";
	string answerQuestion = "Please answer the question...\n";
	string returningOutput = "Returning...";
	string commandNotRecognizedOutput = "Command not recognized...\n";
};