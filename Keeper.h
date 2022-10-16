#ifndef KEEPER_H
#define KEEPER_H

#include <fstream>
#include "car.h"
#include "bike.h"
#include "bus.h"

class Keeper {
public:

    Keeper();
    ~Keeper();

    void add_new_vehicle(); //
    void delete_vehicle(); //
    void edit(); //+
    void show(); // +
    void save(); //
    void upload_from_file(); //

private:
    Garage** my_garage;
    uint16_t count_of_vehicle;

    Garage* create_vehicle();
    Garage** add_vehicle_to_garage(Garage*);
};


#endif //KEEPER_H
