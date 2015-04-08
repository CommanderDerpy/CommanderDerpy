#ifndef _MAZESOLVER_H_
#define _MAZESOLVER_H_

class  theMaze{

private:
	char maze[20][20];

public:
	theMaze();
	~theMaze();

	void drawMaze();
	void predefinedMaze();
};


#endif
