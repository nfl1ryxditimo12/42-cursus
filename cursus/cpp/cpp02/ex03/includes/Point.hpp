#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;

    public:
        Point(void);
        Point(float a, float b);
        Point(const Point &cls);
        ~Point(void);

        Point &operator=(const Point &cls);

        Fixed getX(void) const;
        Fixed getY(void) const;

        static bool compareCoord(const Point &c1, const Point &c2, const Point &point);
        static Fixed getCoordX(const Point &c1, const Point &c2, const Point &point);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
