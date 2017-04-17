#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
	Triangle();
	Triangle(point_t,point_t,point_t,double=0);
	Triangle(const Triangle & obj);
	virtual void move(point_t) override;
	virtual void move(double, double) override;

	Triangle& operator=(const Triangle& obj);

	void setScale(double coef);
	double getArea()const;
	rectangle_t getFrameRect() const;
	point_t getFindCenterTriangle() const;
	void updateRecAfterTurn();
private:
	void updateRec();
	double minMax(double, double, double) const;
	point_t a_, b_, c_;
};
#endif