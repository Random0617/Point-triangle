#include <iostream>
#include "PointTriangle.h"
#include <math.h>
using namespace std;

void Point::input(){
    cout << "INPUT X AND Y COORDINATES OF A POINT" << endl;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
}
void Point::output(){
    cout << "OUTPUT X AND Y COORDINATES OF A POINT" << endl;
    cout << "x = " << x << "; y = " << y << endl;
}
double Point::distanceToPoint(Point b){
    return sqrt((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y));
}
double Point::distanceToOx(){
    return y;
}
double Point::distanceToOy(){
    return x;
}

void Triangle::input(){
    cout << "INPUT X AND Y COORDINATES FOR 3 POINTS OF THE TRIANGLE" << endl;
    cout << "Input point A: " << endl;
    A.input();
    cout << "Input point B: " << endl;
    B.input();
    cout << "Input point C: " << endl;
    C.input();
    AB = A.distanceToPoint(B);
    BC = B.distanceToPoint(C);
    CA = C.distanceToPoint(A);
}
void Triangle::output(){
    cout << "OUTPUT X AND Y COORDINATES FOR 3 POINTS OF THE TRIANGLE" << endl;
    cout << "Output point A: " << endl;
    A.output();
    cout << "Output point B: " << endl;
    B.output();
    cout << "Output point C: " << endl;
    C.output();
}
bool Triangle::isValidTriangle(){
    if (A.x <= 0 || A.y <= 0 || B.x <= 0 || B.y <= 0 || C.x <= 0 || C.y <=0)
        return false;
    if ((A.x == B.x && B.x == C.x) || (A.y == B.y && B.y == C.y))
        return false;
    if (AB + BC > CA && BC + CA > AB && CA + AB > BC)
        return true;
    else
        return false;
}
int Triangle::TriangleType(){
    //0: no special features, 1: isosceles, 2: right, 3: isosceles & right, 4: equilateral
    if (!isValidTriangle())
        return -1;
    bool isosceles = false, right = false, equilateral = false;
    if (AB == BC || BC == CA)
        isosceles = true;
    if (AB == BC && BC == CA)
        equilateral = true;
    if (AB * AB + BC * BC - CA * CA == 0 ||
        BC * BC + CA * CA - AB * AB == 0 ||
        CA * CA + AB * AB - BC * BC == 0)
        right = true;
    if (!isosceles && !right)
        return 0;
    else if (isosceles && !right && !equilateral)
        return 1;
    else if (!isosceles && right && !equilateral)
        return 2;
    else if (isosceles && right && !equilateral)
        return 3;
    else
        return 4;
}
double Triangle::perimeter(){
    if (!isValidTriangle())
        return 0;
    return AB + BC + CA;
}
double Triangle::area(){
    if (!isValidTriangle())
        return 0;
    double p = perimeter() / 2;
    double result = sqrt(p * (p - AB) * (p - BC) * (p - CA));
    return result;
}
Point Triangle::G(){
    Point center;
    center.x = (A.x + B.x + C.x) / 3;
    center.y = (A.y + B.y + C.y) / 3;
    return center;
}
