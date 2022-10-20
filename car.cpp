#include "car.h"

Car::Car() {
    std::cout << "Enter brand: " << std::endl;
    std::cin >> brand;

    std::cout << "Enter model: " << std::endl;
    std::cin >> model;

    std::cout << "Enter engine capacity: " << std::endl;
    std::cin >> engine_capacity;
    InvalidInput;
    if(engine_capacity <= 0) throw "There cannot be less than 0 engine capacity";


    std::cout << "Enter colour: " << std::endl;
    std::cin >> colour;

    std::cout << "Enter type of KPP: " << std::endl;
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
    std::cout << "Car." << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
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
            std::cout << "New Brand" << std::endl;
            std::cin >> brand;
            break;
        case 2:
            std::cout << "New Model" << std::endl;
            std::cin >> model;
            break;
        case 3:
            std::cout << "New Engine capacity" << std::endl;
            std::cin >> engine_capacity;
            InvalidInput;
            if(engine_capacity <= 0) throw "There cannot be less than 0 engine capacity";
            break;
        case 4:
            std::cout << "New Colour" << std::endl;
            std::cin >> colour;
            break;
        case 5:
            std::cout << "New Type of KPP" << std::endl;
            std::cin >> KPP_type;
            break;
        default:
            throw "Invalid value";
    }

}

void Car::save_to_file(std::ofstream &out) {
    out << CAR << std::endl;
    out << brand << std::endl;
    out << model << std::endl;
    out << engine_capacity << std::endl;
    out << colour << std::endl;
    out << KPP_type << std::endl;
}

char *Car::get_brand() {
    return brand;
}
