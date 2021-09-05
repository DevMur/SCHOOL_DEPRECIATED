#include <iostream>
#include "Point.cpp"
using namespace std;

int main(){
    //create some points, two edges from each point makes a triangle
    vector<int> test1{1, 2, 3, 4};
    vector<int> test2{6, 7, 8, 9};
    vector<int> test3{2, 4, 6, 8};
    vector<int> test4{1, 3, 5, 7, 9};
    Point first = Point(test1.size());
    Point second = Point(test1);
    Point third = Point(test3);
    Point fourth = Point(test4);

    Point abuse = Point(0); //for methods hence name.

    cout << "Point 1: (" << first.getPoint(first, 0) << ", " << first.getPoint(first, 1) << 
    ", " << first.getPoint(first, 2) << ", " << first.getPoint(first, 3) << ")" << endl;
    cout << "Point 2: (" << second.getPoint(second, 0) << ", " << second.getPoint(second, 1) << 
    ", " << second.getPoint(second, 2) << ", " << second.getPoint(second, 3) << ")" << endl;
    cout << "Point 3: (" << third.getPoint(third, 0) << ", " << third.getPoint(third, 1) << 
    ", " << third.getPoint(third, 2) << ", " << third.getPoint(third, 3) << ")" << endl;
    cout << "Distance between 1 and 2: " << abuse.Distance(first, second) << endl;
    cout << "Distance between 1 and 3: " << abuse.Distance(first, third) << endl;
    cout << "Distance between 2 and 3: " << abuse.Distance(second, third) << endl;

    cout << endl << endl; //lil formatting jawn

    cout << "Translating point 1 by a positive amount..." << endl;

    abuse.Translate(first, 10);

    cout << "New location: (" << first.getPoint(first, 0) << ", " << first.getPoint(first, 1) << 
    ", " << first.getPoint(first, 2) << ", " << first.getPoint(first, 3) << ")" << endl;
    cout << "Distance from 1 -> 2: " << abuse.Distance(first, second) << endl; 
    cout << "Distance from 1 -> 3: " << abuse.Distance(first, third) << endl; 
    cout << "Translating point 1 by a negative amount..." << endl;

    cout << endl;
    abuse.Translate(first, -20);
    cout << endl;

    cout << "New location: (" << first.getPoint(first, 0) << ", " << first.getPoint(first, 1) << 
    ", " << first.getPoint(first, 2)  << ", " << first.getPoint(first, 3) << ")" << endl;
    cout << "Distance from 1 -> 2: " << abuse.Distance(first, second) << endl; 
    cout << "Distance from 1 -> 3: " << abuse.Distance(first, third) << endl; 

    //handling the case where the dimensions are different.

    cout << endl << endl;
    cout << "Point 3: (" << third.getPoint(third, 0) << ", " << third.getPoint(third, 1) << 
    ", " << third.getPoint(third, 2) << ", " << third.getPoint(third, 3) << ")" << endl;
    cout << "Point 4: (" << fourth.getPoint(fourth, 0) << ", " << fourth.getPoint(fourth, 1) << 
    ", " << fourth.getPoint(fourth, 2) << ", " << fourth.getPoint(fourth, 3) << ")" << endl;
    cout << "These clearly have different dimensions, I'm only demonstrating one form of error handling as none was specified." << endl;
    cout << "Distance from 3 -> 4: " << abuse.Distance(third, fourth) << endl; 

    return 0;
}