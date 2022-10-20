#ifndef CAR_H
#define CAR_H

#include "garage.h"
#include <fstream>
#include <iostream>
#include <cstring>

class Car : public Garage{
private:
    char brand[64];
    char model[64];
    int engine_capacity;
    char colour[64];
    char KPP_type[64];

public:
    Car();
    explicit Car(std::ifstream& in);
    Car(const Car& car);
    ~Car() = default;

    char* get_brand() override;
    void show() override;
    void edit() override;
    void save_to_file(std::ofstream& out) override;
};


#endif //CAR_H
