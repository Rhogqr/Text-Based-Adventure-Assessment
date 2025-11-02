#pragma once
#include <iostream>

using namespace std;

class Room
{
private:
	int xCoord, yCoord;
public:
public:
	Room()
	{
		xCoord = 0;
		yCoord = 0;
	}
 
	Room(int x, int y)
	{
		xCoord = x;
		yCoord = y;
	}

	char displayRoom(int x, int y)
	{
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

void displayMap(Room rooms[4][4], int playerX, int playerY)
{
	for (int i = 0; i < 25; i++)
	{
		cout << endl;
	}
	cout << "-----------------" << endl;
	cout << "| " << rooms[0][0].displayRoom(playerX, playerY) << " | " << rooms[1][0].displayRoom(playerX, playerY) << " | " << rooms[2][0].displayRoom(playerX, playerY) << " | " << rooms[3][0].displayRoom(playerX, playerY) << " |" << endl;
	cout << "| " << rooms[0][1].displayRoom(playerX, playerY) << " | " << rooms[1][1].displayRoom(playerX, playerY) << " | " << rooms[2][1].displayRoom(playerX, playerY) << " | " << rooms[3][1].displayRoom(playerX, playerY) << " |" << endl;
	cout << "| " << rooms[0][2].displayRoom(playerX, playerY) << " | " << rooms[1][2].displayRoom(playerX, playerY) << " | " << rooms[2][2].displayRoom(playerX, playerY) << " | " << rooms[3][2].displayRoom(playerX, playerY) << " |" << endl;
	cout << "| " << rooms[0][3].displayRoom(playerX, playerY) << " | " << rooms[1][3].displayRoom(playerX, playerY) << " | " << rooms[2][3].displayRoom(playerX, playerY) << " | " << rooms[3][3].displayRoom(playerX, playerY) << " |" << endl;
	cout << "-----------------" << endl;
}