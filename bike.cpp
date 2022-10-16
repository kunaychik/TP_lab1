#include "bike.h"

Bike::Bike() {
    std::cout << "Enter brand: ";
    std::cin >> brand;

    std::cout << "Enter model: ";
    std::cin >> model;

    std::cout << "Enter engine capacity: ";
    std::cin >> engine_capacity;
    InvalidInput;
    if(engine_capacity <= 0) throw "There cannot be less than 0 engine capacity";


    std::cout << "Enter engine power: ";
    std::cin >> engine_power;
    InvalidInput;
    if(engine_power <= 0) throw "There cannot be less than 0 engine power";


    std::cout << "Enter type of terrain: ";
    std::cin >> terrain_type;
}

Bike::Bike(std::ifstream &in) {
    in >> brand;
    in >> model;
    in >> engine_capacity;
    in >> engine_power;
    in >> terrain_type;
}

Bike::Bike(const Bike &bike) {
    strcpy_s(brand, 64, bike.brand);
    strcpy_s(model, 64, bike.model);
    engine_capacity = bike.engine_capacity;
    engine_power = bike.engine_power;
    strcpy_s(terrain_type, 64, bike.terrain_type);
}

void Bike::show() {
    std::cout << "Bus." << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model:" << model << std::endl;
    std::cout << "Engine capacity: " << engine_capacity << std::endl;
    std::cout << "Engine power: " << engine_power << std::endl;
    std::cout << "Type of terrain: " << terrain_type << std::endl;

}

void Bike::edit() {
    int choice;
    std::cout << "1. Brand\n" <<
                "2. Model\n" <<
                "3. Engine capacity\n" <<
                "4. Engine power\n" <<
                "5. Type of terrain" << std::endl;

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
            std::cin >> engine_power;
            InvalidInput;
            if(engine_power <= 0) throw "There cannot be less than 0 engine power";
            break;
        case 5:
            std::cin >> terrain_type;
            break;
        default:
            throw "Invalid value";
            break;
    }
}

void Bike::save_to_file(std::ofstream &out) {
    out << BIKE;
    out << brand;
    out << model;
    out << engine_capacity;
    out << engine_power;
    out << terrain_type;
}
