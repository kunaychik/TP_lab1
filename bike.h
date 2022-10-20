#ifndef BIKE_H
#define BIKE_H

#include "garage.h"
#include <fstream>
#include <iostream>
#include <cstring>

class Bike : public Garage {
private:
    char brand[64];
    char model[64];
    int engine_capacity;
    int engine_power;
    char terrain_type[64];

public:
    Bike();
    explicit Bike(std::ifstream& in);
    Bike(const Bike& car);
    ~Bike() = default;

    char* get_brand() override;
    void show() override;
    void edit() override;
    void save_to_file(std::ofstream& out) override;
};


#endif //BIKE_H
