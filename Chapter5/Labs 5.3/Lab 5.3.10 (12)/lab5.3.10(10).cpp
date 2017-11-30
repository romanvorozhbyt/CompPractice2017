#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;
class Point2D {
public:
	Point2D(double x, double y)
	{
		this->x = x;
		this->y = y;
	};
	string toString();
	double getX() { return x; }
	double getY() { return y; }
private:
	double x;
	double y;
};

string Point2D::toString()
{
	ostringstream out;
	out << "x = " << setprecision(7) << x << ", y = " << setprecision(7) << y;
	return out.str();
};

class Line2D {
public:
	Line2D(double slope, double y_intercept)
	{
		this->slope = slope;
		this->y_intercept = y_intercept;
	}
	Line2D(Point2D pointA, Point2D pointB);
	string toString();
	bool contains(Point2D point);
private:
	bool compareDouble(double a, double b);
	double slope;
	double y_intercept;
	double y = 0;
};

Line2D::Line2D(Point2D pointA, Point2D pointB)
{
	if (pointA.getX() == pointB.getX())
	{
		slope = 0;
		y_intercept = pointB.getX();
	}
	else if (pointA.getY() == pointB.getY())
	{
		slope = 0;
		y_intercept = 0;
		y = pointB.getY();
	}
	else
	{
		slope = (pointA.getY() - pointB.getY()) / (pointA.getX() - pointB.getX());
		y_intercept = (pointA.getX() * pointB.getY() - pointA.getY() * pointB.getX()) / (pointA.getX() - pointB.getX());
	}
}

string Line2D::toString()
{
	ostringstream out;
	if (slope == 0 && y_intercept != 0)
		out << "x = " << setprecision(7) << y_intercept;
	else if (slope != 0 && y_intercept == 0)
		out << "y = " << setprecision(7) << slope << "x";
	else if (slope == 0 && y_intercept == 0)
		out << "y = " << setprecision(7) << y;
	else
		out << "y = " << setprecision(7) << slope << "x + " << setprecision(7) << y_intercept;
	return out.str();
}

bool Line2D::contains(Point2D point)
{
	if (slope == 0)
	{
		if(y_intercept == 0)
			return compareDouble(point.getY(), y);
		return compareDouble(point.getX(), y_intercept);
	}
	return  compareDouble(point.getX() * slope + y_intercept, point.getY());
}

bool Line2D::compareDouble(double a, double b)
{
	return fabs(a - b) < DBL_EPSILON;
}

int main()
{
	double x1, y1, x2, y2, x3, y3;
	cout << "Input first coordinates(for constructing line): ";
	cin >> x1 >> y1;
	cout << "Input second coordinates(for constructing line): ";
	cin >> x2 >> y2;
	cout << "Input the point's coordinates: ";
	cin >> x3 >> y3;
	Point2D p1(x1, y1), p2(x2, y2), p3(x3, y3);
	Line2D l1(p1, p2);
	cout << l1.toString() << endl;
	string result = (l1.contains(p3)) ? "collinear" : "not collinear";
	cout << result << endl;
	return 0;
}