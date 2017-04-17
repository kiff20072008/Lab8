#include <math.h>
#define _USE_MATH_DEFINES
#include "circle.hpp"

Circle::Circle() :r_(0)
{
	name_= "Circle";
	rect_.height = rect_.width = 2 * r_;
}

Circle::Circle(point_t p , double raad = 0)
{
	if (raad < 0)
	{
		r_ = 0;
	}else {
		r_ = raad;
	}
	rect_.pos  = p;
	name_ = "Circle";
	rect_.height = rect_.width = 2 * r_;
}


Circle::Circle(const Circle& obj)
{
	r_ = obj.r_;
	name_ =obj.name_;
	rect_ = obj.rect_;
}

Circle& Circle::operator=(const Circle& obj)
{
	if (this != &obj)
	{
		r_ = obj.r_;
		name_ = obj.name_;
		rect_ = obj.rect_;
	}
	return *this;
}

rectangle_t Circle::getFrameRect() const
{
	return rect_;
}

double Circle::getArea() const
{
	return M_PI*r_*r_;
}

void Circle::setScale(double coef)
{
	if (coef > 0)
	{
		r_ *= coef;
		rect_.height = rect_.width = 2 * r_;

	}
}

double  Circle::getRad() const
{
	return r_;
}