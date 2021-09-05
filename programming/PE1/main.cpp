#include <iostream>
#include "Point.cpp"
using namespace std;

int main(){
    //create some points, two edges from each point makes a triangle
    Point first = Point();
    Point second = Point(-3, 3);
    Point third = Point(3, 3);

    Point abuse = Point(); //for methods so.

    cout << "Point 1: (" << first.getX(first) << ", " << first.getY(first) << ")" << endl;
    cout << "Point 2: (" << second.getX(second) << ", " << second.getY(second) << ")" << endl;
    cout << "Point 3: (" << third.getX(third) << ", " << third.getY(third) << ")" << endl;
    cout << "Distance between 1 and 2: " << abuse.Distance(first, second) << endl;
    cout << "Distance between 1 and 3: " << abuse.Distance(first, third) << endl;
    cout << "Distance between 2 and 3: " << abuse.Distance(second, third) << endl;
    cout << endl << endl;
    cout << "Translating point 1 by a positive amount..." << endl;
    abuse.Translate(first, 1);
    cout << "New location: (" << first.getX(first) << ", " << first.getY(first) << ") " << endl;
    cout << "Distance from 1 -> 2: " << abuse.Distance(first, second) << endl; 
    cout << "Distance from 1 -> 3: " << abuse.Distance(first, third) << endl; 
    cout << "Translating point 1 by a negative amount..." << endl;
    abuse.Translate(first, -20);
    cout << "New location: (" << first.getX(first) << ", " << first.getY(first) << ") " << endl;
    cout << "Distance from 1 -> 2: " << abuse.Distance(first, second) << endl; 
    cout << "Distance from 1 -> 3: " << abuse.Distance(first, third) << endl; 

    return 0;
}