#include <math.h>
#define _USE_MATH_DEFINES
#include "shape.hpp"


void Shape::updateRecAfterTurn()
{
}

void Shape::move(point_t temp)
{
	rect_.pos= temp;
};

void Shape::move(double x, double y)
{
	rect_.pos.x += x;
	rect_.pos.y += y;
};

void Shape::setAngle(double temp)
{
	if (temp > -1 && temp < 361)
	{
		angle_ = temp*M_PI / 180;
		updateRecAfterTurn();
	}
};

void Shape::operator+=(point_t right_obj)
{
	move(right_obj.x, right_obj.y);
};

std::string Shape::getName() const
{
	return name_;
}

point_t Shape::getPos() const
{
	return rect_.pos;
}

double Shape::getAngle()const
{
return (angle_*180/M_PI);
}

Shape::Shape() :rect_({ { 0,0 },0,0 }), angle_(0)
{
}
