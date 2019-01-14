#include "../include/genetic/genetic.hpp"
#include "../include/genetic/parser.hpp"
#include "../include/genetic/settings.hpp"

#include <iostream>
#include <random>


int main(const int argc, const char **argv)
{
    Parser parser;

    if(!parser.parse(argc, argv))
    {
        std::cerr << "ERROR: Failure parsing arguments and value!" << std::endl;
        return -1;
    }

    if (parser.getShowHelp()) {
        parser.printHelp();
        return  0;
    }

    if (!parser.checkSettings()) {
        parser.printHelp();
        std::cerr << "ERROR: Failure by checking the settings!" << std::endl;
        return -1;
    }

    const Settings settings = parser.getSettings();

    settings.printSettings();

    Genetic genetic(settings);

    for (size_t i = 0; i < settings.getIterationGeneration(); ++i) {
        genetic.switchGeneration();
        genetic.evaluate();
        genetic.select();
        genetic.status(i + 1);

        if (settings.getVisualization() != 0 && i % settings.getVisualization() == 0) {
            genetic.visualize();
        }
    }

    genetic.visualize();


    return 0;
}
