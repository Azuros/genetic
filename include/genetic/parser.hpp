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
