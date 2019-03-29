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
              << "percent chance for one mutation: " << this->mutationRate << "\n"
              << "percent of the extinction: " << this->extinctionRate << "\n"
              << "output data name: " << this->outputName << "\n"
              << std::endl;
}
