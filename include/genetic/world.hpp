#pragma once

#include <vector>

#include "line.hpp"
#include "circle.hpp"
#include "robot.hpp"

class World
{
private:
    std::vector<Line> lines;
    std::vector<Circle> checkpoints;
    double minX;
    double maxX;
    double minY;
    double maxY;

    void constructDefaultWorld();
    void calculateMinMax();

public:
    World();
    ~World();

    double getMinX() const;
    double getMinY() const;
    double getMaxX() const;
    double getMaxY() const;

    const std::vector<Line> getLines() const;
    const std::vector<Circle> getCheckpoints() const;

    void evaluate(Robot robot, const size_t maxSteps);
};
