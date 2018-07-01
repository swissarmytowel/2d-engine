#pragma once

#include <cmath>

namespace util
{
    class Point2D
    {
    public:
        Point2D() = default;
        ~Point2D() = default;
        Point2D(const Point2D &) = default;
        Point2D &operator=(const Point2D &) = default;
        Point2D(double x, double y)
            : _x(x), _y(y)
        {};

        Point2D &operator+=(const Point2D &other);
        Point2D &operator-=(const Point2D &other);
        Point2D &operator*=(const Point2D &other);
        Point2D &operator/=(const Point2D &other);

        const Point2D operator+(const Point2D &other) const;
        const Point2D operator-(const Point2D &other) const;
        const Point2D operator*(const Point2D &other) const;
        const Point2D operator/(const Point2D &other) const;

        void addToX(double value);
        void addToY(double value);

        double getX() const;
        double getY() const;

    private:
        double _x;
        double _y;
    };
}