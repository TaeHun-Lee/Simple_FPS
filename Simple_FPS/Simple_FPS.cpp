#include "pch.h"
#include <windows.h>
#include <process.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Map
{
private:
	int width = 10;
	int height = 10;
	char player = 'O';
	char wall = '=';
	int playerCoord[2];
	int wallCoord[5][2];
public:
	void playerSet() {
		srand((unsigned int)time(NULL));
		playerCoord[0] = rand() % 8 + 1;
		playerCoord[1] = rand() % 8 + 1;
	}

	void wallSet() {
		srand((unsigned int)time(NULL));
		for (int i = 0; i < 5; i++) {
			while ((wallCoord[i][0] = rand() % 8 + 1) == playerCoord[0]);
			while ((wallCoord[i][1] = rand() % 8 + 1) == playerCoord[1]);
		}
	}

	bool wallCheck(int row, int column) {
		for (int i = 0; i < 5; i++) {
			if (row == wallCoord[i][0] && column == wallCoord[i][1])
				return true;
		}
		return false;
	}


	void makeMap() {
		bool isWall = false;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (isWall = wallCheck(i, j) == true) {
					cout << wall;
				}
				if (!isWall) {
					if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
						cout << "*";
					else if (i == playerCoord[0] && j == playerCoord[1]) {
						cout << player;
					}
					else
						cout << " ";
				}
				isWall = false;
			}
			cout << endl;
		}
	}
	void move() {
		char input;
		switch (input = _getch()) {
		case 'w':
			if (playerCoord[0] > 1 && !wallCheck(playerCoord[0]-1, playerCoord[1]) )
				playerCoord[0] = playerCoord[0] - 1;
			break;
		case 'a':
			if (playerCoord[1] > 1 && !wallCheck(playerCoord[0], playerCoord[1]-1) )
				playerCoord[1] = playerCoord[1] - 1;
			break;
		case 's':
			if (playerCoord[0] < 8 && !wallCheck(playerCoord[0]+1, playerCoord[1]) )
				playerCoord[0] = playerCoord[0] + 1;
			break;
		case 'd':
			if (playerCoord[1] < 8 && !wallCheck(playerCoord[0], playerCoord[1]+1) )
				playerCoord[1] = playerCoord[1] + 1;
			break;
		default:
			break;
		}
		system("cls");
		makeMap();
	}
};


int main()
{
	Map* mapObj = new Map();
	mapObj->playerSet();
	mapObj->wallSet();
	mapObj->makeMap();
	while (1)
		mapObj->move();
	delete mapObj;
}