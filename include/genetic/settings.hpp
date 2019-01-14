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
