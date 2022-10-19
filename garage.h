#ifndef GARAGE_H
#define GARAGE_H
#include <fstream>
#include <iostream>
#include <limits>

#define InvalidInput if(std::cin.fail() || std::cin.get() != '\n'){std::cin.clear(); \
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                  \
std::cin.sync();                                                                     \
throw "Invalid value"; }

enum Vehicles {
    BIKE = 1,
    CAR,
    BUS
};

class Garage {
public:

    virtual void show() = 0;
    virtual void edit() = 0;
    virtual void save_to_file(std::ofstream& out) = 0;

};

#endif //GARAGE_H
