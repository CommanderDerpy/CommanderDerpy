#include <iostream>
#include <fstream>
#include <cstdlib>
#include "mazeSolver.h"

using namespace std;

//Pre: non
//Post: constructs the maze with walls
//Return: non non
theMaze::theMaze(bool foo) {

	debug = foo;

	if (debug == true) {
		cout << "Debug mode is on" << endl;
		cout << "DEBUG:    Maze constructor start" << endl;
	}
	for (int i = 0; i < 20; ++i)
	{
		for (int c = 0; c < 20; ++c)
		{
			if (i == 0) {
				maze[i][c] = 'X';
			} else if (i == 19) {
				maze[i][c] = 'X';
			} else if (c == 0) {
				maze[i][c] = 'X';
			} else if (c == 19) {
				maze[i][c] = 'X';
			} else {
				maze[i][c] = ' ';
			}
		}
	}

	maze[0][3] = 'S';
	maze[19][16] = 'E';
	if (debug == true) {
		cout << "DEBUG:    Maze constructor end" << endl;
	}
}

//Pre: non
//Post: deletes the object
//Return: non
theMaze::~theMaze() {
	cout << "Deleting maze..." << endl;
}

//Pre: non
//Post: creates a pre defined maze for testing only
//Return: non
void theMaze::predefinedMaze() {
	//decalre file
	ifstream myFile;
	//open file
	myFile.open("predefinedMaze.txt");

	if(myFile.is_open()) {
		for (int i = 0; i < 20; ++i) {
			for (int c = 0; c < 20; ++c) {
				//feed text into the maze

				maze[i][c] = myFile.get();
				myFile.ignore();
				myFile.ignore();
				myFile.ignore();

			}
		}
	}
}
//Pre: non
//Post: gives a random maze
//Return: non
void theMaze::randomMaze() {
	srand(time(NULL));
	int random;

	for (int i = 1; i < 19; ++i) {
		for (int c = 1; c < 19; ++c) {
			random = rand() % 3;
			if(random == 1) {
				maze[i][c] = 'X';
			} 
		}
	}
}

//Pre: non
//Post: drawa the maze to the screen
//Return: non
void theMaze::drawMaze() {
	if (debug == true) {
		cout << "DEBUG:    drawMaze start" << endl;
	}

	cout << "==============================================" << endl;
	for (int i = 0; i < 20; ++i) {
		cout << "|  ";
		for (int c = 0; c < 20; ++c) {

			cout << maze[c][i] << " ";

		}
		cout << "  |"<< endl;
	}
	cout << "==============================================" << endl;

	if (debug == true) {
		cout << "DEBUG:    drawMaze end" << endl;
	}	
}

bool theMaze::solveMaze() {


	return true;
}