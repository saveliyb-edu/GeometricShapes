#include <iostream>
#include "Point.h"
#include "FrameRectangle.h"
#include "Ellipse.h"
#include "Regular.h"

int main() {
    Ellipse ellipse1(1.5, 1.5, 1.5, 3);
    std::cout << ellipse1 << std::endl;
    //ellipse1.move(5, 5);
    //std::cout << ellipse1 << std::endl;
    //Point zero(0, 0);
    //ellipse1.move(zero);
    //std::cout << ellipse1 << std::endl;

    //Ellipse* ellipse2 = ellipse1.clone();
    //std::cout << ellipse2 << std::endl;

    //delete ellipse2;
    Point zero;
    Point pointMin(0, 1);
    Point pointMax(1, 1);
    Regular regular(zero, pointMin, pointMax);
    std::cout << regular;
}
