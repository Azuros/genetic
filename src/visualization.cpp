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
    /* all for checking
    for (size_t i = 0; i < world.getCheckpointSize(); ++i)
    {
        const Circle &circle = world.getCheckpointAt(i);
        fprintf(this->pipe, "%f %f %f\n", circle.getX(), circle.getY(), circle.getRadius());
    }
    */
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
