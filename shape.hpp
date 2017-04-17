#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "base-types.hpp"

class Shape
{
public:
	virtual double getArea() const =0;
	virtual rectangle_t getFrameRect() const =0;
	virtual void updateRecAfterTurn();
	virtual void setScale(double) = 0;
	virtual void move(point_t);
	virtual void move(double, double);
	void setAngle(double);
	std::string getName()const;
	point_t getPos()const;
	double getAngle() const;
	void operator+=(point_t);
	Shape();
protected:
	std::string name_;
	rectangle_t rect_;
	double angle_;
};
#endif


