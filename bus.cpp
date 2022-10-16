//
// Created by UserPC on 10/12/2022.
//

#include "bus.h"

Bus::Bus() {
    std::cout << "Enter brand: ";
    std::cin >> brand;

    std::cout << "Enter model: ";
    std::cin >> model;

    std::cout << "Enter number of passenger seats: ";
    std::cin >> num_of_passenger_seats;
    if(std::cin.fail() || std::cin.get() != '\n') throw "Invalid value";

    std::cout << "Enter max number of passenger: ";
    std::cin >> max_num_of_passengers;
    if(std::cin.fail() || std::cin.get() != '\n') throw "Invalid value";

    std::cout << "Enter destination: ";
    std::cin >> destination;
}

Bus::Bus(std::ifstream &in) {

}

Bus::Bus(const Bus &car) {

}

void Bus::show() {

}

void Bus::edit() {

}

void Bus::save_to_file(std::ofstream &out) {

}
