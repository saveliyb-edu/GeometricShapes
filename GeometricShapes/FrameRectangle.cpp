#include "FrameRectangle.h"
#include "Point.h"
#include <iostream>
#include <iomanip>

FrameRectangle::FrameRectangle() {
	width_ = 0.0;
	height_ = 0.0;
	Point zeroPoint;
	this->setPos(zeroPoint);
}

FrameRectangle::FrameRectangle(Point pos, double width, double height) {
	width_ = width;
	height_ = height;
	pos_ = pos;
}

FrameRectangle::FrameRectangle(const FrameRectangle& other) {
	width_ = other.getWidth();
	height_ = other.getHeight();
	pos_ = other.getPos();
}

FrameRectangle::FrameRectangle(Point pos, Point lowerLeft, Point upperRight) {
	pos_ = pos;
	width_ = upperRight.getX() - lowerLeft.getX();
	height_ = upperRight.getY() - lowerLeft.getY();
}

FrameRectangle::FrameRectangle(Point lowerLeft, Point upperRight) {
	width_ = upperRight.getX() - lowerLeft.getX();
	height_ = upperRight.getY() - lowerLeft.getY();
	Point pos(lowerLeft.getX() + width_ / 2, lowerLeft.getY() + height_ / 2);
	pos_ = pos;
}

FrameRectangle::~FrameRectangle() {}

void FrameRectangle::setWidth(double width) {
	width_ = width;
}

void FrameRectangle::setHeight(double height) {
	height_ = height;
}

void FrameRectangle::setPos(Point pos) {
	pos_ = pos;
}

double FrameRectangle::getWidth() const {
	return width_;
}

double FrameRectangle::getHeight() const {
	return height_;
}

Point FrameRectangle::getPos() const {
	return pos_;
}

std::ostream& operator<<(std::ostream& out, const FrameRectangle& obj) {
	Point lowerLeft(obj.getPos().getX() - obj.getWidth() / 2, obj.getPos().getY() - obj.getHeight() / 2);
	Point upperRight(obj.getPos().getX() + obj.getWidth() / 2, obj.getPos().getY() + obj.getHeight() / 2);
	out << std::fixed << std::setprecision(1) << lowerLeft << " " << upperRight;
	return out;
}