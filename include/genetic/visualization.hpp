#pragma once

#include "world.hpp"
#include "robot.hpp"

#include <list>

#include <eigen3/Eigen/Core>


class Visualization
{
private:
    bool isInitialized;

    FILE *pipe;

    void construct_world();

public:
    Visualization();
    ~Visualization();
    void visualize(const World &world, const Robot &robot, const std::list<Eigen::Vector2d> &path);
};
