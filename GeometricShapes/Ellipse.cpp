#include "Ellipse.h"
#include "Point.h"
#include <iostream>
#include <iomanip>


Ellipse::Ellipse() {
	Point zero_point;
	center_ = zero_point;
	radiusX_ = 0.0;
	radiusY_ = 0.0;
}

Ellipse::Ellipse(const Point center, const double radius_x, const double radius_y) {
	center_ = center;
	radiusX_ = radius_x;
	radiusY_ = radius_y;
}

Ellipse::Ellipse(const Ellipse& other) {
	center_ = other.center_;
	radiusX_ = other.radiusX_;
	radiusY_ = other.radiusY_;
}

Ellipse::Ellipse(const double centerX, const double centerY, const double radius_x, const double radius_y) {
	Point center_point(centerX, centerY);
	center_ = center_point;
	radiusX_ = radius_x;
	radiusY_ = radius_y;
}

Ellipse::~Ellipse() {
}

double Ellipse::getArea() const {
	return 3.141592653589793 * radiusX_ * radiusY_;
}

FrameRectangle Ellipse::getFrameRectangle() const {
	FrameRectangle frame(center_, radiusX_ * 2, radiusY_ * 2);
	return frame;
}

void Ellipse::move(double dx, double dy) {
	center_.setX(center_.getX() + dx);
	center_.setY(center_.getY() + dy);
}

void Ellipse::move(const Point& center) {
	center_ = center;
}

Ellipse* Ellipse::clone() const {
	return new Ellipse(*this);
}

std::string Ellipse::getName() const {
	return std::string("ELLIPSE");
}

std::ostream& operator<< (std::ostream& out, const Ellipse& obj) {
	out << std::fixed << std::setprecision(1) << obj.getName() << " " << obj.getArea() << " " << obj.getFrameRectangle() << std::endl;
	return out;
}