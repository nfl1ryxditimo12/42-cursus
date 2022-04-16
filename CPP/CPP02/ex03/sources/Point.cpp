#include "Point.hpp"

Point::Point(void): x(0), y(0) {}

Point::Point(float a, float b): x(Fixed(a)), y(Fixed(b)) {}

Point::Point(const Point &cls): x(cls.x), y(cls.y) {}

Point &Point::operator=(const Point &cls)
{
    (void)cls;
    return *this;
}

Fixed Point::getX(void) const
{
    return this->x;
}

Fixed Point::getY(void) const
{
    return this->y;
}

bool Point::compareCoord(const Point &c1, const Point &c2, const Point &point)
{
    if ((c1.getY() > point.getY()) != (c2.getY() > point.getY()))
        return true;
    return false;
}

Fixed Point::getCoordX(const Point &c1, const Point &c2, const Point &point)
{
    return ((c2.getX() - c1.getX()) * (point.getY() - c1.getY()) / (c2.getY() - c1.getY()) + c1.getX());
}

Point::~Point(void) {}
