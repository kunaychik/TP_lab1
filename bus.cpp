//
// Created by UserPC on 10/12/2022.
//

#include "bus.h"

Bus::Bus() {
    std::cout << "Enter brand: " << std::endl;
    std::cin >> brand;

    std::cout << "Enter model: " << std::endl;
    std::cin >> model;

    std::cout << "Enter number of passenger seats: " << std::endl;
    std::cin >> num_of_passenger_seats;
    InvalidInput;
    if(num_of_passenger_seats <= 0) throw "There cannot be less than 0 passenger seats";

    std::cout << "Enter max number of passenger: " << std::endl;
    std::cin >> max_num_of_passengers;
    InvalidInput;
    if(max_num_of_passengers <= 0) throw "There cannot be a maximum of passengers less than 0";

    std::cout << "Enter destination: " << std::endl;
    std::cin >> destination;
}

Bus::Bus(std::ifstream &in) {
    in >> brand;
    in >> model;
    in >> num_of_passenger_seats;
    in >> max_num_of_passengers;
    in >> destination;
}

Bus::Bus(const Bus &bus) {
    strcpy_s(brand, 64, bus.brand);
    strcpy_s(model, 64, bus.model);
    num_of_passenger_seats = bus.num_of_passenger_seats;
    max_num_of_passengers = bus.max_num_of_passengers;
    strcpy_s(destination, 64, bus.destination);
}

void Bus::show() {
    std::cout << "Bus." << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Number of passenger seats: " << num_of_passenger_seats << std::endl;
    std::cout << "Maximum number of passengers: " << max_num_of_passengers << std::endl;
    std::cout << "Destination: " << destination << std::endl;
}

void Bus::edit() {
    int choice;
    std::cout << "1. Brand\n" <<
              "2. Model\n" <<
              "3. Number of passenger seats\n" <<
              "4. Maximum number of passengers\n" <<
              "5. Destination" << std::endl;

    std::cin >>choice;
    InvalidInput;

    switch (choice) {
        case 1:
            std::cout << "New Brand: " << std::endl;
            std::cin >> brand;
            break;
        case 2:
            std::cout << "New Model: " << std::endl;
            std::cin >> model;
            break;
        case 3:
            std::cout << "New Number of passenger seats: " << std::endl;
            std::cin >> num_of_passenger_seats;
            InvalidInput;
            if(num_of_passenger_seats <= 0) throw "There cannot be less than 0 passenger seats";
            break;
        case 4:
            std::cout << "New Maximum number of passengers: " << std::endl;
            std::cin >> max_num_of_passengers;
            InvalidInput;
            if(max_num_of_passengers <= 0) throw "There cannot be a maximum of passengers less than 0";
            break;
        case 5:
            std::cout << "New Destination: " << std::endl;
            std::cin >> destination;
            break;
        default:
            throw "Invalid value";
    }
}

void Bus::save_to_file(std::ofstream &out) {
    out << BUS << std::endl;
    out << brand << std::endl;
    out << model << std::endl;
    out << num_of_passenger_seats << std::endl;
    out << max_num_of_passengers << std::endl;
    out << destination << std::endl;
}
