#include <iostream>

#include "mazeSolver.h"

using namespace std;

int main() {
	cout << "Hi" << endl;

	theMaze *maze = new theMaze(true);

	maze->randomMaze();
	maze->drawMaze();

	while (maze->solveMaze());

	cout << endl << endl << endl << "We are done here" << endl;
	return 0;
}