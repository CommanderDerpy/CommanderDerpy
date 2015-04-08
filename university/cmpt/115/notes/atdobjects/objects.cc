#include "objects.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Game::Game() {
	
}

void Game::unused() {
		cout << "    " << 1;
	for (int i = 1; i < 9; ++i) {
		cout << "   " << i+1;
	}
	cout << "  ";
	for (int i = 9; i < 15; ++i) {
		cout  << i+1 << "  ";
	} 
	cout << endl;
	for (int i = 0; i < 15; ++i) {
		cout << i+1 << " ";
			if (i < 9) cout << " ";
		for (int i = 0; i < 15; ++i) {	
			cout << "[ ] ";
		}
		cout << endl;
	}
}
void Game::setUp() {
	for (int c = 0; c < 15; ++c)
	{
		for (int i = 0; i < 15; ++i)
		{
			gameField[c][i] = ' ';
		}
	}
}

void Game::drawGame() {
			cout << "    " << 1;
	for (int i = 1; i < 9; ++i) {
		cout << "   " << i+1;
	}
	cout << "  ";
	for (int i = 9; i < 15; ++i) {
		cout  << i+1 << "  ";
	} 
	cout << endl;
	for (int c = 0; c < 15; ++c) {
		cout << c+1 << " ";
			if (c < 9) cout << " ";
		for (int i = 0; i < 15; ++i) {	
			cout << "[" << gameField[c][i] << "]" << " ";
		}
		cout << endl;
	}
}

void Game::spawnMonsters(int numberOfEnemies) {
	srand (time(NULL));
	for (int i = 0; i < numberOfEnemies; ++i) {
		int x = rand() % 16;
		int y = rand() % 5;
		if (gameField[x][y] == ' ') {
			gameField[x][y] = 'E';	
		} else {
			i = i - 1;
		}
	}
}

void Game::spawnUnits(int numberOfUnits) {
	srand (time(NULL));
	for (int i = 0; i < numberOfUnits; ++i) {
		int x = rand() % 16;
		int y = rand() % 5 + 10;
		if (gameField[x][y] == ' ') {
			gameField[x][y] = 'S';	
		} else {
			i = i - 1;
		}
	}
}