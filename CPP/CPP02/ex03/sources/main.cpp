#include "Point.hpp"

int main()
{
    Point	a(0, 0);
	Point	b(20, 0);
	Point	c(10, 15);
	Point	p1(10, 14.99);
	Point	p2(30, 50);
    Point   p3(19.998, 0);
    Point   p4(5, -1);
    Point   p5(19, 0.5);

    std::cout << "Point a X: " << a.getX() << ", Y: " << a.getY() << std::endl;
    std::cout << "Point b X: " << b.getX() << ", Y: " << b.getY() << std::endl;
    std::cout << "Point c X: " << c.getX() << ", Y: " << c.getY() << std::endl;

    std::cout << std::endl;

    std::cout << "Point p1 X: " << p1.getX() << ", Y: " << p1.getY() << std::endl;
    std::cout << "Point p2 X: " << p2.getX() << ", Y: " << p2.getY() << std::endl;
    std::cout << "Point p3 X: " << p3.getX() << ", Y: " << p3.getY() << std::endl;
    std::cout << "Point p4 X: " << p4.getX() << ", Y: " << p4.getY() << std::endl;
    std::cout << "Point p5 X: " << p5.getX() << ", Y: " << p5.getY() << std::endl;

    std::cout << std::endl;

	if (bsp(a, b, c, p1))
		std::cout << "\"p1\" is in the triangle" << std::endl;
	else
		std::cout << "\"p1\" is out of the triangle" << std::endl;
    if (bsp(a, b, c, p2))
		std::cout << "\"p2\" is in the triangle" << std::endl;
	else
		std::cout << "\"p2\" is out of the triangle" << std::endl;
    if (bsp(a, b, c, p3))
		std::cout << "\"p3\" is in the triangle" << std::endl;
	else
		std::cout << "\"p3\" is out of the triangle" << std::endl;
    if (bsp(a, b, c, p4))
		std::cout << "\"p4\" is in the triangle" << std::endl;
	else
		std::cout << "\"p4\" is out of the triangle" << std::endl;
    if (bsp(a, b, c, p5))
		std::cout << "\"p5\" is in the triangle" << std::endl;
	else
		std::cout << "\"p5\" is out of the triangle" << std::endl;
    
	return 0;
}
