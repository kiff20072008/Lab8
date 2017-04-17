#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle : public Shape
{
public:
	Rectangle();
	Rectangle(point_t,double,double,double=0);
	Rectangle(const Rectangle&);

	Rectangle& operator=(const Rectangle&);

	void setScale(double);
	double getArea() const;
	rectangle_t getFrameRect() const;
	void updateRecAfterTurn();
private:
	double width_, height_;
};
#endif