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

#include "line.hpp"
#include "circle.hpp"
#include "network.hpp"

#include <vector>

#include <eigen3/Eigen/Geometry>


class Robot
{
private:
    Eigen::Affine2d pose;
    double radius;
    double laserMaxRange;
    double fitness;
    double linearVelocity;
    double linearMaxVelocity;
    double angularVelocity;
    double angularMaxVelocity;
    bool isCollidied;
    std::vector<Eigen::Vector2d> lasers;
    std::vector<double> lasersDistance;
    size_t currentCheckpointIndex;
    Network network;
    void initLasers(const size_t size);
    void createLaser3();
    void createLaser5();
    void createLaser7();
    void createLaser9();
    void createLaser11();
    void createLaser13();
    void calculateLaserLineIntersection(const Line &line);
    double calculateDistanceFromPointToLine(const Line &line);
    bool isPointInLineSegment(const Line &line);

public:
    Robot(const size_t laserSize, const Network &network);
    ~Robot();

    Line getLaserAt(const size_t i) const;
    size_t getLaserSize() const;

    const Network& getNetwork() const;
    Network& getNetwork();


    const Eigen::Affine2d& getPose() const;
    double getRadius() const;
    double getX() const;
    double getY() const;
    Eigen::Vector2d getPosition() const;
    void move(const double time);
    bool collidied() const;
    void selectAction();
    size_t getCurrentCheckpointIndex() const;
    double distanceToCheckpoint(const std::vector<Circle> &checkpoints);
    void checkCollisionWithLines(const std::vector<Line> &lines);
    double getActionLinear() const;
    double getActionAngular() const;

    void setFitness(const double fintess);
    double getFitness() const;

    void reset();
    void updateLaser(const std::vector<Line> &lines);
};
