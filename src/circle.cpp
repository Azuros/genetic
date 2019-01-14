#include "../include/genetic/circle.hpp"

Circle::Circle():point(Eigen::Vector2d(0.0, 0.0)), radius(0.0)
{

}

Circle::Circle(const double x, const double y, const double radius):point(Eigen::Vector2d(x, y)), radius(radius)
{

}

Circle::Circle(const Eigen::Vector2d point, const double radius):point(point), radius(radius)
{

}

Circle::~Circle()
{

}

double Circle::getX() const
{
    return this->point.x();
}

double Circle::getY() const
{
    return this->point.y();
}

double Circle::getRadius() const
{
    return this->radius;
}

Eigen::Vector2d Circle::getPoint() const
{
    return this->point;
}

void Circle::setX(const double x)
{
    this->point.x() = x;
}

void Circle::setY(const double y)
{
   this->point.y() = y;
}

void Circle::setRadius(const double radius)
{
    this->radius = radius;
}

void Circle::setPoint(const Eigen::Vector2d point)
{
    this->point = point;
}
