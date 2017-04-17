#include <math.h>
#define _USE_MATH_DEFINES
#include "Triangle.hpp"



Triangle::Triangle() :a_({ 0,0 }), b_({ 0,0 }), c_({ 0,0 })
{
	name_ = "Triangle";
}

Triangle::Triangle(point_t a, point_t b, point_t c, double angle = 0)
{ 
	name_ = "Triangle";
	a_ = a;
	b_ = b;
	c_ = c;
	angle_ = angle;
	updateRecAfterTurn();
}

Triangle::Triangle(const Triangle & obj)
{
	angle_ = obj.angle_;
	name_ = obj.name_;
	rect_  = obj.rect_;
	a_ = obj.a_;
	b_ = obj.b_;
	c_ = obj.c_;
}

Triangle& Triangle::operator=(const Triangle& obj)
{
	if (this != &obj)
	{
		angle_ = obj.angle_;
		name_ = obj.name_;
		rect_ = obj.rect_;
		a_ = obj.a_;
		b_ = obj.b_;
		c_ = obj.c_;
	}
	return *this;
}
void Triangle::setScale(double coef)
{
	point_t temp_a, temp_b, temp_c;
	if (coef>0)
	{
		temp_a.x = rect_.pos.x - a_.x;
		temp_a.y = rect_.pos.y - a_.y;
		temp_b.x = rect_.pos.x - b_.x;
		temp_b.y = rect_.pos.y - b_.y;
		temp_c.x = rect_.pos.x - c_.x;
		temp_c.y = rect_.pos.y - c_.y;
		temp_a.x *= coef;
		temp_a.y *= coef;
		temp_b.x *= coef;
		temp_b.y *= coef;
		temp_c.x *= coef;
		temp_c.y *= coef;
		a_.x = rect_.pos.x + temp_a.x;
		a_.y = rect_.pos.y + temp_a.y;
		b_.x = rect_.pos.x + temp_b.x;
		b_.y = rect_.pos.y + temp_b.y;
		c_.x = rect_.pos.x + temp_c.x;
		c_.y = rect_.pos.y + temp_c.y;
		updateRecAfterTurn();
	}
}

double Triangle::getArea()const 
{
	return (((a_.x-c_.x)*(b_.y-c_.y)-(b_.x-c_.x)*(a_.y-c_.y))/2);
}

rectangle_t Triangle::getFrameRect() const
{
	return rect_;
}

void Triangle::updateRecAfterTurn()
{

}