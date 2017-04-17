#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
	Triangle();
	Triangle(point_t,point_t,point_t,double);
	Triangle(const Triangle & obj);

	Triangle& operator=(const Triangle& obj);

	void setScale(double coef);
	double getArea()const;
	rectangle_t getFrameRect() const;
	void updateRecAfterTurn();
private:
	point_t a_, b_, c_;
};
#endif