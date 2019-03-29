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

#include "../genetic/visualization.hpp"

#include <iostream>

Visualization::Visualization()
{
    isInitialized = false;
}

Visualization::~Visualization()
{
    if (isInitialized) {
        pclose(pipe);
    }
}

void Visualization::visualize(const World &world, const Robot &robot, const std::list<Eigen::Vector2d> &path)
{
    const std::vector<Line> &lines = world.getLines();
    const std::vector<Circle> &checkpoints = world.getCheckpoints();

    // init the pipeline if not initializied
    if (!this->isInitialized)
    {
        this->pipe = popen("/usr/bin/gnuplot -geometry 800x800 -persist -display :0.0", "w");
        this->isInitialized = true;
    }

    if (!this->pipe) {
        std::cerr << "Could not create gnuplotPipe! " <<std:: endl;
        return;
    }

    if (lines.size() == 0) {
        std::cerr << "World has no lines!" << std::endl;
        return;
    }

    fprintf(this->pipe, "set xrange [%f:%f]\n", world.getMinX() - 1.0, world.getMaxX() + 1.0);
    fprintf(this->pipe, "set yrange [%f:%f]\n", world.getMinY() - 1.0, world.getMaxY() + 1.0);
    fprintf(this->pipe, "plot '-' using 1:2:3 with circles lc 'magenta' fill solid border, '-' using 1:2:3:4 with vectors nohead lc 'blue', '-' using 1:2:3:4 with vectors nohead lc 'red', '-' using 1:2:3:4 with vectors nohead lc 'green', '-' using 1:2:3 with circles lc 'red', '-' using 1:2:3:4 with vectors lc 'red'\n");

    // create checkpoint
    fprintf(this->pipe, "%f %f %f\n", checkpoints[robot.getCurrentCheckpointIndex()].getX(), checkpoints[robot.getCurrentCheckpointIndex()].getY(), checkpoints[robot.getCurrentCheckpointIndex()].getRadius());
    fprintf(this->pipe, "EOF\n");

    // create the world lines
    for (size_t i = 0; i < lines.size(); ++i)
    {
        const Line &line = lines[i];
        fprintf(this->pipe, "%f %f %f %f\n",  line.getX1(), line.getY1(), line.getX2() - line.getX1(), line.getY2() - line.getY1());
    }
    fprintf(this->pipe, "EOF\n");

    // create path of the robot
    std::list<Eigen::Vector2d>::const_iterator iter = path.cbegin();
    Eigen::Vector2d lastPosition = *iter;
    while (iter != path.cend()) {
        const Line line(lastPosition, *iter);
        fprintf(this->pipe, "%f %f %f %f\n",  line.getX1(), line.getY1(), line.getX2() - line.getX1(), line.getY2() - line.getY1());
        lastPosition = *iter;
        ++iter;
    }
    fprintf(this->pipe, "EOF\n");

    // create laser
    for (size_t i = 0; i < robot.getLaserSize(); ++i) {
        const Line line = robot.getLaserAt(i);
        fprintf(this->pipe, "%f %f %f %f\n", line.getX1(), line.getY1(), line.getX2() - line.getX1(), line.getY2() - line.getY1());
    }
    fprintf(this->pipe, "EOF\n");

    // create robot
    fprintf(this->pipe, "%f %f %f\n", robot.getPose().translation().x(), robot.getPose().translation().y(), robot.getRadius());
    fprintf(this->pipe, "EOF\n");


    // create robot direction
    Eigen::Vector2d direction = robot.getPose().rotation() * Eigen::Vector2d(robot.getRadius(),0);
    fprintf(this->pipe, "%f %f %f %f\n", robot.getX(), robot.getY(), direction.x(), direction.y());

    fprintf(this->pipe, "EOF\n");

    fflush(pipe);
}
