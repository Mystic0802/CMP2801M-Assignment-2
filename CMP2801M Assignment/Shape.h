#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"

#define _USE_MATH_DEFINES // Must define this to access math constants e.g. M_PI
#include <cmath> // Must include cmath BEFORE iostream!. https://stackoverflow.com/a/58379321
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>

class Shape
{
protected:
	double area;
	double perimeter;
	Point* leftTop;
	std::vector<Point> points;
	std::stringstream* shapePropertyOStream;
public:
	Shape() {
		area = 0;
		perimeter = 0;
		leftTop = new Point();
		std::stringstream ss;
		ss << std::endl;
		shapePropertyOStream = new std::stringstream(ss.str());
	}
	~Shape() {
		delete leftTop;
		delete shapePropertyOStream;
	}
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
	// Calculates the positions of the points that make up the shape and adds them to the points vector.
	virtual void calculatePoints() = 0;
	// Calls all calculate functions. Should be called after any change to the leftTop point.
	void recalculateShape() {
		calculateArea();
		calculatePerimeter();
		calculatePoints();
		updateShapePropertyOStream();
	}
	virtual void updateShapePropertyOStream() = 0;
	// Declare the operator<< overload function as a friend of the Shape class.
	friend std::ostream& operator<<(std::ostream& os, const Shape& shape);
};

// Overload the << operator to print the shape's points, area & perimeter.
std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
	os << shape.shapePropertyOStream->str();
	os << "Points[";
	for (Point p : shape.points)
	{
		os << "(" << p.getX() << "," << p.getY() << ")";
	}
	os << "]\n";
	os << std::fixed << "Area=" << std::setprecision(1) << shape.area << ", Perimeter=" << shape.perimeter << std::endl;
	return os;
}

#endif // !SHAPE_H