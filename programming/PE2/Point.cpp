#include "Point.h"
#include <math.h>
#include <iostream>
using namespace std;
/*
Constructor for the origin nothing more nothing less, sets each element in a vector of size n to 0
*/
Point::Point(int n){
    int counter = 0;
    while (counter < n)
    {
        dimension.push_back(0);
        counter++;
    }
}
/*
Takes a vector and sets the dimensions of the point being created to the dimensions given. i.e. {1,2,3,4,5} = x=1, y=2, z=3, ..., etc
*/
Point::Point(vector<int>& maybe){
    dimension = maybe;
}
/*
Given an object and dimension (x,y,z,etc) returns the value of that point
If the location is invalid -1 is returned and handled by main
*/
int Point::getPoint(Point curr, int location){
    if (location <= curr.dimension.size())
    {
        return curr.dimension[location];
    }
    else
    {
        return -1;
    }
    
}
/*
Can change the value of a point at a given location of a given object. If location invalid prints error message
*/
void Point::setPoint(Point &curr, int location, int value){
    if (location <= curr.dimension.size())
    {
        curr.dimension[location] = value;
    }
    else
    {
        cout << "ERROR: Dimension greater than stored in this point." << endl;
    }
}
/*
uses the pythagorean thereom to calculate the shortest distance between 2 given points. i.e. a straight line
my vector wont exceed 100... i dont even know what dimension comes after Z
If the sizes are not equal a negative distance is returned, this should be a clear indicator to the user that something 
is very wrong and not a real distance.
*/
double Point::Distance(Point one, Point two){
    int counter = 0;
    double a[100];
    double c = 0.0;
    if (one.dimension.size() != two.dimension.size())
    {
        return -1;
    }
    else
    {
        while (counter < one.dimension.size())
        {
            a[counter] = one.dimension[counter] - two.dimension[counter];
            counter++;
        }
        for (int i = 0; i < one.dimension.size(); i++)
        {
            c += pow(a[i], 2);
        }
    }

	double dist = sqrt(c);

    return dist;
}
/*
Translation occurs at every point across the vector of points/dimensions of a given point object.
They all change by the same amount.
*/
void Point::Translate(Point &curr, int amount){
    for (int i = 0; i < curr.dimension.size(); i++)
    {
        curr.dimension[i] += amount;
        cout << curr.dimension[i] << endl;
    }
}