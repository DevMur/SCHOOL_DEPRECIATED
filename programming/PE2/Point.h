#ifndef POINT_H
#define POINT_H
#include <vector>
using namespace std;
class Point{
public:
    Point(int n);
    Point(vector<int>& maybe);
    int getPoint(Point curr, int location);
    void setPoint(Point &curr, int location, int value);
    double Distance(Point one, Point two);
    void Translate(Point &curr, int amount);
private:
    vector<int> dimension;
};

#endif