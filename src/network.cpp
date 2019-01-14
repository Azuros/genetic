#include "../include/genetic/network.hpp"

#include <iostream>
#include <chrono>

Network::Network(const size_t inputSize, const size_t hiddenSize): inputLayer(inputSize + 1), hiddenLayer(hiddenSize + 1), weightInputHidden(hiddenSize, inputSize + 1), weightHiddenOutput(2, hiddenSize + 1), randomGenerator(std::chrono::system_clock::now().time_since_epoch().count())
{
    // set bias to one
    this->inputLayer[this->inputLayer.size() - 1] = 1.0;
    this->hiddenLayer[this->hiddenLayer.size() - 1] = 1.0;
}

Network::~Network()
{

}

void Network::getAction(const std::vector<double> &input, double &outputLinear, double &outputAngular)
{
    // fill input
    for (size_t i = 0; i < input.size(); ++i) {
        this->inputLayer[static_cast<long>(i)] = input[i];
    }

    // Sum of the hidden layer
    this->hiddenLayer.head(this->hiddenLayer.size() - 1) = this->weightInputHidden * this->inputLayer;

    // Activationfunction of the hidden layer
    this->hiddenLayer.array().head(hiddenLayer.size() - 1) = this->hiddenLayer.array().head(hiddenLayer.size() - 1).tanh();

    // Sum of the output layer
    this->outputLayer = this->weightHiddenOutput * this->hiddenLayer;

    // Activationfunction of the output layer
    this->outputLayer.array() = this->outputLayer.array().tanh();

    outputLinear = (this->outputLayer[0] + 1.0) * 0.5;
    outputAngular = this->outputLayer[1];

    //printWeight();
    //std::cout << outputLinear << "\t" << outputAngular << std::endl;
}

void Network::setRandomWeight(const double weightInitialization)
{
    // fill random weight for input hidden matrix
    for (long i = 0; i < weightInputHidden.size(); ++i) {
        this->weightInputHidden(i) = getRandomDouble(-weightInitialization, weightInitialization);
    }

    // fill random weight for hidden out matrix
    for (long i = 0; i < weightHiddenOutput.size(); ++i) {
        this->weightHiddenOutput(i) = getRandomDouble(-weightInitialization, weightInitialization);
    }
}

double Network::getRandomDouble(const double min, const double max)
{
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(this->randomGenerator);
}

double Network::getRandomInt(const int min, const int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(this->randomGenerator);
}

const Eigen::MatrixXd &Network::getWeightInputHidden() const
{
    return this->weightInputHidden;
}

Eigen::MatrixXd &Network::getWeightInputHidden()
{
    return this->weightInputHidden;
}

const Eigen::MatrixXd &Network::getWeightHiddenOutput() const
{
    return this->weightHiddenOutput;
}

Eigen::MatrixXd &Network::getWeightHiddenOutput()
{
    return this->weightHiddenOutput;
}

void Network::printWeight() const
{
    std::cout << ">> weightInputHiden <<\n" << this->weightInputHidden << "\n>> weightHiddenOutput <<\n" << this->weightHiddenOutput << std::endl;
    //std::cout << this->inputLayer << "\n---\n" << this->hiddenLayer << "\n---\n" << this->outputLayer << std::endl;
}
