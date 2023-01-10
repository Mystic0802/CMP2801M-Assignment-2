#ifndef MOVABLE_H
#define MOVABLE_H

class Movable
{
public:
	virtual void move(int newX, int newY) = 0;
	virtual void scale(int xScaleFactor, int yScaleFactor) = 0;
};

#endif // !MOVABLE_H

