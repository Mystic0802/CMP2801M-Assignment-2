#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include "Movable.h"

class Square : public Shape, public Movable
{
private:
	int edge;
public:
	// Default constructor:
	Square() {
		edge = 0;
		recalculateShape();
	}
	
	Square(int x, int y, int e) {
		leftTop->setXY(x, y);
		edge = e;
		recalculateShape();
	}

	// Square implementation of Shape::calculateArea()
	virtual void calculateArea() override {
		area = edge * edge;
	}

	// Square implementation of Shape::calculatePerimeter()
	virtual void calculatePerimeter() override {
		perimeter = 4 * edge;
	}

	// Square implementation of Shape::calculatePoints()
	// Calculates the 4 points of the square. Stores in order: top left, top right, bottom right, bottom left.
	virtual void calculatePoints() override {
		int xPlusEdge = leftTop->getX() + edge;
		int yPlusEdge = leftTop->getY() + edge;

		points.push_back(*leftTop); // Top left
		points.push_back(Point(xPlusEdge, leftTop->getY())); // Top right
		points.push_back(Point(xPlusEdge, yPlusEdge)); // Bottom right
		points.push_back(Point(leftTop->getX(), yPlusEdge)); // Bottom left
	}

	// Square implentation of Movable::move()
	virtual void move(int newX, int newY) override {
		leftTop->setXY(newX, newY);
		recalculateShape();
	}

	// Square implementation of Movable::scale()
	virtual void scale(int xScale, int yScale) override {
		edge *= xScale;
	}

	// Declare the operator<< overload function as a friend of the Circle class
	friend std::ostream& operator<<(std::ostream& os, const Square& s);
};

// Overload the << operator to print the square's exclusive details
std::ostream& operator<<(std::ostream& os, const Square& s) {
	os << "Square[e=" << s.edge << "]\n";
	Shape* shape = (Shape*)&s;
	os << *shape;
	shape = nullptr;
 	return os;
}

#endif // !SQUARE_H
