#include "../include/genetic/settings.hpp"

#include <iostream>

Settings::Settings(const size_t popullationSize, const size_t maxSimulationSteps, const size_t hiddenLayerSize, const size_t laserSize, const size_t visualization, const size_t iterationGeneration, const double weightInitialization, const double mutationRate, const double extinctionRate, const std::string outputName):popullationSize(popullationSize), maxSimulationSteps(maxSimulationSteps), hiddenLayerSize(hiddenLayerSize), laserSize(laserSize), visualization(visualization), iterationGeneration(iterationGeneration), weightInitialization(weightInitialization), mutationRate(mutationRate), extinctionRate(extinctionRate), outputName(outputName)
{
    if (this->popullationSize % 2 != 0) {
        this->popullationSize += 1;
    }
}

Settings::~Settings()
{

}

size_t Settings::getPopullationSize() const
{
    return this->popullationSize;
}

size_t Settings::getMaxSimulationSteps() const
{
    return this->maxSimulationSteps;
}

size_t Settings::getHiddenLayerSize() const
{
    return this->hiddenLayerSize;
}

size_t Settings::getLaserSize() const
{
    return this->laserSize;
}

size_t Settings::getVisualization() const
{
    return this->visualization;
}

size_t Settings::getIterationGeneration() const
{
    return this->iterationGeneration;
}

double Settings::getWeightInitialization() const
{
    return this->weightInitialization;
}

double Settings::getMutationRate() const
{
    return this->mutationRate;
}

double Settings::getExtinctionRate() const
{
    return this->extinctionRate;
}

std::string Settings::getOutputName() const
{
    return this->outputName;
}

void Settings::printSettings() const
{
    std::cout << "*** Settings ***\n"
              << "iteration of generation: " << this->iterationGeneration << "\n"
              << "visualition at every iteration: " << this->visualization << "\n"
              << "popullation size: " << this->popullationSize << "\n"
              << "max number of simulation step: " << this->maxSimulationSteps << "\n"
              << "number of hidden layer neurons: " << this->hiddenLayerSize << "\n"
              << "laser size: " << this->laserSize << "\n"
              << "weight initialization: " << this->weightInitialization << "\n"
              << "percent chance for one mutation" << this->mutationRate << "\n"
              << "percent of the extinction: " << this->extinctionRate << "\n"
              << "output data name: " << this->outputName << "\n"
              << std::endl;
}
