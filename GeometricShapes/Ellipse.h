#pragma once
#include "Shape.h"
#include "Point.h"
#include "FrameRectangle.h"

class Ellipse : public Shape {
	friend std::ostream& operator<<(std::ostream& out, const Ellipse& obj);
public:
	Ellipse(const Point center, const double radius_x, const double radius_y);
	Ellipse(const Ellipse& other);
	Ellipse(const double centerX, const double centerY, const double radius_x, const double radius_y);

	~Ellipse();

	double getArea() const override;
	FrameRectangle getFrameRectangle() const override;
	void move(double dx, double dy) override;
	void move(const Point& center) override;
	void scale(double coefficient) override;
	Shape* clone() const override;
	std::string getName() const override;

private:
	Point center_;
	double radiusX_;
	double radiusY_;
};

