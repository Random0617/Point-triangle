#include <iostream>
#include "PointTriangle.h"
using namespace std;

int main()
{
    Point A;
    Point B;
    cout << "Input point A: " << endl;
    A.input();
    cout << "Input point B: " << endl;
    B.input();
    cout << "Output point A: " << endl;
    A.output();
    cout << "Output point B: " << endl;
    B.output();
    cout << "Distance from point A to point B: " << A.distanceToPoint(B) << endl;
    cout << "Distance from point A to Ox: " << A.distanceToOx() << endl;
    cout << "Distance from point A to Oy: " << A.distanceToOy() << endl;
    cout << "Distance from point B to Ox: " << B.distanceToOx() << endl;
    cout << "Distance from point B to Oy: " << B.distanceToOy() << endl;
    Triangle ABC;
    cout << "Input triangle ABC: " << endl;
    ABC.input();
    cout << "Output triangle ABC: " << endl;
    ABC.output();
    cout << "Triangle type: ";
    if (ABC.TriangleType() == -1)
        cout << "This is not a valid triangle." << endl;
    else if (ABC.TriangleType() == 0)
        cout << "normal triangle" << endl;
    else if (ABC.TriangleType() == 1)
        cout << "isosceles triangle" << endl;
    else if (ABC.TriangleType() == 2)
        cout << "right triangle" << endl;
    else if (ABC.TriangleType() == 3)
        cout << "isosceles & right triangle" << endl;
    else
        cout << "equilateral" << endl;
    cout << "Perimeter: " << ABC.perimeter() << endl;
    cout << "Area: " << ABC.area() << endl;
    cout << "Center G: (" << ABC.G().x << ", " << ABC.G().y << ")" << endl;
    return 0;
}
