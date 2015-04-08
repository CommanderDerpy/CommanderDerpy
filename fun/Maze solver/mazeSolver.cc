#include <iostream>
#include "mazeSolver.h"

using namespace std;

theMaze::theMaze() {
	cout << "Hi new maze" << endl;
	for (int i = 0; i < 20; ++i)
	{
		for (int c = 0; c < 20; ++c)
		{
			maze[i][c] = 'X';
		}
	}
	cout << "Hi new maze end" << endl;
}

theMaze::~theMaze() {
	cout << "Deleting maze..." << endl;
}

void theMaze::predefinedMaze() {

}

void theMaze::drawMaze() {
	cout << "===============================================" << endl;
	for (int i = 0; i < 20; ++i) {
		cout << "|  ";
		for (int c = 0; c < 20; ++c) {

			cout << maze[i][c] << " ";

		}
		cout << "  |"<< endl;
	}
	cout << "===============================================" << endl;
}