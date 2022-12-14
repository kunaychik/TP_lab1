#include "Keeper.h"

Keeper::Keeper() {
    my_garage = nullptr;
    count_of_vehicle = 0;
}

Keeper::~Keeper() {
    for (uint16_t i = 0; i < count_of_vehicle; ++i) {
        delete my_garage[i];
    }
    delete[] my_garage;
}

void Keeper::add_new_vehicle() {
    auto new_vehicle = create_vehicle();
    my_garage = add_vehicle_to_garage(new_vehicle);
}

void Keeper::delete_vehicle() {
    int choice;
    show();
    std::cout << "Select vehicle: ";
    std::cin >> choice;
    InvalidInput;
    if(choice <= 0 || choice > static_cast<int>(count_of_vehicle)) throw "Invalid input";


    auto new_garage = new Garage * [count_of_vehicle - 1];

    for (uint16_t i = 0, j = 0; i < count_of_vehicle; ++i) {
        if(i == choice - 1) continue;
        new_garage[j++] = my_garage[i];
    }
    delete my_garage[choice-1];
    --count_of_vehicle;

    delete[] my_garage;

    my_garage = new_garage;
}

void Keeper::edit() {
    int choice;
    show();
    std::cout << "Select vehicle: ";
    std::cin >> choice;
    InvalidInput;
    if(choice <= 0 || choice > static_cast<int>(count_of_vehicle)) throw "Invalid input";

    my_garage[choice-1]->edit();
}

void Keeper::show() {
    if(!count_of_vehicle) throw "There are no vehicles in garage";
    for (int i = 0; i < count_of_vehicle; ++i) {
        std::cout << i + 1 << ": " << std::endl;
        my_garage[i]->show();
    }
}

void Keeper::save() {
    if(!count_of_vehicle) throw "There are no vehicles in garage";

    std::ofstream out("garage.txt");
    if (!out.is_open()) throw "The file does not open";

    out << count_of_vehicle << std::endl;
    for (size_t i = 0; i < count_of_vehicle; i++) {
        my_garage[i]->save_to_file(out);
    }

    std::cout << "Successful saving\n" << std::endl;
}

void Keeper::upload_from_file() {
    std::ifstream in("garage.txt");
    if (!in.is_open()) throw "File does not exist";

    int count_of_vehicle_from_file;
    in >> count_of_vehicle_from_file;
    int type;
    for (size_t i = 0; i < count_of_vehicle_from_file; i++) {
        in >> type;
        Garage* new_vehicle = nullptr;
        switch (type)
        {
            case BIKE:
                new_vehicle = new Bike(in);
                break;

            case CAR:
                new_vehicle = new Car(in);
                break;

            case BUS:
                new_vehicle = new Bus(in);
                break;
            default:
                break;
        }
        my_garage = add_vehicle_to_garage(new_vehicle);
    }
    std::cout << "Successful upload\n" << std::endl;
}

Garage *Keeper::create_vehicle() {
    int choice;
    std::cout << "Select vehicle\n"<<
                "1. Bike\n" <<
                "2. Car\n" <<
                "3. Bus" << std::endl;

    std::cin >> choice;
    InvalidInput;
    if(choice <= 0 || choice >= 4) throw "Invalid input";
    Garage* new_vehicle = nullptr;

    switch (choice) {
        case 1:
            new_vehicle = new Bike();
            break;
        case 2:
            new_vehicle = new Car();
            break;
        case 3:
            new_vehicle = new Bus();
            break;
        default:
            break;

    }

    return new_vehicle;
}

Garage** Keeper::add_vehicle_to_garage(Garage* new_vehicle) {
    auto new_garage = new Garage * [count_of_vehicle + 1];

    for (uint16_t i = 0; i < count_of_vehicle; ++i) {
        new_garage[i] = my_garage[i];
    }
    ++count_of_vehicle;
    new_garage[count_of_vehicle-1] = new_vehicle;

    delete[] my_garage;

    return new_garage;
}

void Keeper::show_all_vehicle_by_one_brand() {
    if(!count_of_vehicle) throw "There are no vehicles in garage";

    char my_brand[64];
    std::cout << "Brand: " << std::endl;
    std::cin >> my_brand;
    std::cout << "All vehicles in garage by brand: " << my_brand << std::endl;
    for (int i = 0; i < count_of_vehicle; ++i) {
        if(strcmp(my_brand, my_garage[i]->get_brand()) == 0) {
            my_garage[i]->show();
        }
    }
}
