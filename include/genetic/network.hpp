#pragma once

#include <vector>
#include <random>

#include <eigen3/Eigen/Core>


class Network
{
private:
    Eigen::VectorXd inputLayer;
    Eigen::VectorXd hiddenLayer;
    Eigen::Vector2d outputLayer;
    Eigen::MatrixXd weightInputHidden;
    Eigen::MatrixXd weightHiddenOutput;

    std::default_random_engine randomGenerator;


public:
    Network(const size_t inputSize, const size_t hiddenSize);
    ~Network();
    void getAction(const std::vector<double> &input, double &outputLinear, double &outputAngular);
    void setRandomWeight(const double weightInitialization);
    double getRandomDouble(const double min, const double max);
    double getRandomInt(const int min, const int max);

    const Eigen::MatrixXd& getWeightInputHidden() const;
    Eigen::MatrixXd& getWeightInputHidden();
    const Eigen::MatrixXd& getWeightHiddenOutput() const;
    Eigen::MatrixXd& getWeightHiddenOutput();


    void printWeight() const;

};
