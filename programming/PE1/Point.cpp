#include <iostream>
#include "Point.h"
#include <math.h>
using namespace std;
/*
Constructor for the origin nothing more nothing less
*/
Point::Point(){
    x = 0;
    y = 0;
}
/*
takes the x and y coordinates and makes a pretty basic coordinate pair
*/
Point::Point(int x1, int y1){
    x = x1;
    y = y1;
}
/*
changes only the x location
*/
void Point::setX(Point curr, int newx){
    curr.x = newx;
}
/*
changes only the y location/value
*/
void Point::setY(Point curr, int newy){
    curr.y = newy;
}
/*
uses the pythagorean thereom to calculate the shortest distance between 2 given points. i.e. a straight line
*/
double Point::Distance(Point one, Point two){
    double a = one.x - two.x; //use pythagorean thereom to find the straight line distance
	double b = one.y - two.y;
	double c = pow(a, 2) + pow(b, 2); 

	double dist = sqrt(c);

    return dist;
}
/*
My translation is vertical, it only moves the given objects y coordinate by the given amount.
*/
void Point::Translate(Point curr, int amount){
    curr.y += amount;
}