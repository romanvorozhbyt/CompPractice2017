#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;
class Point2D
{
    public:
        Point2D(double x, double y);
        string toString();
        double distanceTo(Point2D that);
    private:  
        double x;
        double y;
};

Point2D::Point2D(double x, double y)
{
    this -> x = x;
    this -> y = y;
}

string Point2D::toString()
{
    ostringstream out;
    out << "x = " << setprecision(7) << x << ", y = " << setprecision(7) << y;
    return out.str();
}

double Point2D::distanceTo(Point2D that)
{
    return sqrt(pow((x - that.x), 2) + pow((y - that.y), 2));
}

int main()
{
    double x1, y1, x2, y2;
    cout << "Input first coordinates: ";
    cin >> x1 >> y1;
    cout << "Input second coordinates: ";
    cin >> x2 >> y2;
    Point2D p1(x1, y1), p2(x2, y2);
    cout << "The first coordinates are: " + p1.toString() << endl;
    cout << "The second coordinates are: " + p2.toString() << endl;
    cout << "Distance between points is " << p2.distanceTo(p1);
    return 0;
}