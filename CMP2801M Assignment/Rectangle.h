#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Movable.h"

class Rectangle : public Shape, public Movable
{
private:
	int width;
	int height;
public:
	// Default constructor
	Rectangle() {
		width = 0;
		height = 0;
		recalculateShape();
		updateShapePropertyOStream();
	}
	
	Rectangle(int x, int y, int h, int w) {
		leftTop->setXY(x, y);
		height = h;
		width = w;
		recalculateShape();
		updateShapePropertyOStream();
	}

	virtual void updateShapePropertyOStream() override
	{
		std::stringstream ss;
		ss << "Rectangle[h=" << height << ",w=" << width << "]" << std::endl;
		*shapePropertyOStream = std::stringstream(ss.str());
	}
	
	// Rectangle implementation of Shape::calculateArea()
	virtual void calculateArea() override {
		area = width * height;
	}
	
	// Rectangle implementation of Shape::calculatePerimeter()
	virtual void calculatePerimeter() override {
		perimeter = 2 * (width + height);
	}
	
	// Rectangle implementation of Shape::calculatePoints()
	// Calculates the 4 points of the rectangle. Stores in order: top left, top right, bottom right, bottom left.
	virtual void calculatePoints() override {
		points.clear();
		int xPlusWidth = leftTop->getX() + width;
		int yPlusHeight = leftTop->getY() + height;
		
		points.push_back(*leftTop); // Top left
		points.push_back(Point(xPlusWidth, leftTop->getY())); // Top right
		points.push_back(Point(xPlusWidth, yPlusHeight)); // Bottom right
		points.push_back(Point(leftTop->getX(), yPlusHeight)); // Bottom left
	}
	
	// Rectangle implentation of Movable::move()
	virtual void move(int newX, int newY) override {
		leftTop->setXY(newX, newY);
		recalculateShape();
	}
	
	// Rectangle implementation of Movable::scale()
	virtual void scale(int xScale, int yScale) override {
		width *= xScale;
		height *= yScale;
		recalculateShape();
	}
};


#endif // !RECTANGLE_H
