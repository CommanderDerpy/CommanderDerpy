/* 
 * Maximilian Gewers 
 * 11163599
 * CMPT - 115 - 02
 * CMPT - 115 - T08
 */
 

/*
 *  testPoint.cpp
 *  Do a bit of work with the Point class
 *
 */

#include <iostream>
using namespace std;

#include "Point.h"


int main() { 

	cout << "Enter 2 points, X and Y : ";
	float x = 0;
	float y = 0;
	cin >> x >> y;
	Point* nPoint = new Point(x,y);
	//nPoint->setX(x);
	//nPoint->setY(y);
	cout << "Point has coordinates: ";
	cout << nPoint->getX() << ", " << nPoint->getY() << endl;

	nPoint->displacement();
	delete nPoint;

	cout << endl << endl;

	cout << "Creating a new point on the stack..." << endl;
	Point p(0,0);

	cout << "Point has coordinates: ";
	cout << p.getX() << ", " << p.getY() << endl;

  return 0; 
} 
