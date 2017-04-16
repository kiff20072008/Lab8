#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle : public Shape
{
public:
	Circle();
	Circle(point_t p, double raad) ;
	Circle(const Circle& obj);
	Circle& operator=(const Circle& obj);
	rectangle_t getFrameRect() const;
	double getArea() const;
	void setScale(double coef);
	double  getRad() const;
private:
	double r_;
};
#endif