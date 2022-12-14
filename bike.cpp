#include "bike.h"

Bike::Bike() {
    std::cout << "Enter brand: " << std::endl;
    std::cin >> brand;

    std::cout << "Enter model: " << std::endl;
    std::cin >> model;

    std::cout << "Enter engine capacity: " << std::endl;
    std::cin >> engine_capacity;
    InvalidInput;
    if(engine_capacity <= 0) throw "There cannot be less than 0 engine capacity";


    std::cout << "Enter engine power: " << std::endl;
    std::cin >> engine_power;
    InvalidInput;
    if(engine_power <= 0) throw "There cannot be less than 0 engine power";


    std::cout << "Enter type of terrain: " << std::endl;
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
    std::cout << "Bike." << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
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
            std::cout << "New Engine power" << std::endl;
            std::cin >> engine_power;
            InvalidInput;
            if(engine_power <= 0) throw "There cannot be less than 0 engine power";
            break;
        case 5:
            std::cout << "New Type of terrain" << std::endl;
            std::cin >> terrain_type;
            break;
        default:
            throw "Invalid value";
    }
}

void Bike::save_to_file(std::ofstream &out) {
    out << BIKE << std::endl;
    out << brand << std::endl;
    out << model << std::endl;
    out << engine_capacity << std::endl;
    out << engine_power << std::endl;
    out << terrain_type << std::endl;
}

char *Bike::get_brand() {
    return brand;
}
