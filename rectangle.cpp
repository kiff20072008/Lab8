#include "rectangle.hpp"


void Rectangle::setScale(double coef) 
{ 
	if (coef>0 )
	{ 
		width_ *= coef;
		height_ *= coef;
		updateRecAfterTurn();
	} 
}

void Rectangle::updateRecAfterTurn()
{
	rect_.height = height_*cos(angle_) + width_*sin(angle_);
	rect_.width = width_*cos(angle_) + height_*sin(angle_);
}

Rectangle::Rectangle():height_(0),width_(0)
{
	name_ = "Rectangle";
	rect_.height = height_ ;
	rect_.width = width_;
}

Rectangle::Rectangle(point_t p , double x , double y,double angle = 0 )
{
	name_ = "Rectangle";
	height_ = x;
	width_ = y;
	rect_.pos = p;
	angle_ = angle;
	updateRecAfterTurn();
}

Rectangle& Rectangle::operator=(const Rectangle& obj)
{
	if (this != &obj)
	{
		angle_ = obj.angle_;
		rect_ = obj.rect_;
		name_ = obj.name_;
		height_ = obj.height_;
		width_ = obj.width_;

	}
	return *this;
}


Rectangle::Rectangle(const Rectangle& obj)
{
	angle_ = obj.angle_;
	rect_ = obj.rect_;
	name_ = obj.name_;
	height_ = obj.height_;
	width_ = obj.width_;
}

double Rectangle::getArea() const 
{
	return width_*height_;
}

rectangle_t Rectangle::getFrameRect() const
{
	return rect_;
}