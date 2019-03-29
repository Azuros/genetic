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
