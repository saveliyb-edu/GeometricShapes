#pragma once
#include "FrameRectangle.h"
#include <string>
#include "Point.h"


class Shape {
public:
    virtual double getArea() const = 0;
    virtual FrameRectangle getFrameRectangle() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void move(const Point& center) = 0;
    //virtual void scale(double coefficient) = 0;
    virtual Shape* clone() const = 0;
    virtual std::string getName() const = 0;
};

