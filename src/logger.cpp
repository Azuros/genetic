#include "../include/genetic/logger.hpp"

#include <iomanip>
#include <iostream>


Logger::Logger()
{

}

Logger::~Logger()
{
    if (file.is_open()) {
        file.close();
    }
}

void Logger::createFiles(const std::string path)
{
    file.open(path);

    if (!file.is_open()) {
        std::cerr << "ERROR: Can not create '" << path << "'!" << std::endl;
        exit(-1);
    }
}

void Logger::log(const size_t episode, const double avg, const double max, const double min)
{
    if (file.is_open()) {
        file << std::fixed << std::setprecision(2) << episode << ", " << avg << ", " << max << ", " << min << "\n";
    }
}
