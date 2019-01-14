#pragma once

#include <eigen3/Eigen/Core>

class Circle
{
private:
    Eigen::Vector2d point;
    double radius;
public:
    Circle();
    Circle(const double x, const double y, const double radius);
    Circle(const Eigen::Vector2d point, const double radius);
    ~Circle();

    double getX() const;
    double getY() const;
    double getRadius() const;
    Eigen::Vector2d getPoint() const;

    void setX(const double x);
    void setY(const double x);
    void setRadius(const double radius);
    void setPoint(const Eigen::Vector2d point);

};
