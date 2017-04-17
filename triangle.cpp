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

void Triangle::move(point_t new_point)
{
	point_t temp;
	temp.x = new_point.x - rect_.pos.x;
	temp.y = new_point.y - rect_.pos.y;
	a_.x += temp.x;
	b_.x += temp.x;
	c_.x += temp.x;
	a_.y += temp.y;
	b_.y += temp.y;
	c_.y += temp.y;

	rect_.pos = new_point;

}

void Triangle::move(double x, double y)
{
	a_.x += x;
	b_.x += x;
	c_.x += x;
	a_.y += y;
	b_.y += y;
	c_.y += y;
	rect_.pos = getFindCenterTriangle();
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
		updateRec();
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

point_t Triangle::getFindCenterTriangle() const
{
	return (point_t{ (a_.x + b_.x + c_.x) / 3,(a_.y + b_.y + c_.y) / 3 });
}

void Triangle::updateRecAfterTurn()
{
	point_t temp_a, temp_b, temp_c;

	a_.x -= rect_.pos.x;
	a_.y -= rect_.pos.y;
	b_.x -= rect_.pos.x;
	b_.y -= rect_.pos.y;
	c_.x -= rect_.pos.x;
	c_.y -= rect_.pos.y;

	temp_a.x = a_.x*cos(angle_) - a_.y*sin(angle_);
	temp_a.y = a_.x*sin(angle_) + a_.y*cos(angle_);
	temp_b.x = b_.x*cos(angle_) - b_.y*sin(angle_);
	temp_b.y = b_.x*sin(angle_) + b_.y*cos(angle_);
	temp_c.x = c_.x*cos(angle_) - c_.y*sin(angle_);
	temp_c.y = c_.x*sin(angle_) + c_.y*cos(angle_);

	a_.x = rect_.pos.x + temp_a.x;
	a_.y = rect_.pos.y + temp_a.y;
	b_.x = rect_.pos.x + temp_b.x;
	b_.y = rect_.pos.y + temp_b.y;
	c_.x = rect_.pos.x + temp_c.x;
	c_.y = rect_.pos.y + temp_c.y;

	updateRec();
	
}

void Triangle::updateRec()
{
	rect_.pos = getFindCenterTriangle();

	rect_.height = minMax(a_.y, b_.y, c_.y);
	rect_.width = minMax(a_.x, b_.x, c_.x);
}

double Triangle::minMax(double first_, double second_, double third_) const
{
	double temp_min=first_, temp_max=third_;

	if (second_ < temp_min)
	{
		temp_min = second_;
	}
	if (third_ < temp_min)
	{
		temp_min = third_;
	}
	if (first_ > temp_max)
	{
		temp_max = first_;
	}
	if (second_ > temp_max)
	{
		temp_max = second_;
	}
	return (temp_max - temp_min);
}
