#ifndef CAR_H
#define CAR_H

#include "garage.h"
#include <fstream>
#include <iostream>

class Car : public Garage{
private:
    char brand[64];
    char model[64];
    char engine_capacity[64];
    char colour[64];
    char KPP_type[64];

public:
    Car();
    explicit Car(std::ifstream& in);
    Car(const Car& car);
    ~Car() = default;

    void show() override;
    void edit() override;
    void save_to_file(std::ofstream& out) override;
};


#endif //CAR_H
