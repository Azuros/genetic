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
