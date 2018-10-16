#include <iostream>
#include <string>
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
void Use()
{
	string item, room;
	char input;
	Output(" Which item would you like to use?\n");
	getline(cin, item);
	Output(" Which room are you in?\n");
	getline(cin, room);
	
		if (room == "safehouse" && item == "water")
		{
			input = 'a';
		}
		else if (room == "safehouse" && item == "bread")
		{
			input = 'b';
		}
		else if (room == "radiotower" && item == "flashlight")
		{
			input = 'c';
		}
		else if (room == "radiotower" && item == "electricalinsulatinggloves")
		{
			input = 'd';
		}
		else if (room == "radiotower" && item == "electricaltape")
		{
			input = 'e';
		}
		else if (room == "radiotower" && item == "radio")
		{
			input = 'f';
		}
		else
		{
			input = 'g';
		}

		switch (input)
		{
		case 'a': Output(" This water is cold and replenishing!\n");
			break;
		case 'b':Output(" This garlic bread is delicious!\n");
			break;
		case 'c':Output(" Flashlight is now on, now I can see better!\n");
			break;
		case 'd':Output(" Putting on electricalgloves..\n");
			break;
		case 'e':Output(" Now using electrical tape..\n");
			break;
		case 'f':Output(" Communicating with other survivors..\n");
			break;
		case 'g':Output(" Cannot use that tool here...\n");
			break;
		default: Output(" Cannot use here..\n");
			break;
		}



}

int main()
{
	Use();
	system("pause");
	return 0;
}