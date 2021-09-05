#ifndef POINT_H
#define POINT_H

class Point{
private:
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    int getX(Point curr){return curr.x;}
    int getY(Point curr){return curr.y;}
    void setX(Point curr, int newx);
    void setY(Point curr, int newy);
    double Distance(Point one, Point two);
    void Translate(Point curr, int amount);
};

#endif