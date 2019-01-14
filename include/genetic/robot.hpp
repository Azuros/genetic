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
    double angularVelocity;
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
