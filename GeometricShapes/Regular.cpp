#include "Regular.h"
#include <cmath>
#include <iostream>
#include <iomanip>

Regular::Regular() {
	Point zero_point;
	center_ = zero_point;
	pointOnRadiusDescribed_ = zero_point;
	pointOnRadiusInscribed_ = zero_point;
}

Regular::Regular(const Point center, const Point pointDescribed, const Point pointInscribed) {
	center_ = center;
	pointOnRadiusDescribed_ = pointDescribed;
	pointOnRadiusInscribed_ = pointInscribed;
}

Regular::Regular(const Regular& other) {
	center_ = other.center_;
	pointOnRadiusDescribed_ = other.pointOnRadiusDescribed_;
	pointOnRadiusInscribed_ = other.pointOnRadiusInscribed_;
}

Regular::Regular(const double centerX, const double centerY, const double pointDescribedX, const double pointDescribedY, const double pointInscribedX, const double pointInscribedY) {
	Point center(centerX, centerY);
	Point pointDescribed(pointDescribedX, pointDescribedY);
	Point pointInscribed(pointInscribedX, pointInscribedY);
	center_ = center;
	pointOnRadiusDescribed_ = pointDescribed;
	pointOnRadiusInscribed_ = pointInscribed;
}

Regular::~Regular() {
}

double Regular::getArea() const {
	double RadiusDescribed = getRadiusDescribed();
	double RadiusInscribed = getRadiusInscribed();
	unsigned int numberSides = round(3.1415926535 / (acos(getRadiusInscribed() / RadiusDescribed)));
	if (numberSides == 0) {
		return 0;
	}
	double square = numberSides * RadiusDescribed * RadiusDescribed * sin(2*3.1415926535 / numberSides) / 2;
	return square;
}

FrameRectangle Regular::getFrameRectangle() const {
	unsigned int numberSides = round(3.1415926535 / (acos(getRadiusInscribed() / getRadiusDescribed())));

	double alpha = 2 * acos(getRadiusInscribed() / getRadiusDescribed());
	double zeroAngle = acos((pointOnRadiusDescribed_.getX() - center_.getX()) / getRadiusDescribed());
	double angle = zeroAngle;
	double a = getRadiusDescribed();
	double b = getRadiusInscribed();

	Point lowerLeft(pointOnRadiusDescribed_);
	Point upperRight(lowerLeft);
	Point temp;
	for (int i = 0; i < numberSides - 1; i++) {
		angle += alpha;
		temp.setX(cos(angle) * getRadiusDescribed() + center_.getX());
		temp.setY(sin(-angle) * getRadiusDescribed() + center_.getY());

		if (temp.getX() < lowerLeft.getX()) {
			lowerLeft.setX(temp.getX());
		}
		else if (temp.getX() > upperRight.getX()) {
			upperRight.setX(temp.getX());
		}
		if (temp.getY() < lowerLeft.getY()) {
			lowerLeft.setY(temp.getY());
		}
		else if (temp.getY() > upperRight.getY()) {
			upperRight.setY(temp.getY());
		}
	}
	FrameRectangle frame(lowerLeft, upperRight);
	return frame;
}

void Regular::move(double dx, double dy) {
	center_.setX(center_.getX() + dx);
	center_.setY(center_.getY() + dy);

	pointOnRadiusDescribed_.setX(pointOnRadiusDescribed_.getX() + dx);
	pointOnRadiusDescribed_.setY(pointOnRadiusDescribed_.getY() + dy);

	pointOnRadiusInscribed_.setX(pointOnRadiusInscribed_.getX() + dx);
	pointOnRadiusInscribed_.setY(pointOnRadiusInscribed_.getY() + dy);
}

void Regular::move(const Point& center) {
	double dx = center.getX() - center_.getX();
	double dy = center.getY() - center_.getY();
	move(dx, dy);
}

Regular* Regular::clone() const {
	return new Regular(*this);
}

std::string Regular::getName() const {
	return std::string("REGULAR");
}

double Regular::getRadiusDescribed() const {
	double a = sqrt(pow(pointOnRadiusDescribed_.getX() - center_.getX(), 2) + pow(pointOnRadiusDescribed_.getY() - center_.getY(), 2));
	return a;
}

double Regular::getRadiusInscribed() const {
	double a1 = pow(pointOnRadiusInscribed_.getX() - center_.getX(), 2);
	double a2 = pow(pointOnRadiusInscribed_.getY() - center_.getY(), 2);
	double b = sqrt(pow(pointOnRadiusInscribed_.getX() - center_.getX(), 2) + pow(pointOnRadiusInscribed_.getY() - center_.getY(), 2));
	return b;
}

std::ostream& operator<<(std::ostream& out, const Regular& obj) {
	out << std::fixed << std::setprecision(1) << obj.getName() << " " << obj.getArea() << " " << obj.getFrameRectangle() << std::endl;
	return out;
}