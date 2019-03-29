/***
 * Copyright 2019 Christian Jestel
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "../include/genetic/line.hpp"

Line::Line():point1(Eigen::Vector2d(0.0, 0.0)), point2(Eigen::Vector2d(0.0, 0.0))
{

}

Line::Line(const Eigen::Vector2d point1, const Eigen::Vector2d point2):point1(point1), point2(point2)
{

}

Line::Line(const double x1, const double y1, const double x2, const double y2):point1(Eigen::Vector2d(x1, y1)), point2(Eigen::Vector2d(x2, y2))
{

}

Line::~Line()
{

}

double Line::getX1() const
{
    return this->point1.x();
}

double Line::getY1() const
{
    return this->point1.y();
}

double Line::getX2() const
{
    return this->point2.x();
}

double Line::getY2() const
{
    return this->point2.y();
}

Eigen::Vector2d Line::getPoint1() const
{
    return this->point1;
}

Eigen::Vector2d Line::getPoint2() const
{
    return this->point2;
}

void Line::setX1(const double x1)
{
    this->point1.x() = x1;
}

void Line::setY1(const double y1)
{
    this->point1.y() = y1;
}

void Line::setX2(const double x2)
{
    this->point2.x() = x2;
}

void Line::setY2(const double y2)
{
    this->point2.x() = y2;
}

void Line::setPoint1(const Eigen::Vector2d point1)
{
    this->point1 = point1;
}

void Line::setPoint1(const double x1, const double y1)
{
    this->point1.x() = x1;
    this->point1.y() = y1;
}

void Line::setPoint2(const Eigen::Vector2d point2)
{
    this->point2 = point2;
}

void Line::setPoint2(const double x2, const double y2)
{
    this->point2.x() = x2;
    this->point2.y() = y2;
}
