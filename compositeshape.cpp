#include "Compositeshape.hpp"

int CompositeShape::getLength() 
{ 
	return length_;
}

Shape* CompositeShape::operator[](int num)
{
	return obj_[num];
}

CompositeShape::CompositeShape() :length_(0)
{
}

CompositeShape::CompositeShape(Shape &obj1) :length_(1)
{
	obj_ = new Shape*[length_];
	obj_[length_-1] = &obj1;
}

void CompositeShape::addShape(Shape &obj1)
{
	Shape **temp = new Shape*[++length_];
	if (!temp)
	{
		return;
	}
	for (int i = 0; i < length_-1; ++i)
	{
		temp[i] = obj_[i];
	}
	temp[length_ - 1] = &obj1;
	obj_= temp;
}





bool check_if_per(rectangle_t obj1, rectangle_t obj2)
{
	if (obj1.pos.x > (obj2.pos.x + obj2.width) || (obj1.pos.x + obj1.width) < obj2.pos.x)
		return false;
	if (obj1.pos.y > (obj2.pos.y + obj2.height) || (obj1.pos.y + obj1.height) < obj1.pos.y)
		return false;
	return true;
}