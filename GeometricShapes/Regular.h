#pragma once
#include "Shape.h"
#include "Point.h"

class Regular : public Shape {
	friend std::ostream& operator<<(std::ostream& out, const Regular& obj);
public:
	Regular(const Point center, const Point radiusDescribed, const Point radiusInscribed);
	Regular(const Regular& other);
	Regular(const double centerX, const double centerY, const double pointDescribedX, const double pointDescribedY, const double pointInscribedX, const double pointInscribedY);

	~Regular();

	double getArea() const override;
	FrameRectangle getFrameRectangle() const override;
	void move(double dx, double dy) override;
	void move(const Point& center) override;
	//void scale(double coefficient) override;
	Regular* clone() const override;
	std::string getName() const override;

	double getRadiusDescribed() const;
	double getRadiusInscribed() const;

	bool isRightAngledTriangle() const;
	double getCut(Point a, Point b) const;

private:
	Point center_;
	Point pointOnRadiusDescribed_;
	Point pointOnRadiusInscribed_;
};

