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

#include "robot.hpp"
#include "world.hpp"
#include "visualization.hpp"
#include "settings.hpp"
#include "network.hpp"
#include "logger.hpp"


class Genetic
{
private:
    Settings settings;
    std::vector<Robot> popullation1;
    std::vector<Robot> popullation2;
    std::vector<std::pair<size_t, double>> fitnessKumulative;
    size_t switchPopullation;
    World world;
    Visualization visualization;
    Logger logger;

    void selection(const std::vector<Robot> &oldGeneration, std::vector<Robot> &newGeneration);
    void evaluation(std::vector<Robot> &popullation);
    void crossover(const Network &parentNetwork1, const Network &parentNetwork2, Network &childNetwork1, Network &childNetwork2);
    void sort(const std::vector<Robot> &generation);
    void mutation(Network &network);
public:
    Genetic(const Settings settings);
    ~Genetic();
    void visualize();
    void evaluate();

    void select();
    void switchGeneration();
    void status(const size_t episode);
};
