#ifndef BIKE_H
#define BIKE_H

#include "garage.h"
#include <fstream>
#include <iostream>

class Bike : public Garage {
private:
    char brand[64];
    char model[64];
    char engine_capacity[64];
    char engine_power[64];
    char terrain_type[64];

public:
    Bike();
    explicit Bike(std::ifstream& in);
    Bike(const Bike& car);
    ~Bike() = default;

    void show() override;
    void edit() override;
    void save_to_file(std::ofstream& out) override;
};


#endif //BIKE_H
