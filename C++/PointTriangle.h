#ifndef POINTTRIANGLE_H_INCLUDED
#define POINTTRIANGLE_H_INCLUDED

#include <math.h>
using namespace std;

struct Point{
    double x;
    double y;
    void input();
    void output();
    double distanceToPoint(Point b);
    double distanceToOx();
    double distanceToOy();
};

struct Triangle{
    Point A;
    Point B;
    Point C;
    double AB;
    double BC;
    double CA;
    void input();
    void output();
    bool isValidTriangle();
    int TriangleType();
    double perimeter();
    double area();
    Point G();
};

#endif // POINTTRIANGLE_H_INCLUDED
