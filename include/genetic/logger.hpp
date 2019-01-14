#pragma once

#include <string>
#include <fstream>


class Logger
{
private:
    std::ofstream file;
public:
    Logger();
    ~Logger();

    void createFiles(const std::string path);
    void log(const size_t episode, const double avg, const double max, const double min);
};

