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
	pointOnRadiusInscribed_ = other.pointOnRadiusDescribed_;
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
	//double a = getRadiusInscribed();
	//double b = RadiusDescribed;
	//double x = acos(getRadiusInscribed() / RadiusDescribed);
	unsigned int numberSides = round(3.1415 / (acos(RadiusDescribed / getRadiusInscribed())));
	if (numberSides == 0) {
		return 0;
	}
	double square = numberSides / 2 * RadiusDescribed * RadiusDescribed * sin(3.1415 / numberSides);
	return square;
}

FrameRectangle Regular::getFrameRectangle() const {
	//unsigned int numberSides = 180 / (acos(getRadiusInscribed() / getRadiusDescribed()));
	unsigned int numberSides = round(3.1415 / (acos(getRadiusDescribed() / getRadiusInscribed())));
	Point lowerLeft(center_);
	Point upperRight(center_);
	Point temp;
	double angle = 2 * acos(getRadiusInscribed() / getRadiusDescribed());
	double zeroAngle = acos((pointOnRadiusDescribed_.getX() - center_.getX()) / getRadiusDescribed());
	for (int i = 0; i < numberSides; i+=2) {
		temp.setX(cos(zeroAngle + angle*i) * getRadiusDescribed() + center_.getX());
		temp.setY(sin(zeroAngle + angle * i) * getRadiusDescribed() + center_.getY());

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
	FrameRectangle frame(center_, lowerLeft, upperRight);
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
	double a = sqrt(pow(center_.getX() - pointOnRadiusDescribed_.getX(), 2) + pow(center_.getY() - pointOnRadiusDescribed_.getY(), 2));
	return a;
	//return sqrt(pow(center_.getX() - pointOnRadiusDescribed_.getX(), 2) + pow(center_.getY() - pointOnRadiusDescribed_.getY(), 2));
}

double Regular::getRadiusInscribed() const {
	double b = sqrt(pow(center_.getX() - pointOnRadiusInscribed_.getX(), 2) + pow(center_.getY() - pointOnRadiusInscribed_.getY(), 2));
	return b;
	//return sqrt(pow(center_.getX() - pointOnRadiusInscribed_.getX(), 2) + pow(center_.getY() - pointOnRadiusInscribed_.getY(), 2));
}

std::ostream& operator<<(std::ostream& out, const Regular& obj) {
	out << std::fixed << std::setprecision(1) << obj.getName() << " " << obj.getArea() << " " << obj.getFrameRectangle() << std::endl;
	return out;
}