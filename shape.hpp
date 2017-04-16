#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"
#include <string>

class Shape
{
public:
	virtual double getArea() const =0;
	virtual rectangle_t getFrameRect() const =0;
	virtual void updateRecAfterTurn() =0;
	virtual void setScale(double) = 0;
	void move(point_t temp);
	void move(double x, double y);
	void setAngle(double temp);
	std::string getName()const;
	point_t getPos()const;
	double getAngle() const;
	void operator+=(point_t right_obj);
	Shape();
protected:
	std::string name_;
	rectangle_t rect_;
	double angle_;
};
#endif


