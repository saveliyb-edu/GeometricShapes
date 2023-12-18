#pragma once
#include "Point.h"
#include <iostream>

class FrameRectangle {
	friend std::ostream& operator<<(std::ostream& out, const FrameRectangle& obj);
private:
	double width_;
	double height_;
	Point pos_;
public:
	FrameRectangle();
	FrameRectangle(Point pos, double width, double height);
	FrameRectangle(const FrameRectangle& other);
	FrameRectangle(Point pos, Point lowerLeft, Point upperRight);
	FrameRectangle(Point lowerLeft, Point upperRight);
	~FrameRectangle();

	void setWidth(double width);
	void setHeight(double height);
	void setPos(Point pos);
	double getWidth() const;
	double getHeight() const;
	Point getPos() const;
};

