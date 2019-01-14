#include "../include/genetic/parser.hpp"
#include "../include/genetic/settings.hpp"

#include <iostream>

Parser::Parser(): popullationSize(100), maxSimulationSteps(250), hiddenLayerSize(7), laserSize(5), visualization(1), iterationGeneration(1000), weightInitialization(1.0), mutationRate(0.1), extinctionRate(0.2)
{

}

Parser::~Parser()
{

}

bool Parser::isInRange(const size_t i, const size_t numberOfArguments)
{
    return i < numberOfArguments;
}

bool Parser::parseSizeT(const char *argValue, size_t &value)
{
    long tmp;

    try {
        tmp = std::atol(argValue);
        if (tmp < 0) {
            std::cerr << "ERROR: Value must be positive!" << std::endl;
            return false;
        }

    }
    catch (...)
    {
        std::cerr << "ERROR: Value must be an integer!" << std::endl;
        return false;
    }

    value = static_cast<size_t>(tmp);
    return true;
}

bool Parser::parseDouble(const char *argValue, double &value)
{
    double tmp;

    try {
        tmp = std::atof(argValue);
    }
    catch (...)
    {
        std::cerr << "ERROR: Value must be a float!" << std::endl;
        return false;
    }

    value = static_cast<double>(tmp);
    return true;
}

void Parser::errorValue(const std::string argument, const size_t i)
{
    std::cerr << "ERROR: Parsing value for argument '" << argument << "' at position " << i << "!" << std::endl;
}

bool Parser::parse(const int argc, const char **argv)
{
    const size_t numberOfArguments = static_cast<size_t>(argc);

    size_t i = 1;


    while (i < numberOfArguments)
    {
        const std::string argument(argv[i]);

        // help
        if (argument.compare("-h") == 0) {
            this->showHelp = true;
            return true;
        }
        // popullationSize
        else if (argument.compare("-p") == 0) {
            i++;

            if(!isInRange(i, numberOfArguments) || !parseSizeT(argv[i], this->popullationSize))
            {
                this->errorValue("-p", i);
                return false;
            }
        }
        // maxSteps
        else if (argument.compare("-s") == 0)
        {
            i++;

            if(!isInRange(i, numberOfArguments) || !parseSizeT(argv[i], this->maxSimulationSteps))
            {
                this->errorValue("-s", i);
                return false;
            }
        }
        // hiddenLayerSize
        else if (argument.compare("-n") == 0)
        {
            i++;

            if(!isInRange(i, numberOfArguments) || !parseSizeT(argv[i], this->hiddenLayerSize))
            {
                this->errorValue("-n", i);
                return false;
            }
        }
        // visualization
        else if (argument.compare("-v") == 0)
        {
            i++;

            if(!isInRange(i, numberOfArguments) || !parseSizeT(argv[i], this->visualization))
            {
                this->errorValue("-v", i);
                return false;
            }
        }
        // iterationGeneration
        else if (argument.compare("-i") == 0)
        {
            i++;

            if(!isInRange(i, numberOfArguments) || !parseSizeT(argv[i], this->iterationGeneration))
            {
                this->errorValue("-i", i);
                return false;
            }
        }
        // laserSize
        else if (argument.compare("-l") == 0)
        {
            i++;

            if(!isInRange(i, numberOfArguments) || !parseSizeT(argv[i], this->laserSize))
            {
                this->errorValue("-l", i);
                return false;
            }
        }
        // mutationRate
        else if (argument.compare("-m") == 0)
        {
            i++;

            if(!isInRange(i, numberOfArguments) || !parseDouble(argv[i], this->mutationRate))
            {
                this->errorValue("-m", i);
                return false;
            }
        }
        // extinctionRate
        else if (argument.compare("-e") == 0)
        {
            i++;

            if(!isInRange(i, numberOfArguments) || !parseDouble(argv[i], this->extinctionRate))
            {
                this->errorValue("-e", i);
                return false;
            }
        }
        // weightInitialization
        else if (argument.compare("-w") == 0)
        {
            i++;

            if(!isInRange(i, numberOfArguments) || !parseDouble(argv[i], this->extinctionRate))
            {
                this->errorValue("-w", i);
                return false;
            }
        }
        else if(argument.compare("-o") == 0)
        {
            i++;

            if(!isInRange(i, numberOfArguments))
            {
                this->errorValue("-o", i);
                return false;
            }
            else
            {
                this->outputName = std::string(argv[i]);
            }
        }
        // unknown argument
        else
        {
            std::cerr << "ERROR: Unknown argument '" << argument << "' at position " << i << "!" << std::endl;
            return false;
        }

        ++i;
    }

    return true;
}

bool Parser::getShowHelp() const
{
    return this->showHelp;
}

bool Parser::checkSettings() const
{
    bool successful = true;

    if(!(1 <= this->iterationGeneration))
    {
        std::cerr << "ERROR: In '-i' got " << this->iterationGeneration << " must in range [1, inf]!" << std::endl;
        successful = false;
    }

    if(!(10 <= this->popullationSize))
    {
        std::cerr << "ERROR: In '-p' got " << this->popullationSize << " must in range [10, inf]!" << std::endl;
        successful = false;
    }

    if(!(50 <= this->maxSimulationSteps))
    {
        std::cerr << "ERROR: In '-s' got " << this->maxSimulationSteps << " must in range [50, inf]!" << std::endl;
        successful = false;
    }

    if(!(2 <= this->hiddenLayerSize))
    {
        std::cerr << "ERROR: In '-n' got " << this->hiddenLayerSize << " must in range [50, inf]!" << std::endl;
        successful = false;
    }

    if(!(3 == this->laserSize || 5 == this->laserSize || 7 == this->laserSize || 9 == this->laserSize || 11 == this->laserSize))
    {
        std::cerr << "ERROR: In '-l' got " << this->laserSize << " must in range [3,5,7,9,11]!" << std::endl;
        successful = false;
    }

    if (!(0.1 <= this->weightInitialization)) {
        std::cerr << "ERROR: In '-w' got " << this->weightInitialization << " must in range [0.1, inf]!" << std::endl;
        successful = false;
    }

    if (!(0.0 <= this->mutationRate && this->mutationRate <= 1.0)) {
        std::cerr << "ERROR: In '-m' got " << this->mutationRate << " must in range [0.1, inf]!" << std::endl;
        successful = false;
    }

    if (!(0.0 <= this->extinctionRate && this->extinctionRate <= 1.0)) {
        std::cerr << "ERROR: In '-m' got " << this->mutationRate << " must in range [0.1, inf]!" << std::endl;
        successful = false;
    }

    return successful;
}

Settings Parser::getSettings() const
{
    return Settings(this->popullationSize, this->maxSimulationSteps, this->hiddenLayerSize, this->laserSize, this->visualization, this->iterationGeneration, this->weightInitialization, this->mutationRate, this->extinctionRate, this->outputName);
}

void Parser::printHelp() const
{
    std::cout << "*** Help ***\n"
              << "usage: genetic [<argument> <value>]\n"
              << " arg    type     range     default     description\n"
              << " '-h'                                show this\n"
              << " '-i'  Integer  [1,  inf]   1000     iteration of generation\n"
              << " '-v'  Integer  [0,  inf]      1     visualition at every iteration\n"
              << " '-p'  Integer  [10, inf]    100     popullation size\n"
              << " '-s'  Integer  [50, inf]    250     max number of simulation step\n"
              << " '-n'  Integer  [2,  inf]      7     number of hidden layer neurons\n"
              << " '-l'  Integer  [3,5,7,9,11]   5     laser size\n"
              << " '-w'   Float   [0.1, inf]     1.0   weight initialization\n"
              << " '-m'   Float   [0.0, 1.0]     0.1   percent chance for one mutation\n"
              << " '-e'   Float   [0.0, 1.0]     0.2   percent of the extinction\n"
              << " '-o'  String                        output data name\n"
              << std::endl;
}


