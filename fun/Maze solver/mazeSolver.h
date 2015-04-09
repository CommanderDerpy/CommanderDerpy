#ifndef _MAZESOLVER_H_
#define _MAZESOLVER_H_

class  theMaze{

private:
	char maze[20][20];
	bool debug;

public:
	theMaze(bool);
	~theMaze();

	void randomMaze();
	void drawMaze();
	void predefinedMaze();
	bool solveMaze();
};


#endif
