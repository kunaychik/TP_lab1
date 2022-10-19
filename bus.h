#ifndef BUS_H
#define BUS_H

#include "garage.h"
#include <fstream>
#include <iostream>
#include <cstring>


class Bus : public Garage {
private:
    char brand[64];
    char model[64];
    int num_of_passenger_seats;
    int max_num_of_passengers;
    char destination[64];

public:
    Bus();
    explicit Bus(std::ifstream& in);
    Bus(const Bus& car);
    ~Bus() = default;

    void show() override;
    void edit() override;
    void save_to_file(std::ofstream& out) override;
};


#endif //BUS_H
