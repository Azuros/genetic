#pragma once

#include <eigen3/Eigen/Core>

class Line
{
private:
    Eigen::Vector2d point1;
    Eigen::Vector2d point2;
public:
    Line();
    Line(const Eigen::Vector2d point1, const Eigen::Vector2d point2);
    Line(const double x1, const double y1, const double x2, const double y2);
    ~Line();


    double getX1() const;
    double getY1() const;
    double getX2() const;
    double getY2() const;
    Eigen::Vector2d getPoint1() const;
    Eigen::Vector2d getPoint2() const;

    void setX1(const double x1);
    void setY1(const double y1);
    void setX2(const double x2);
    void setY2(const double y2);
    void setPoint1(const Eigen::Vector2d point1);
    void setPoint1(const double x1, const double y1);
    void setPoint2(const Eigen::Vector2d point2);
    void setPoint2(const double x2, const double y2);
};
