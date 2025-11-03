#include "Rooms.h"


Room* rooms[4][4];
int playerX = 0;
int playerY = 0;
int playerHealth = 3;
int main()
{
// initialises the map before the player does anything
initialiseMap(rooms);

char input;

// displays the map including the player position (starts at top left)
displayMap(rooms, playerX, playerY);

while (true)
{
	// gets player input for movement, works in a way such that only wasd inputs are accepted, and anything else does nothing
	cout << "Enter command (w/a/s/d to move): ";
	cin >> input;
	
	// wasd movement, also uses the initialised room data to check if the player is allowed to move that way, and if so, does
	if (input == 'w' && rooms[playerX][playerY]->doorNorth) playerY--;
	else if (input == 's' && rooms[playerX][playerY]->doorSouth) playerY++;
	else if (input == 'a' && rooms[playerX][playerY]->doorWest) playerX--;
	else if (input == 'd' && rooms[playerX][playerY]->doorEast) playerX++; 

	displayMap(rooms, playerX, playerY);
	rooms[playerX][playerY]->specialRoomFunction();

	// if the player is in the bottom right corner of the map
	if (playerX == 3 && playerY == 3)
	{
		// displays where they are on the map one last time, and a message saying they have won
		displayMap(rooms, playerX, playerY);
		cout << "You have reached the end of the maze. To play again, please close and reopen the program." << endl;
		break;
	}
}
// pauses the program before exiting so the player can see the win message
system("pause");
return 0;
}