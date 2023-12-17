#pragma once
#include <iostream>

class Point {
	friend std::ostream& operator<<(std::ostream& out, const Point& obj);
private:
	double x_;
	double y_;
public:
	Point();
	Point(double x, double y);
	Point(const Point& other);
	~Point();

	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;
};

