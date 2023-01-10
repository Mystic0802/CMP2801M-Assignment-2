#ifndef POINT_H
#define POINT_H

class Point
{
private:
	int x;
	int y;
public:
	// Default contructor
	Point() {
		x = 0;
		y = 0;
	}

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	
	// Getters and setters
	int getX() const {
		return x;
	}
	void setX(int x) {
		this->x = x;
	}	
	int getY() const {
		return y;
	}
	void setY(int y) {
		this->y = y;
	}
	void setXY(int x, int y) {
		this->x = x;
		this->y = y;
	}
};


#endif // !POINT_H

