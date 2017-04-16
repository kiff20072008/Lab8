#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include "shape.hpp"

#define MAX_SIZE 12


class CompositeShape
{
public:
	CompositeShape();
	CompositeShape(Shape &obj1);
	void addShape(Shape &obj1);
	int getLength();
	Shape* operator [](int num);


private:
	
	int length_;
	Shape **obj_;
};

bool check_if_per(rectangle_t obj1, rectangle_t obj2);
#endif