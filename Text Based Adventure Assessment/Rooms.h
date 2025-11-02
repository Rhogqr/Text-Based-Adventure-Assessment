#pragma once
#include <iostream>

using namespace std;

class Room
{
private:
	int xCoord, yCoord;
public:
	bool doorNorth, doorSouth, doorEast, doorWest;
	// constructors
	Room()
	{
		xCoord = 0;
		yCoord = 0;
		doorNorth = false;
		doorSouth = false;
		doorEast = false;
		doorWest = false;
	}
 
	Room(int x, int y, bool dN, bool dS, bool dE, bool dW)
	{
		xCoord = x;
		yCoord = y;
		doorNorth = dN;
		doorSouth = dS;
		doorEast = dE;
		doorWest = dW;
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
};

class EmptyRoom : public Room
{
	// uses the same constructors as Room
	EmptyRoom() : Room() {}
	EmptyRoom(int x, int y, bool dN, bool dS, bool dE, bool dW) : Room(x, y, dN, dS, dE, dW) {}

	// same displayRoom function as Room
	char displayRoom(int x, int y)
	{
		return Room::displayRoom(x, y);
	}
};

void displayMap(Room rooms[4][4], int playerX, int playerY)
{
	// Clears the console by printing 50 new lines
	for (int i = 0; i < 50; i++)
	{
		cout << endl;
	}
	// displays the map with the player's position marked by an 'X', and a space if the player is not in that room
	cout << "-----------------" << endl;
	cout << "| " << rooms[0][0].displayRoom(playerX, playerY) << " | " << rooms[1][0].displayRoom(playerX, playerY) << " | " << rooms[2][0].displayRoom(playerX, playerY) << " | " << rooms[3][0].displayRoom(playerX, playerY) << " |" << endl;
	cout << "| " << rooms[0][1].displayRoom(playerX, playerY) << " | " << rooms[1][1].displayRoom(playerX, playerY) << " | " << rooms[2][1].displayRoom(playerX, playerY) << " | " << rooms[3][1].displayRoom(playerX, playerY) << " |" << endl;
	cout << "| " << rooms[0][2].displayRoom(playerX, playerY) << " | " << rooms[1][2].displayRoom(playerX, playerY) << " | " << rooms[2][2].displayRoom(playerX, playerY) << " | " << rooms[3][2].displayRoom(playerX, playerY) << " |" << endl;
	cout << "| " << rooms[0][3].displayRoom(playerX, playerY) << " | " << rooms[1][3].displayRoom(playerX, playerY) << " | " << rooms[2][3].displayRoom(playerX, playerY) << " | " << rooms[3][3].displayRoom(playerX, playerY) << " |" << endl;
	cout << "-----------------" << endl;
}

void initialiseMap(Room rooms[4][4])
{
	// Manually sets up each room in the 4x4 grid with each room's ways to move. Also allows for changing of classes in code easily if needed
	rooms[0][0] = Room(0, 0, false, true, false, false); rooms[1][0] = Room(1, 0, false, true, false, false); rooms[2][0] = Room(2, 0, false, true, true, false); rooms[3][0] = Room(3, 0, false, true, false, false);
	rooms[0][1] = Room(0, 1, true, true, false, false); rooms[1][1] = Room(1, 1, true, true, true, false); rooms[2][1] = Room(2, 1, true, true, false, true); rooms[3][1] = Room(3, 1, true, true, false, false);
	rooms[0][2] = Room(0, 2, true, true, true, false); rooms[1][2] = Room(1, 2, true, true, false, true); rooms[2][2] = Room(2, 2, true, true, false, false); rooms[3][2] = Room(3, 2, true, true, false, false);
	rooms[0][3] = Room(0, 3, true, false, false, false); rooms[1][3] = Room(1, 3, true, true, false, false); rooms[2][3] = Room(2, 3, true, false, false, false); rooms[3][3] = Room(3, 3, false, false, false, false);
}