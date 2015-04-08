#ifndef _OBJECT_H_
#define _OBJECT_H_

class Game {
private:
	char gameField[15][15];
public:
	Game();
	void unused();
	void setUp();
	void drawGame();
	void spawnMonsters(int numberOfEnemies);
	void spawnUnits(int numberOfUnits);
	~Game();
};

#endif