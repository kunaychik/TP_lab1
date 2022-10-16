#include "car.h"

Car::Car() {
    std::cout << "Enter brand: ";
    std::cin >> brand;

    std::cout << "Enter model: ";
    std::cin >> model;

    std::cout << "Enter engine capacity: ";
    std::cin >> engine_capacity;

    std::cout << "Enter colour: ";
    std::cin >> colour;

    std::cout << "Enter type of KPP: ";
    std::cin >> KPP_type;

}

Car::Car(std::ifstream &in) {

}

Car::Car(const Car &car) {

}

void Car::show() {

}

void Car::edit() {

}

void Car::save_to_file(std::ofstream &out) {

}
