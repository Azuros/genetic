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

#include <string>

class Settings
{
private:
    size_t popullationSize;
    size_t maxSimulationSteps;
    size_t hiddenLayerSize;
    size_t laserSize;
    size_t visualization;
    size_t iterationGeneration;
    double weightInitialization;
    double mutationRate;
    double extinctionRate;
    std::string outputName;
public:
    Settings(const size_t popullationSize, const size_t maxSimulationSteps, const size_t hiddenLayerSize, const size_t laserSize, const size_t visualization, const size_t iterationGeneration, const double weightInitialization, const double mutationRate, const double extinctionRate, const std::string outputName);
    ~Settings();

    size_t getPopullationSize() const;
    size_t getMaxSimulationSteps() const;
    size_t getHiddenLayerSize() const;
    size_t getLaserSize() const;
    size_t getVisualization() const;
    size_t getIterationGeneration() const;
    double getWeightInitialization() const;
    double getMutationRate() const;
    double getExtinctionRate() const;
    std::string getOutputName() const;

    void printSettings() const;
};
