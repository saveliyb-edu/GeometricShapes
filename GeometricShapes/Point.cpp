#include "Point.h"
#include <iostream>
#include <iomanip>


Point::Point() {
	this->setX(0.0);
	this->setY(0.0);
}

Point::Point(double x, double y) {
	this->setX(x);
	this->setY(y);
}

Point::Point(const Point& other) {
	setX(other.getX());
	setY(other.getY());
}

Point::~Point() {}

void Point::setX(double value) {
	x_ = value;
}

void Point::setY(double value) {
	y_ = value;
}

double Point::getX() const {
	return x_;
}

double Point::getY() const {
	return y_;
}

std::ostream& operator<<(std::ostream& out, const Point& obj) {
	out << std::fixed << std::setprecision(1) << obj.getX() << " " << obj.getY();
	return out;
}