#include "bike.h"

Bike::Bike() {
    std::cout << "Enter brand: ";
    std::cin >> brand;

    std::cout << "Enter model: ";
    std::cin >> model;

    std::cout << "Enter engine capacity: ";
    std::cin >> engine_capacity;

    std::cout << "Enter engine power: ";
    std::cin >> engine_power;

    std::cout << "Enter type of terrain: ";
    std::cin >> terrain_type;
}

Bike::Bike(std::ifstream &in) {
    in >> brand;
    in >> model;
}

Bike::Bike(const Bike &car) {

}

void Bike::show() {

}

void Bike::edit() {

}

void Bike::save_to_file(std::ofstream &out) {

}
