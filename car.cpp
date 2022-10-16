#include "car.h"

Car::Car() {
    std::cout << "Enter brand: ";
    std::cin >> brand;

    std::cout << "Enter model: ";
    std::cin >> model;

    std::cout << "Enter engine capacity: ";
    std::cin >> engine_capacity;
    InvalidInput;
    if(engine_capacity <= 0) throw "There cannot be less than 0 engine capacity";

    
    std::cout << "Enter colour: ";
    std::cin >> colour;

    std::cout << "Enter type of KPP: ";
    std::cin >> KPP_type;

}

Car::Car(std::ifstream &in) {
    in >> brand;
    in >> model;
    in >> engine_capacity;
    in >> colour;
    in >> KPP_type;
}

Car::Car(const Car &car) {
    strcpy_s(brand, 64, car.brand);
    strcpy_s(model, 64, car.model);
    engine_capacity = car.engine_capacity;
    strcpy_s(colour, 64, car.colour);
    strcpy_s(KPP_type, 64, car.KPP_type);
}

void Car::show() {
    std::cout << "Bus." << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model:" << model << std::endl;
    std::cout << "Engine capacity: " << engine_capacity << std::endl;
    std::cout << "Colour: " << colour << std::endl;
    std::cout << "Type of KPP: " << KPP_type << std::endl;
    
}

void Car::edit() {
    int choice;
    std::cout << "1. Brand\n" <<
              "2. Model\n" <<
              "3. Engine capacity\n" <<
              "4. Colour\n" <<
              "5. Type of KPP" << std::endl;

    std::cin >>choice;
    InvalidInput;

    switch (choice) {
        case 1:
            std::cin >> brand;
            break;
        case 2:
            std::cin >> model;
            break;
        case 3:
            std::cin >> engine_capacity;
            InvalidInput;
            if(engine_capacity <= 0) throw "There cannot be less than 0 engine capacity";
            break;
        case 4:
            std::cin >> colour;
            break;
        case 5:
            std::cin >> KPP_type;
            break;
        default:
            throw "Invalid value";
            break;
    }

}

void Car::save_to_file(std::ofstream &out) {
    out << CAR;
    out << brand;
    out << model;
    out << engine_capacity;
    out << colour;
    out << KPP_type;
}
