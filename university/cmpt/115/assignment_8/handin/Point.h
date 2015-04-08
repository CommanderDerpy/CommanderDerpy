/* 
 * Maximilian Gewers 
 * 11163599
 * CMPT - 115 - 02
 * CMPT - 115 - T08
 */
 

 /*
 * Point.h
 *  A simple example class
 *  The interface definition
 */


#ifndef _POINT_H_
#define _POINT_H_

class Point { 

private: 
  float x; // stores the x coordinate 
  float y; // stores the y coordinate 

public: 
  Point(float, float); //the constructor 
  void setX(float newX); 
  void setY(float newY); 
  float getX(); 
  float getY();
  void displacement();
  ~Point(); //the destructor 
}; 

#endif
