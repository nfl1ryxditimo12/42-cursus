#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed   check;
    int     count = 0;

    if (Point::compareCoord(a, b, point))
    {
        check = Point::getCoordX(a, b, point);
        if (point.getX() < check)
            count++;
    }

    if (Point::compareCoord(b, c, point))
    {
        check = Point::getCoordX(b, c, point);
        if (point.getX() < check)
            count++;
    }

    if (Point::compareCoord(c, a, point))
    {
        check = Point::getCoordX(c, a, point);
        if (point.getX() < check)
            count++;
    }

    return (count % 2 == 1);
}
