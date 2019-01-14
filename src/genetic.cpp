#include "../include/genetic/genetic.hpp"

#include <random>
#include <time.h>
#include <omp.h>
#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <list>

const static double STD_MOVE_STEP_SIZE = 0.1;
const static size_t STD_NUMBER_OF_MOVE_STEP_FOR_SELECT_ACTION = 5;
const static size_t STD_COUT_SPACE = 12;

// Comperator for sort
bool comperatorGreater(const std::pair<size_t, double> &p1, const std::pair<size_t, double> &p2)
{
    return p1.second > p2.second;
}

Genetic::Genetic(const Settings settings):settings(settings), switchPopullation(false)
{
    if (!this->settings.getOutputName().empty()) {
        this->logger.createFiles(this->settings.getOutputName());
    }

    this->popullation1.reserve(settings.getPopullationSize());
    this->popullation2.reserve(settings.getPopullationSize());
    this->fitnessKumulative.reserve(settings.getPopullationSize());

    for (size_t i = 0; i < settings.getPopullationSize(); ++i)
    {
        Network network1(this->settings.getLaserSize(), this->settings.getHiddenLayerSize());
        network1.setRandomWeight(this->settings.getWeightInitialization());
        this->popullation1.push_back(Robot(settings.getLaserSize(), network1));

        Network network2(this->settings.getLaserSize(), this->settings.getHiddenLayerSize());
        network2.setRandomWeight(this->settings.getWeightInitialization());
        this->popullation2.push_back(Robot(settings.getLaserSize(), network2));
        this->fitnessKumulative.push_back(std::pair<size_t, double>(i,0.0));
    }
}

Genetic::~Genetic()
{

}

void Genetic::switchGeneration()
{
    switchPopullation = !switchPopullation;
}

void Genetic::sort(const std::vector<Robot> &generation)
{
    for (size_t i = 0; i < generation.size(); ++i) {
        fitnessKumulative[i] = std::pair<size_t, double>(i, generation[i].getFitness());
    }

    std::sort(fitnessKumulative.begin(), fitnessKumulative.end(), &comperatorGreater);

    for (size_t i = 1; i < fitnessKumulative.size(); ++i) {
        fitnessKumulative[i].second = fitnessKumulative[i - 1].second + fitnessKumulative[i].second;
    }
}

void Genetic::visualize()
{
    Robot robot = (switchPopullation)?this->popullation1[fitnessKumulative[0].first]:this->popullation2[fitnessKumulative[0].first];

    robot.reset();

    size_t checkpointIndex = robot.getCurrentCheckpointIndex();

    std::list<Eigen::Vector2d> path;
    path.push_back(robot.getPosition());

    //std::cout << "* * * Robot " << fitnessKumulative[0].first << " " << robot.getFitness() << " * * *" << std::endl;
    //robot.getNetwork().printWeight();

    for (size_t i = 0; i < this->settings.getMaxSimulationSteps() && !robot.collidied(); ++i) {
        robot.updateLaser(this->world.getLines());
        robot.selectAction();
        path.push_back(robot.getPosition());

        //std::cout << robot.getActionLinear() << "\t" << robot.getActionAngular() << std::endl;

        this->visualization.visualize(this->world, robot, path);

        usleep(10000);

        for (size_t j = 0; j < STD_NUMBER_OF_MOVE_STEP_FOR_SELECT_ACTION && !robot.collidied(); ++j) {
            robot.move(STD_MOVE_STEP_SIZE);
            robot.checkCollisionWithLines(this->world.getLines());
            robot.distanceToCheckpoint(this->world.getCheckpoints());

            // check if the checkpoint is reached
            if (checkpointIndex != robot.getCurrentCheckpointIndex()) {
                checkpointIndex = robot.getCurrentCheckpointIndex();
            }
        }
    }
}

void Genetic::evaluate()
{
    if (this->switchPopullation)
    {
        this->evaluation(this->popullation1);
    }
    else
    {
        this->evaluation(this->popullation2);
    }

}

void Genetic::select()
{
    if (switchPopullation)
    {
        this->selection(this->popullation1, this->popullation2);
    }
    else
    {
        this->selection(this->popullation2, this->popullation1);
    }
}

void Genetic::status(const size_t episode)
{
    const std::vector<Robot> &generation = (switchPopullation)? this->popullation1: this->popullation2;
    const double sum = fitnessKumulative[fitnessKumulative.size() - 1].second;
    const double avg = sum / static_cast<double>(fitnessKumulative.size());
    const double max = generation[fitnessKumulative[0].first].getFitness();
    const double min = generation[fitnessKumulative[fitnessKumulative.size() - 1].first].getFitness();

    std::cout << std::fixed << std::setprecision(2)
              << "eps: "  << std::setw(STD_COUT_SPACE) << std::left << episode
              << " avg: " << std::setw(STD_COUT_SPACE) << std::left << avg
              << " max: " << std::setw(STD_COUT_SPACE) << std::left << max
              << " min: " << std::setw(STD_COUT_SPACE) << std::left << min
              << std::endl;

    logger.log(episode, avg, max, min);
}

void Genetic::selection(const std::vector<Robot> &oldGeneration, std::vector<Robot> &newGeneration)
{
    this->sort(oldGeneration);

    const double sum = fitnessKumulative[fitnessKumulative.size() - 1].second;

    const size_t thresholdExtintion = oldGeneration.size() - static_cast<size_t>(static_cast<double>(oldGeneration.size()) * this->settings.getExtinctionRate());

    #pragma omp parallel for
    for (size_t i = 0; i < oldGeneration.size(); i += 2)
    {
        if (i < thresholdExtintion) {
            Network &childNetwork1 = newGeneration[i].getNetwork();
            Network &childNetwork2 = newGeneration[i + 1].getNetwork();
            size_t indexFitness1 = 0;
            size_t indexFitness2 = 0;
            double targetFitness1 = childNetwork1.getRandomDouble(0, sum);

            while(fitnessKumulative[indexFitness1].second < targetFitness1) ++indexFitness1;

            do
            {
                indexFitness2 = 0;
                double targetFitness2 = childNetwork2.getRandomDouble(0, sum);
                while(fitnessKumulative[indexFitness2].second < targetFitness2) ++indexFitness2;
            } while(indexFitness1 == indexFitness2);

            const size_t indexRobot1 = this->fitnessKumulative[indexFitness1].first;
            const size_t indexRobot2 = this->fitnessKumulative[indexFitness2].first;

            this->crossover(oldGeneration[indexRobot1].getNetwork(), oldGeneration[indexRobot2].getNetwork(), childNetwork1, childNetwork2);
            this->mutation(childNetwork1);
            this->mutation(childNetwork2);
        }
        else {
            newGeneration[i].getNetwork().setRandomWeight(this->settings.getWeightInitialization());
            newGeneration[i + 1].getNetwork().setRandomWeight(this->settings.getWeightInitialization());;
        }

    }
}

void Genetic::mutation(Network &network)
{
    if (network.getRandomDouble(0, 1.0) <= this->settings.getMutationRate()) {
        const long index = static_cast<long>(network.getRandomInt(0, static_cast<int>(network.getWeightInputHidden().size() + network.getWeightHiddenOutput().size())));

        if (index < network.getWeightInputHidden().size()) {
            network.getWeightInputHidden()(index) = network.getRandomDouble(-this->settings.getWeightInitialization(), this->settings.getWeightInitialization());
        } else {
            network.getWeightInputHidden()(index - network.getWeightInputHidden().size()) = network.getRandomDouble(-this->settings.getWeightInitialization(), this->settings.getWeightInitialization());
        }

    }
}

void Genetic::evaluation(std::vector<Robot> &popullation)
{
    #pragma omp parallel for
    for (size_t index = 0; index < popullation.size(); ++index) {
        Robot &robot = popullation[index];

        robot.reset();

        double fitness = 0;
        double minDistanceToCheckpoint = robot.distanceToCheckpoint(this->world.getCheckpoints());
        size_t checkpointIndex = robot.getCurrentCheckpointIndex();

        for (size_t i = 0; i < this->settings.getMaxSimulationSteps() && !robot.collidied(); ++i) {
            robot.updateLaser(this->world.getLines());
            robot.selectAction();

            for (size_t j = 0; j < STD_NUMBER_OF_MOVE_STEP_FOR_SELECT_ACTION && !robot.collidied(); ++j) {
                robot.move(STD_MOVE_STEP_SIZE);
                robot.checkCollisionWithLines(this->world.getLines());


                double distanceToCheckpoint = robot.distanceToCheckpoint(this->world.getCheckpoints());

                // give the robot the fitness when it approach to the checkpoint
                if (distanceToCheckpoint < minDistanceToCheckpoint) {
                    fitness += minDistanceToCheckpoint - distanceToCheckpoint;
                    minDistanceToCheckpoint = distanceToCheckpoint;
                }

                // check if the checkpoint is reached
                if (checkpointIndex != robot.getCurrentCheckpointIndex()) {
                    checkpointIndex = robot.getCurrentCheckpointIndex();
                    minDistanceToCheckpoint = robot.distanceToCheckpoint(world.getCheckpoints());
                }
            }
        }

        robot.setFitness(fitness);
    }
}

void Genetic::crossover(const Network &parentNetwork1, const Network &parentNetwork2, Network &childNetwork1, Network &childNetwork2)
{
    for (long i = 0; i < childNetwork1.getWeightInputHidden().size(); ++i) {
        if (childNetwork1.getRandomDouble(0, 1.0) < 0.5)
        {
            childNetwork1.getWeightInputHidden()(i) = parentNetwork1.getWeightInputHidden()(i);
            childNetwork2.getWeightInputHidden()(i) = parentNetwork2.getWeightInputHidden()(i);
        }
        else
        {
            childNetwork1.getWeightInputHidden()(i) = parentNetwork2.getWeightInputHidden()(i);
            childNetwork2.getWeightInputHidden()(i) = parentNetwork1.getWeightInputHidden()(i);
        }
    }

    for (long i = 0; i < childNetwork1.getWeightHiddenOutput().size(); ++i) {
        if (childNetwork1.getRandomDouble(0, 1.0) < 0.5)
        {
            childNetwork1.getWeightHiddenOutput()(i) = parentNetwork1.getWeightHiddenOutput()(i);
            childNetwork2.getWeightHiddenOutput()(i) = parentNetwork2.getWeightHiddenOutput()(i);
        }
        else
        {
            childNetwork1.getWeightHiddenOutput()(i) = parentNetwork2.getWeightHiddenOutput()(i);
            childNetwork2.getWeightHiddenOutput()(i) = parentNetwork1.getWeightHiddenOutput()(i);
        }
    }
}



