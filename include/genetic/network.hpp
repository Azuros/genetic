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
