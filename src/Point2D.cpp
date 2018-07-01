#include"../include/Point2D.hpp"

util::Point2D &util::Point2D::operator+=(const util::Point2D &other)
{
    _x += other.getX();
    _y += other.getY();

    return *this;
}

util::Point2D &util::Point2D::operator-=(const util::Point2D &other)
{
    _x -= other.getX();
    _y -= other.getY();

    return *this;
}

util::Point2D &util::Point2D::operator*=(const util::Point2D &other)
{
    _x *= other.getX();
    _y *= other.getY();

    return *this;
}

util::Point2D &util::Point2D::operator/=(const util::Point2D &other)
{
    _x /= other.getX();
    _y /= other.getY();

    return *this;
}

const util::Point2D util::Point2D::operator+(const util::Point2D &other) const
{
    Point2D result(_x + other.getX(), _y + other.getY());
    return result;
}

const util::Point2D util::Point2D::operator-(const util::Point2D &other) const
{
    Point2D result(_x - other.getX(), _y - other.getY());
    return result;
}

const util::Point2D util::Point2D::operator*(const util::Point2D &other) const
{
    Point2D result(_x * other.getX(), _y * other.getY());
    return result;
}

const util::Point2D util::Point2D::operator/(const util::Point2D &other) const
{
    Point2D result(_x / other.getX(), _y / other.getY());
    return result;
}

double util::Point2D::getX() const
{
    return _x;
}

double util::Point2D::getY() const
{
    return _y;
}

void util::Point2D::addToX(double value)
{
    _x += value;
}

void util::Point2D::addToY(double value)
{
    _y += value;
}
