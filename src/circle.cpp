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
