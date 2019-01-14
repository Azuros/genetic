#include "../include/genetic/robot.hpp"

#include <iostream>

Robot::Robot(const size_t laserSize, const Network &network):pose(Eigen::Affine2d::Identity()), radius(0.125), laserMaxRange(3.0), linearVelocity(0.0), linearMaxVelocity(1.0), angularVelocity(0.0), angularMaxVelocity(0.75), isCollidied(false), currentCheckpointIndex(0), network(network)
{
    this->initLasers(laserSize);
}

Robot::~Robot()
{

}

void Robot::initLasers(const size_t size)
{
    switch (size) {
        case 3:
            createLaser3();
        break;

        case 5:
            createLaser5();
        break;

        case 7:
            createLaser7();
        break;

        case 9:
            createLaser9();
        break;

        case 11:
            createLaser11();
        break;

        case 13:
            createLaser13();
        break;

        default:
            std::cerr << "FATAL: Robot laser size does not match any pattern!" << std::endl;
            exit(-1);
    }
}

void Robot::createLaser3()
{
    this->lasers.reserve(3);

    this->lasers.push_back(Eigen::Vector2d( 1.0,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0,  0.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0, -1.0).normalized());

    for (size_t i = 0; i < this->lasers.size(); ++i) {
        this->lasersDistance.push_back(this->laserMaxRange);
    }
}

void Robot::createLaser5()
{
    this->lasers.reserve(5);

    this->lasers.push_back(Eigen::Vector2d( 0.0,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0,  0.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0, -1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 0.0, -1.0).normalized());

    for (size_t i = 0; i < this->lasers.size(); ++i) {
        this->lasersDistance.push_back(this->laserMaxRange);
    }
}

void Robot::createLaser7()
{
    this->lasers.reserve(7);

    this->lasers.push_back(Eigen::Vector2d(-1.0,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 0.0,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0,  0.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0, -1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 0.0, -1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d(-1.0, -1.0).normalized());


    for (size_t i = 0; i < this->lasers.size(); ++i) {
        this->lasersDistance.push_back(this->laserMaxRange);
    }
}

void Robot::createLaser9()
{
    this->lasers.reserve(9);

    this->lasers.push_back(Eigen::Vector2d( 0.0,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 0.5,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0,  0.5).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0,  0.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0, -0.5).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0, -1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 0.5, -1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 0.0, -1.0).normalized());

    for (size_t i = 0; i < this->lasers.size(); ++i) {
        this->lasersDistance.push_back(this->laserMaxRange);
    }
}

void Robot::createLaser11()
{
    this->lasers.reserve(11);

    this->lasers.push_back(Eigen::Vector2d(-0.5,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 0.0,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 0.5,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0,  0.5).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0,  0.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0, -0.5).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0, -1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 0.5, -1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 0.0, -1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d(-0.5, -1.0).normalized());

    for (size_t i = 0; i < this->lasers.size(); ++i) {
        this->lasersDistance.push_back(this->laserMaxRange);
    }
}

void Robot::createLaser13()
{
    this->lasers.reserve(13);

    this->lasers.push_back(Eigen::Vector2d(-1.0,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d(-0.5,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 0.0,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 0.5,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0,  1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0,  0.5).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0,  0.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0, -0.5).normalized());
    this->lasers.push_back(Eigen::Vector2d( 1.0, -1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 0.5, -1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d( 0.0, -1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d(-0.5, -1.0).normalized());
    this->lasers.push_back(Eigen::Vector2d(-1.0, -1.0).normalized());

    for (size_t i = 0; i < this->lasers.size(); ++i) {
        this->lasersDistance.push_back(this->laserMaxRange);
    }
}

Line Robot::getLaserAt(const size_t i) const
{
    // scale the laservector and transform into robot coordinate system
    Eigen::Vector2d laserEnd = this->pose * (lasers[i] * lasersDistance[i]);
    return Line(this->pose.translation(), laserEnd);
}

size_t Robot::getLaserSize() const
{
    return this->lasers.size();
}

const Network &Robot::getNetwork() const
{
    return this->network;
}

Network &Robot::getNetwork()
{
    return this->network;
}

const Eigen::Affine2d &Robot::getPose() const
{
    return this->pose;
}

double Robot::getRadius() const
{
    return this->radius;
}

double Robot::getX() const
{
    return this->pose.translation().x();
}

double Robot::getY() const
{
    return this->pose.translation().y();
}

Eigen::Vector2d Robot::getPosition() const
{
    return this->pose.translation();
}

void Robot::move(const double time)
{
    this->pose.translate(Eigen::Vector2d(this->linearVelocity * time, 0.0f));
    this->pose.rotate(this->angularVelocity * time);
}

bool Robot::collidied() const
{
    return this->isCollidied;
}

void Robot::selectAction()
{
    this->network.getAction(this->lasersDistance, this->linearVelocity, this->angularVelocity);

    this->linearVelocity *= linearMaxVelocity;
    this->angularVelocity *= angularMaxVelocity;
}

size_t Robot::getCurrentCheckpointIndex() const
{
    return this->currentCheckpointIndex;
}

double Robot::distanceToCheckpoint(const std::vector<Circle> &checkpoints)
{
    const Circle &checkpoint = checkpoints[this->currentCheckpointIndex];
    const double dx = this->getX() - checkpoint.getX();
    const double dy = this->getY() - checkpoint.getY();
    const double distance = std::sqrt(dx*dx + dy*dy);

    if (distance < checkpoint.getRadius()) {
        currentCheckpointIndex = (this->currentCheckpointIndex + 1) % checkpoints.size();
    }

    return distance;
}

void Robot::reset()
{
    this->pose = Eigen::Affine2d::Identity();
    this->currentCheckpointIndex = 0;
    this->isCollidied = false;
    this->linearVelocity = 0.0;
    this->angularVelocity = 0.0;
}

void Robot::updateLaser(const std::vector<Line> &lines)
{
    // fill laser with max range
    for (size_t i = 0; i < lasers.size(); ++i)
    {
        this->lasersDistance[i] = this->laserMaxRange;
    }

    Eigen::Affine2d invPose = this->pose.inverse();

    for (size_t i = 0; i < lines.size(); ++i) {
        Eigen::Vector2d p1 = invPose * lines[i].getPoint1();
        Eigen::Vector2d p2 = invPose * lines[i].getPoint2();
        this->calculateLaserLineIntersection(Line(p1, p2));
    }
}

void Robot::calculateLaserLineIntersection(const Line &line)
{
    /***
     * Formular from: https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection
     *
     * Intersection of two lines ->Given two points on each line
     * numerator_x = (x1*y2 - y1*x2)(x3 -x4) - (x1 - x2)(x3*y4 - y3*x4)
     * numerator_y = (x1*y2 - y1*x2)(y3 -y4) - (y1 - y2)(x3*y4 - y3*x4)
     * denominator = (x1 - x2)(y3 - y4) - (y1 -y2)(x3 -x4)
     *
     * The formula can be reduced, because the lidar is in the origin -> x4 = y4 = 0
     * numerator_x = (x1*y2 - y1*x2)(x3)
     * numerator_y = (x1*y2 - y1*x2)(y3)
     * denominator = (x1 - x2)(y3) - (y1 -y2)(x3)
     ***/

    const double epsilon = 0.000001;

    // min && max with Epsilon for Bounding Box. case line is horizontal or vertical and the bounding box is a line two.
    const double min_x = std::min(line.getX1(),line.getX2()) - epsilon;
    const double min_y = std::min(line.getY1(),line.getY2()) - epsilon;
    const double max_x = std::max(line.getX1(),line.getX2()) + epsilon;
    const double max_y = std::max(line.getY1(),line.getY2()) + epsilon;

    const double x1y2_y1x2 = line.getX1()*line.getY2() - line.getY1()*line.getX2();
    const double d_x1x2 = line.getX1() - line.getX2();
    const double d_y1y2 = line.getY1() - line.getY2();

    for (size_t i = 0; i < this->lasers.size(); ++i) {
        const double x3 = lasers[i].x();
        const double y3 = lasers[i].y();

        const double denominator = d_x1x2 * y3 - d_y1y2 * x3;

        const double x_intersect = x1y2_y1x2 * x3 / denominator;
        const double y_intersect = x1y2_y1x2 * y3 / denominator;

        //check if point is in the right direction and intersect is on line
        if ((((0 <= x_intersect) == (0 <= x3)) && ((0 <= y_intersect) == (0 <= y3)))
                && ((min_x <= x_intersect) && (x_intersect <= max_x))
                && ((min_y <= y_intersect) && (y_intersect <= max_y)) )
        {
            const double distance = std::sqrt(x_intersect*x_intersect + y_intersect * y_intersect);
            this->lasersDistance[i] = std::min(this->lasersDistance[i], distance);
        }
    }
}

#include <iostream>

bool Robot::isPointInLineSegment(const Line &line)
{
    // from: https://stackoverflow.com/questions/17581738/check-if-a-point-projected-on-a-line-segment-is-not-outside-it
    double dx = line.getX2() - line.getX1();
    double dy = line.getY2() - line.getY1();
    double inner_product = (this->getX() - line.getX1()) * dx + (this->getY() - line.getY1()) * dy;

    return 0 <= inner_product && inner_product <= dx*dx + dy*dy;
}

double Robot::calculateDistanceFromPointToLine(const Line &line)
{
    const double dx = line.getX2() - line.getX1();
    const double dy = line.getY2() - line.getY1();
    const double numerator = std::abs(dy*this->getX() - dx*this->getY() + line.getX2()*line.getY1() - line.getY2()*line.getX1());
    const double denominator = std::sqrt(dx * dx + dy * dy);

    return numerator / denominator;
}


void Robot::checkCollisionWithLines(const std::vector<Line> &lines)
{
    for (size_t i = 0; i < lines.size(); ++i) {
        if (calculateDistanceFromPointToLine(lines[i]) < this->radius && isPointInLineSegment(lines[i])) {
            this->isCollidied = true;
            return;
        }
    }
}

double Robot::getActionLinear() const
{
    return this->linearVelocity;
}

double Robot::getActionAngular() const
{
    return this->angularVelocity;
}

void Robot::setFitness(const double fintess)
{
    this->fitness = fintess;
}

double Robot::getFitness() const
{
    return this->fitness;
}
