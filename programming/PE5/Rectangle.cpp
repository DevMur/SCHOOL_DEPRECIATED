//Devin Murray
//I found 7 assertions to pass, I understand bugs
//should be found but I have a photos to show.

#include "Rectangle.h"

Rectangle::Rectangle(Point p1, Point p2) {
    p1_ = p1;
    p2_ = p2;
}

int Rectangle::GetWidth() {
    int width = p2_.x - p1_.x;
    return width;
}

int Rectangle::GetHeight() {
    int height = p2_.y - p1_.y;
    return height;
}

bool Rectangle::Overlaps(Rectangle&  other) {
    if (other.get_p1().x > p2_.x || other.get_p1().y > p2_.y)
    {
        return false;
    }
    if (other.get_p2().x < p1_.x || other.get_p2().y < p1_.y)
    {
        return false;
    }
    return true;
}

int Rectangle::CalculateArea() {
    int area;
    area = GetHeight() * GetWidth();
    return area;
}

void Rectangle::Expand() {
    p2_.x +=1;
    p2_.y +=1;
    p1_.x +=-1;
    p1_.y +=-1;
}

void Rectangle::Shrink() {

    Point t1 = p1_;
    Point t2 = p2_;
    t1.x++;
    t1.y++;
    t2.x--;
    t2.y--;
    if (t1.x > t2.x || t1.y > t2.y)
    {
        return;
    }
    else {
        p1_ = t1;
        p2_ = t2;
    }
}