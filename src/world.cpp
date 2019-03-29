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

#include "../include/genetic/world.hpp"

#include <limits>

void World::constructDefaultWorld()
{
    std::vector<Eigen::Vector2d> topBorder;
    std::vector<Eigen::Vector2d> bottomBorder;

    topBorder.push_back(Eigen::Vector2d(-1.00,  0.50));
    topBorder.push_back(Eigen::Vector2d( 1.00,  0.50));
    topBorder.push_back(Eigen::Vector2d( 2.00, -0.50));
    topBorder.push_back(Eigen::Vector2d( 3.00, -0.50));
    topBorder.push_back(Eigen::Vector2d( 4.00,  0.50));
    topBorder.push_back(Eigen::Vector2d( 6.00,  0.50));
    topBorder.push_back(Eigen::Vector2d( 7.00, -0.00));
    topBorder.push_back(Eigen::Vector2d( 8.00, -1.50));
    topBorder.push_back(Eigen::Vector2d( 8.00, -4.00));
    topBorder.push_back(Eigen::Vector2d( 5.00, -7.00));
    topBorder.push_back(Eigen::Vector2d( 3.00, -8.00));
    topBorder.push_back(Eigen::Vector2d( 2.00, -8.00));
    topBorder.push_back(Eigen::Vector2d( 1.00, -7.50));
    topBorder.push_back(Eigen::Vector2d(-0.00, -6.50));
    topBorder.push_back(Eigen::Vector2d(-0.25, -5.75));
    topBorder.push_back(Eigen::Vector2d(-1.25, -5.00));
    topBorder.push_back(Eigen::Vector2d(-2.00, -5.00));
    topBorder.push_back(Eigen::Vector2d(-2.75, -5.75));
    topBorder.push_back(Eigen::Vector2d(-3.00, -6.50));
    topBorder.push_back(Eigen::Vector2d(-4.00, -7.50));
    topBorder.push_back(Eigen::Vector2d(-5.00, -8.00));
    topBorder.push_back(Eigen::Vector2d(-6.00, -8.00));
    topBorder.push_back(Eigen::Vector2d(-7.50, -7.50));
    topBorder.push_back(Eigen::Vector2d(-8.00, -6.00));
    topBorder.push_back(Eigen::Vector2d(-8.00, -3.00));
    topBorder.push_back(Eigen::Vector2d(-6.50, -2.00));
    topBorder.push_back(Eigen::Vector2d(-6.50, -1.00));
    topBorder.push_back(Eigen::Vector2d(-8.00,  0.00));
    topBorder.push_back(Eigen::Vector2d(-8.00,  2.50));
    topBorder.push_back(Eigen::Vector2d(-7.50,  2.75));
    topBorder.push_back(Eigen::Vector2d(-8.00,  3.00));
    topBorder.push_back(Eigen::Vector2d(-8.00,  4.50));
    topBorder.push_back(Eigen::Vector2d(-7.25,  4.75));
    topBorder.push_back(Eigen::Vector2d(-8.00,  5.00));
    topBorder.push_back(Eigen::Vector2d(-8.00,  7.00));
    topBorder.push_back(Eigen::Vector2d(-7.00,  8.00));
    topBorder.push_back(Eigen::Vector2d(-4.00,  8.00));
    topBorder.push_back(Eigen::Vector2d(-4.00,  6.50));
    topBorder.push_back(Eigen::Vector2d(-3.00,  6.50));
    topBorder.push_back(Eigen::Vector2d(-3.00,  8.00));
    topBorder.push_back(Eigen::Vector2d( 0.00,  8.00));
    topBorder.push_back(Eigen::Vector2d( 2.00,  6.00));
    topBorder.push_back(Eigen::Vector2d( 3.50,  7.50));
    topBorder.push_back(Eigen::Vector2d( 4.50,  8.00));
    topBorder.push_back(Eigen::Vector2d( 5.00,  8.00));
    topBorder.push_back(Eigen::Vector2d( 5.75,  7.50));
    topBorder.push_back(Eigen::Vector2d( 6.00,  7.00));
    topBorder.push_back(Eigen::Vector2d( 6.00,  6.75));
    topBorder.push_back(Eigen::Vector2d( 5.75,  6.25));
    topBorder.push_back(Eigen::Vector2d( 5.00,  5.50));
    topBorder.push_back(Eigen::Vector2d( 5.00,  5.25));
    topBorder.push_back(Eigen::Vector2d( 5.25,  5.00));
    topBorder.push_back(Eigen::Vector2d( 6.50,  5.00));
    topBorder.push_back(Eigen::Vector2d( 7.25,  4.50));
    topBorder.push_back(Eigen::Vector2d( 7.75,  3.50));
    topBorder.push_back(Eigen::Vector2d( 8.00,  1.00));
    topBorder.push_back(Eigen::Vector2d( 5.50,  1.00));
    topBorder.push_back(Eigen::Vector2d( 4.50,  2.00));
    topBorder.push_back(Eigen::Vector2d( 3.75,  2.25));
    topBorder.push_back(Eigen::Vector2d( 2.50,  2.25));
    topBorder.push_back(Eigen::Vector2d( 1.00,  2.75));
    topBorder.push_back(Eigen::Vector2d(-0.50,  2.75));
    topBorder.push_back(Eigen::Vector2d(-1.50,  2.25));
    topBorder.push_back(Eigen::Vector2d(-2.50,  2.25));
    topBorder.push_back(Eigen::Vector2d(-2.75,  2.00));
    topBorder.push_back(Eigen::Vector2d(-2.50,  1.75));
    topBorder.push_back(Eigen::Vector2d(-2.00,  1.75));
    topBorder.push_back(Eigen::Vector2d(-1.75,  1.75));
    topBorder.push_back(Eigen::Vector2d(-1.25,  1.25));
    topBorder.push_back(Eigen::Vector2d(-2.00, -0.50));

    bottomBorder.push_back(Eigen::Vector2d(-0.50, -0.50));
    bottomBorder.push_back(Eigen::Vector2d( 0.50, -0.50));
    bottomBorder.push_back(Eigen::Vector2d( 1.50, -1.50));
    bottomBorder.push_back(Eigen::Vector2d( 3.50, -1.50));
    bottomBorder.push_back(Eigen::Vector2d( 4.50, -0.50));
    bottomBorder.push_back(Eigen::Vector2d( 5.50, -0.50));
    bottomBorder.push_back(Eigen::Vector2d( 6.50, -1.25));
    bottomBorder.push_back(Eigen::Vector2d( 7.00, -2.50));
    bottomBorder.push_back(Eigen::Vector2d( 7.00, -3.50));
    bottomBorder.push_back(Eigen::Vector2d( 5.00, -5.50));
    bottomBorder.push_back(Eigen::Vector2d( 3.00, -6.50));
    bottomBorder.push_back(Eigen::Vector2d( 2.50, -6.50));
    bottomBorder.push_back(Eigen::Vector2d( 1.50, -6.00));
    bottomBorder.push_back(Eigen::Vector2d( 1.00, -5.00));
    bottomBorder.push_back(Eigen::Vector2d( 0.00, -4.00));
    bottomBorder.push_back(Eigen::Vector2d(-1.50, -3.50));
    bottomBorder.push_back(Eigen::Vector2d(-3.00, -4.00));
    bottomBorder.push_back(Eigen::Vector2d(-4.00, -5.50));
    bottomBorder.push_back(Eigen::Vector2d(-5.00, -6.25));
    bottomBorder.push_back(Eigen::Vector2d(-6.00, -6.25));
    bottomBorder.push_back(Eigen::Vector2d(-7.00, -5.25));
    bottomBorder.push_back(Eigen::Vector2d(-7.00, -3.50));
    bottomBorder.push_back(Eigen::Vector2d(-5.50, -2.50));
    bottomBorder.push_back(Eigen::Vector2d(-5.50, -0.50));
    bottomBorder.push_back(Eigen::Vector2d(-7.00,  0.50));
    bottomBorder.push_back(Eigen::Vector2d(-7.00,  1.50));
    bottomBorder.push_back(Eigen::Vector2d(-6.00,  2.50));
    bottomBorder.push_back(Eigen::Vector2d(-6.00,  3.50));
    bottomBorder.push_back(Eigen::Vector2d(-6.75,  3.75));
    bottomBorder.push_back(Eigen::Vector2d(-6.00,  4.00));
    bottomBorder.push_back(Eigen::Vector2d(-6.00,  5.50));
    bottomBorder.push_back(Eigen::Vector2d(-7.00,  5.75));
    bottomBorder.push_back(Eigen::Vector2d(-6.75,  6.25));
    bottomBorder.push_back(Eigen::Vector2d(-6.00,  7.00));
    bottomBorder.push_back(Eigen::Vector2d(-5.00,  7.00));
    bottomBorder.push_back(Eigen::Vector2d(-5.00,  5.50));
    bottomBorder.push_back(Eigen::Vector2d(-2.00,  5.50));
    bottomBorder.push_back(Eigen::Vector2d(-2.00,  7.00));
    bottomBorder.push_back(Eigen::Vector2d(-0.50,  7.00));
    bottomBorder.push_back(Eigen::Vector2d( 2.00,  4.50));
    bottomBorder.push_back(Eigen::Vector2d( 4.50,  7.00));
    bottomBorder.push_back(Eigen::Vector2d( 4.75,  7.00));
    bottomBorder.push_back(Eigen::Vector2d( 5.00,  6.75));
    bottomBorder.push_back(Eigen::Vector2d( 5.00,  6.50));
    bottomBorder.push_back(Eigen::Vector2d( 4.25,  5.75));
    bottomBorder.push_back(Eigen::Vector2d( 4.00,  5.00));
    bottomBorder.push_back(Eigen::Vector2d( 4.25,  4.50));
    bottomBorder.push_back(Eigen::Vector2d( 4.75,  4.00));
    bottomBorder.push_back(Eigen::Vector2d( 5.50,  3.75));
    bottomBorder.push_back(Eigen::Vector2d( 6.25,  3.75));
    bottomBorder.push_back(Eigen::Vector2d( 6.50,  3.50));
    bottomBorder.push_back(Eigen::Vector2d( 7.00,  1.75));
    bottomBorder.push_back(Eigen::Vector2d( 6.00,  2.25));
    bottomBorder.push_back(Eigen::Vector2d( 5.50,  3.25));
    bottomBorder.push_back(Eigen::Vector2d( 4.50,  3.75));
    bottomBorder.push_back(Eigen::Vector2d( 2.50,  3.75));
    bottomBorder.push_back(Eigen::Vector2d( 1.00,  3.25));
    bottomBorder.push_back(Eigen::Vector2d(-0.50,  3.25));
    bottomBorder.push_back(Eigen::Vector2d(-1.50,  3.75));
    bottomBorder.push_back(Eigen::Vector2d(-2.50,  3.75));
    bottomBorder.push_back(Eigen::Vector2d(-3.50,  3.00));
    bottomBorder.push_back(Eigen::Vector2d(-3.75,  2.50));
    bottomBorder.push_back(Eigen::Vector2d(-3.75,  1.50));
    bottomBorder.push_back(Eigen::Vector2d(-3.00,  1.00));
    bottomBorder.push_back(Eigen::Vector2d(-2.25,  1.00));
    bottomBorder.push_back(Eigen::Vector2d(-3.00, -1.00));
    bottomBorder.push_back(Eigen::Vector2d(-2.00, -1.50));


    this->checkpoints.push_back(Circle( 2.50, -1.00, 0.50));
    this->checkpoints.push_back(Circle( 5.00,  0.00, 0.50));
    this->checkpoints.push_back(Circle( 7.50, -3.00, 0.50));
    this->checkpoints.push_back(Circle( 2.50, -7.25, 0.75));
    this->checkpoints.push_back(Circle(-1.50, -4.25, 0.75));
    this->checkpoints.push_back(Circle(-5.50, -7.10, 0.90));
    this->checkpoints.push_back(Circle(-7.50, -4.50, 0.50));
    this->checkpoints.push_back(Circle(-6.00, -1.50, 0.50));
    this->checkpoints.push_back(Circle(-7.50,  1.00, 0.50));
    this->checkpoints.push_back(Circle(-7.00,  7.00, 0.75));
    this->checkpoints.push_back(Circle(-4.55,  7.40, 0.55));
    this->checkpoints.push_back(Circle(-4.40,  6.10, 0.55));
    this->checkpoints.push_back(Circle(-2.60,  6.10, 0.55));
    this->checkpoints.push_back(Circle(-2.40,  7.40, 0.55));
    this->checkpoints.push_back(Circle( 2.00,  5.40, 0.60));
    this->checkpoints.push_back(Circle( 5.25,  7.25, 0.50));
    this->checkpoints.push_back(Circle( 7.45,  1.50, 0.45));
    this->checkpoints.push_back(Circle(-2.75,  2.80, 0.60));
    this->checkpoints.push_back(Circle(-2.25, -0.90, 0.45));
    this->checkpoints.push_back(Circle( 0.00,  0.00, 0.50));

    for (size_t i = 1; i < topBorder.size(); ++i)
    {
        this->lines.push_back(Line(topBorder[i - 1], topBorder[i]));
    }
    this->lines.push_back(Line(topBorder[topBorder.size() - 1], topBorder[0]));

    for (size_t i = 1; i < bottomBorder.size(); ++i)
    {
        this->lines.push_back(Line(bottomBorder[i - 1], bottomBorder[i]));
    }
    this->lines.push_back(Line(bottomBorder[bottomBorder.size() - 1], bottomBorder[0]));
}

void World::calculateMinMax()
{
    this->minX = std::numeric_limits<double>::max();
    this->minY = std::numeric_limits<double>::max();

    this->maxX = std::numeric_limits<double>::lowest();
    this->maxY = std::numeric_limits<double>::lowest();

    for (size_t i = 0; i < lines.size(); ++i) {
        const Line &line = this->lines[i];

        this->minX = std::min(this->minX, std::min(line.getX1(), line.getX2()));
        this->minY = std::min(this->minY, std::min(line.getY1(), line.getY2()));

        this->maxX = std::max(this->maxX, std::max(line.getX1(), line.getX2()));
        this->maxY = std::max(this->maxY, std::max(line.getY1(), line.getY2()));
    }
}

World::World()
{
    this->constructDefaultWorld();
    this->calculateMinMax();
}

World::~World()
{

}

double World::getMinX() const
{
    return this->minX;
}

double World::getMinY() const
{
    return this->minY;
}

double World::getMaxX() const
{
    return this->maxX;
}

double World::getMaxY() const
{
    return this->maxY;
}

const std::vector<Line> World::getLines() const
{
    return this->lines;
}

const std::vector<Circle> World::getCheckpoints() const
{
    return this->checkpoints;
}
