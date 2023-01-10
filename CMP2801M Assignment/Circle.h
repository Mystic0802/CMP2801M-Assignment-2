#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Movable.h"

class Circle : public Shape, public Movable
{
private:
	int radius;
public:
	// Default constructor
	Circle() {
		radius = 0;
		recalculateShape();
	}
	// Constructor
	Circle(int x, int y, int r) {
		leftTop->setXY(x, y);
		radius = r;
		recalculateShape();
	}
	// Circle implementation of Shape::calculateArea()
	virtual void calculateArea() override {
		area = M_PI * (radius * radius);
	}
	// Circle implementation of Shape::calculatePerimeter()
	virtual void calculatePerimeter() override {
		perimeter = 2 * M_PI * radius;
	}
	// Circle implementation of Shape::calculatePoints()
	// Calculates the 2 points of the circle. Stores in order: top left, bottom right.
	virtual void calculatePoints() override {
		int xPlusRadius = leftTop->getX() + radius;
		int yPlusRadius = leftTop->getY() + radius;

		points.push_back(*leftTop); // Top left
		points.push_back(Point(xPlusRadius, yPlusRadius)); // Bottom right
	}
	// Circle implentation of Movable::move()
	virtual void move(int newX, int newY) override {
		leftTop->setXY(newX, newY);
		recalculateShape();
	}
	// Circle implementation of Movable::scale()
	virtual void scale(int xScale, int yScale) override {
		radius *= xScale;
	}

	// Declare the operator<< overload function as a friend of the Circle class
	friend std::ostream& operator<<(std::ostream& os, const Circle& c);
};

// Overload the << operator to print the circle's exclusive details
std::ostream& operator<<(std::ostream& os, const Circle& c)
{
	os << "Rectangle[r=" << c.radius << "]\n";
	Shape* shape = (Shape*)&c;
	os << *shape;
	shape = nullptr;
	return os;
}

#endif // !CIRCLE_H