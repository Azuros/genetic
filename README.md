# genetic

This program represents a small genetic algorithm. The scenario is a robot which tries to travel the longest distance through a parkour. The controller of the robot is a simple feed forward neuronal net with one hidden layer. The input layer are the distance of the lidar sensor and the outpout layer are the linear and angular velocity. The genes of the genetic algorithm are the weight of the neuronal net.

## Requirements
* Ubuntu 18.04 or 16.04 (tested with)
* cmake
* Eigen (for neuronal net and simulation)

optional
* gnuplot-x11 (visualization)
* OpenMP

## Installation

Install all requirements
```
sudo apt install cmake build-essential git libomp-dev gnuplot-x11 libeigen3-dev 
```

Clone the repository
```
git clone https://github.com/Azuros/genetic
```

Go into the genetic directory and create a build directory.
```
cd genetic
mkdir build
```

Go into the build directory and run cmake.
```
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
```

Compile with make.
```
make -j 4
```

Execute the program.
```
./genetic
```

## Parameters

Show help for parameter information
```
./genetic -h
```

