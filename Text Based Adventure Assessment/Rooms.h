#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

string EmptyRoomDescription = "This is an empty room. Your only option is to move.";
string PuzzleRoomDescription = "This is a puzzle room. You have to solve this equation to continue.";
string WrongRoomDescription = "You have gone the wrong way, You should turn around.";

class Room
{
private:
	int xCoord, yCoord;
public:
	bool doorNorth, doorSouth, doorEast, doorWest;
	string description;
	// constructors
	Room()
	{
		xCoord = 0;
		yCoord = 0;
		doorNorth = false;
		doorSouth = false;
		doorEast = false;
		doorWest = false;
		description = "peepee";
	}
 
	Room(int x, int y, bool dN, bool dS, bool dE, bool dW, string desc)
	{
		xCoord = x;
		yCoord = y;
		doorNorth = dN;
		doorSouth = dS;
		doorEast = dE;
		doorWest = dW;
		description = desc;
	}
	
	char displayRoom(int x, int y)
	{
		// if the player's position = the room's position, return 'X', else return ' ', to be used as the marker for where they are
		if (x == xCoord && y == yCoord)
		{
			return 'X';
		}
		else
		{
			return ' ';
		}
	}

	virtual void specialRoomFunction()
	{
		// base Room class has no special function, so does nothing
	}
};

class EmptyRoom : public Room
{
public:
	// uses the same constructors as Room
	EmptyRoom() : Room() {}
	EmptyRoom(int x, int y, bool dN, bool dS, bool dE, bool dW, string desc) : Room(x, y, dN, dS, dE, dW, desc) { desc = EmptyRoomDescription; }

	// same displayRoom function as Room
	char displayRoom(int x, int y)
	{
		return Room::displayRoom(x, y);
	}

	void specialRoomFunction()
	{
		// empty room has no special function, so always does nothing
	}
};
class PuzzleRoom : public Room
{
public:
	// uses the same constructors as Room
	PuzzleRoom() : Room() {}
	PuzzleRoom(int x, int y, bool dN, bool dS, bool dE, bool dW, string desc) : Room(x, y, dN, dS, dE, dW, desc) { desc = PuzzleRoomDescription; }

	// same displayRoom function as Room
	char displayRoom(int x, int y)
	{
		return Room::displayRoom(x, y);
	}

	void specialRoomFunction()
	{
		while (true)
		{
			int rand1 = rand() % 1000;
			int rand2 = rand() % 1000;
			int answer;
			cout << "What is " << rand1 << "+" << rand2 << endl;
			cin >> answer;

			// input validation to ensure a number, and that if the number is over int limits it doesn't break the program
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a number." << endl;
				continue;
			}

			if (answer == (rand1 + rand2) - 0)
			{
				cout << "Correct! You may proceed." << endl;
				break;
			}
			else
			{
				cout << "Incorrect. Try again." << endl;
			}
		}
	}
};
class WrongRoom : public Room
{
public:
	WrongRoom() : Room() {}
	WrongRoom(int x, int y, bool dN, bool dS, bool dE, bool dW, string desc) : Room(x, y, dN, dS, dE, dW, desc) { desc = WrongRoomDescription; }

	char displayRoom(int x, int y)
	{
		return Room::displayRoom(x, y);
	}

	void specialRoomFunction()
	{
		// no special function implemented
	}
};

void displayMap(Room* rooms[4][4], int playerX, int playerY)
{
    // Clears the console by printing 50 new lines
    for (int i = 0; i < 50; i++)
    {
        cout << endl;
    }
	
    // displays the map with the player's position marked by an 'X', and a space if the player is not in that room
    cout << "-----------------" << endl;
    cout << "| " << rooms[0][0]->displayRoom(playerX, playerY) << " | " << rooms[1][0]->displayRoom(playerX, playerY) << " | " << rooms[2][0]->displayRoom(playerX, playerY) << " | " << rooms[3][0]->displayRoom(playerX, playerY) << " |" << endl;
    cout << "| " << rooms[0][1]->displayRoom(playerX, playerY) << " | " << rooms[1][1]->displayRoom(playerX, playerY) << " | " << rooms[2][1]->displayRoom(playerX, playerY) << " | " << rooms[3][1]->displayRoom(playerX, playerY) << " |" << endl;
    cout << "| " << rooms[0][2]->displayRoom(playerX, playerY) << " | " << rooms[1][2]->displayRoom(playerX, playerY) << " | " << rooms[2][2]->displayRoom(playerX, playerY) << " | " << rooms[3][2]->displayRoom(playerX, playerY) << " |" << endl;
    cout << "| " << rooms[0][3]->displayRoom(playerX, playerY) << " | " << rooms[1][3]->displayRoom(playerX, playerY) << " | " << rooms[2][3]->displayRoom(playerX, playerY) << " | " << rooms[3][3]->displayRoom(playerX, playerY) << " |" << endl;
    cout << "-----------------" << endl;

	cout << rooms[playerX][playerY]->description << endl;
}

void initialiseMap(Room* rooms[4][4])
{
	// Manually sets up each room in the 4x4 grid with each room's ways to move. Also allows for changing of classes in code easily if needed
	rooms[0][0] = new EmptyRoom(0, 0, false, true, false, false, EmptyRoomDescription); rooms[1][0] = new WrongRoom(1, 0, false, true, false, false, WrongRoomDescription); rooms[2][0] = new PuzzleRoom(2, 0, false, true, true, false, PuzzleRoomDescription); rooms[3][0] = new EmptyRoom(3, 0, false, true, false, false, EmptyRoomDescription);
	rooms[0][1] = new PuzzleRoom(0, 1, true, true, false, false, PuzzleRoomDescription); rooms[1][1] = new PuzzleRoom(1, 1, true, true, true, false, PuzzleRoomDescription); rooms[2][1] = new EmptyRoom(2, 1, true, true, false, true, EmptyRoomDescription); rooms[3][1] = new EmptyRoom(3, 1, true, true, false, false, EmptyRoomDescription);
	rooms[0][2] = new EmptyRoom(0, 2, true, true, true, false, EmptyRoomDescription); rooms[1][2] = new EmptyRoom(1, 2, true, true, false, true, EmptyRoomDescription); rooms[2][2] = new WrongRoom(2, 2, true, true, false, false, WrongRoomDescription); rooms[3][2] = new PuzzleRoom(3, 2, true, true, false, false, PuzzleRoomDescription);
	rooms[0][3] = new WrongRoom(0, 3, true, false, false, false, WrongRoomDescription); rooms[1][3] = new WrongRoom(1, 3, true, true, false, false, WrongRoomDescription); rooms[2][3] = new WrongRoom(2, 3, true, false, false, false, WrongRoomDescription); rooms[3][3] = new EmptyRoom(3, 3, false, false, false, false, EmptyRoomDescription);
}