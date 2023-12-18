#include <iostream>
#include "Point.h"
#include "FrameRectangle.h"
#include "Ellipse.h"
#include "Regular.h"
#include <cmath>

int main() {
    setlocale(LC_ALL, "ru");
    
    std::cout << "Ellipse: 1.5, 1.5, 1.5, 3" << std::endl;
    Ellipse ellipse1(1.5, 1.5, 1.5, 3);
    std::cout << ellipse1 << std::endl;


    ellipse1.move(5, 5);
    std::cout << "Ellipse move on 5, 5" << std::endl;
    std::cout << ellipse1 << std::endl;
    Point zero(0, 0);
    Point point111(5, 6);
    ellipse1.move(zero);
    std::cout << "Ellipse move to 5, 5" << std::endl;
    std::cout << ellipse1 << std::endl;

    Shape* ellipse2 = ellipse1.clone();

    Ellipse ellipse3(ellipse1);
    std::cout << ellipse3 << std::endl;

    std::cout << "Move cloned ellipse1" << std::endl;
    std::cout << &ellipse2 << std::endl << std::endl;
    std::cout << ellipse2 << std::endl << std::endl;

    delete ellipse2;
    
    Point zeropoint;
    try {
        Ellipse el3(zeropoint, 0, 10);
        std::cout << el3 << std::endl;
    }
    catch (const char* error_message1) {
        std::cout << error_message1 << std::endl;
    }
    std::cout << std::endl;

    try {
        Ellipse el4(0.5, -4, 10, 0);
        std::cout << el4 << std::endl;
    }
    catch (const char* error_message2) {
        std::cout << error_message2 << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Triangle: ожидание" << std::endl;
    std::cout << "REGULAR 43.3 0.0 0.0 10.0 8.7" << std::endl << "Вывод:" << std::endl;
    Point zero1(5, 5/sqrt(3));
    Point pointMin1(5, 0);
    Point pointMax1(0, 0);
    Regular triangle(zero1, pointMax1, pointMin1);
    std::cout << triangle << std::endl;


    std::cout << "Square: ожидание" << std::endl;
    std::cout << "REGULAR 4.0 -1.0 -1.0 1.0 1.0" << std::endl << "Вывод:" << std::endl;
    Point zero2(0, 0);
    Point pointMin2(1, 0);
    Point pointMax2(1, 1);
    Regular square(zero2, pointMax2, pointMin2);
    std::cout << square << std::endl;



    std::cout << "Pentagon: ожидание" << std::endl;
    std::cout << "REGULAR 3.4 1.0 0.0 3.3 2.3" << std::endl << "Вывод:" << std::endl;
    Point zero3(2.1881909602356, 1.1881909602356);
    Point pointMin3(1.3210197609601, 1.6300367553551);
    Point pointMax3(1, 1);
    Regular pentagon(zero3, pointMax3, pointMin3);
    std::cout << pentagon << std::endl;

    std::cout << "Octadecagon: ожидание" << std::endl;
    std::cout << "REGULAR 6533.3 -42.1 -8.0 50.1 82.7" << std::endl << "Вывод:" << std::endl;
    Point zero4(4, 37.370254556941);
    Point pointMin4(4, -8);
    Point pointMax4(-4, -8);
    Regular octadecagon(zero4, pointMax4, pointMin4);
    std::cout << octadecagon << std::endl;


    std::cout << "19-gon: ожидание" << std::endl;
    std::cout << "REGULAR 1090.5 -19.6 -15.4 17.8 22.1" << std::endl << "Вывод:" << std::endl;
    Point zero5(-0.7697967568343, 3.3206020048372);
    Point pointMin5(-13.0401269105472, -10.5862385432421);
    Point pointMax5(-10.7194856665992, -12.6337945019892);
    Regular polygon19(zero5, pointMax5, pointMin5);
    std::cout << polygon19 << std::endl;

    std::cout << "1000-gon: ожидание" << std::endl;
    std::cout << "REGULAR 3945.6 -38.4 -5.1 32.5 65.8" << std::endl << "Вывод:" << std::endl;
    Point zero6(-2.9122096489125, 30.3642082888162);
    Point pointMin6(-7.5959283033748, -4.763681619507);
    Point pointMax6(-7.7062861873104, -4.7489672351259);
    Regular polygon1000(zero6, pointMax6, pointMin6);
    std::cout << polygon1000 << std::endl;

    Point zero7(0, 0);
    Point firstPoint(1, 0);
    Point seconfPoint(0, 1);
    try {
        Regular example(zero7, firstPoint, seconfPoint);
        std::cout << example << std::endl;
    } catch (const char* error_message7) {
            std::cout << error_message7 << std::endl;
    }

    Point zero8(0, 0);
    Point Point8(1, 0);
    //Point Point8(0, 1);
    try {
        Regular example(zero8, Point8, zero8);
        std::cout << example << std::endl;
    }
    catch (const char* error_message7) {
        std::cout << error_message7 << std::endl;
    }
}
