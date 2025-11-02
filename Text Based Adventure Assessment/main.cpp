#include "Rooms.h"

Room rooms[4][4];
int playerX = 0;
int playerY = 0;
int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			rooms[i][j] = Room(i, j);
		}
	}
	char input;
	while (true)
	{
		displayMap(rooms, playerX, playerY);
		rooms[playerX][playerY].displayRoom(playerX, playerY);
		
		cout << "Enter command (w/a/s/d to move): ";
		cin >> input;
		
		if (input == 'w' && playerY > 0) playerY--;
		else if (input == 's' && playerY < 3) playerY++;
		else if (input == 'a' && playerX > 0) playerX--;
		else if (input == 'd' && playerX < 3) playerX++;

		if (playerX == 3 && playerY == 3)
		{
			displayMap(rooms, playerX, playerY);
			cout << "You have reached the end of the maze." << endl;
			break;
		}
	}
	return 0;
}