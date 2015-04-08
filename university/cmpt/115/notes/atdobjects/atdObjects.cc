#include <iostream>
#include <string>

using namespace std;
#include "objects.h"

int main() {
	Game* nGame = new Game;
	cout << "setting up game.." << endl;
	nGame->setUp();
	cout << "drawing game.." << endl;
	nGame->drawGame();

	cout << "Spawning monsters.." << endl;
	nGame->spawnMonsters(25);
	nGame->spawnUnits(25);
	cout << "drawing game.." << endl;
	nGame->drawGame();
}