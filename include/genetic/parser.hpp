#pragma once

#include "../include/genetic/settings.hpp"

#include <string>

class Parser
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

    bool showHelp;

    bool isInRange(const size_t i, const size_t numberOfArguments);
    bool parseSizeT(const char *argValue, size_t &value);
    bool parseDouble(const char *argValue, double &value);
    void errorValue(const std::string argument, const size_t i);

public:
    Parser();
    ~Parser();

    bool parse(const int argc, const char **argv);
    bool getShowHelp() const;
    bool checkSettings() const;
    Settings getSettings() const;
    void printHelp() const;
};
