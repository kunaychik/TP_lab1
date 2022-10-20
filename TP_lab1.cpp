#include "Keeper.h"
#include <iostream>

void loop();
bool switch_in_loop(Keeper& interface);
void upload(Keeper& interface);
void add_vehicle(Keeper& interface);
void delete_vehicle(Keeper& interface);
void show(Keeper& interface);
void edit(Keeper& interface);
void save(Keeper& interface);

int main() {

    loop();

    return 0;
}
void save(Keeper& interface) {
    try {
        interface.save();
    }
    catch (const char* txt) {
        std::cout << txt << std::endl;
    }
}

void edit(Keeper& interface) {
    try {
        interface.edit();
    }
    catch (const char* txt) {
        std::cout << txt << std::endl;
    }
}

void show(Keeper& interface) {
    int choice;
    std::cout << "What do you want to see\n" <<
        "1. Show all vehicles in garage\n" <<
        "2. Show all vehicle by one brand" << std::endl;
    std::cin >> choice;
    InvalidInput
        switch (choice) {
        case 1:
            try {
                interface.show();
            }
            catch (const char* txt) {
                std::cout << txt << std::endl;
            }
            break;
        case 2:
            try {
                interface.show_all_vehicle_by_one_brand();
            }
            catch (const char* txt) {
                std::cout << txt << std::endl;
            }
            break;
        default:
            break;
        }
}

void delete_vehicle(Keeper& interface) {
    try {
        interface.delete_vehicle();
    }
    catch (const char* txt) {
        std::cout << txt << std::endl;
    }
}

void add_vehicle(Keeper& interface) {
    try {
        interface.add_new_vehicle();
    }
    catch (const char* txt) {
        std::cout << txt << std::endl;
    }
}

void upload(Keeper& interface) {
    int choice;
    std::cout << "Do you want to try upload data from file?\n" <<
        "1. Yes\n" <<
        "2. No\n" << std::endl;
    try {
        std::cin >> choice;
        InvalidInput;
    }
    catch (const char* txt) {
        std::cout << txt << std::endl;
    }
    if (choice == 1) {
        try {
            interface.upload_from_file();
        }
        catch (const char* txt) {
            std::cout << txt << std::endl;
        }
    }
}

bool switch_in_loop(Keeper& interface) {
    int choice;
    std::cout << "Select action: \n" <<
        "1. Add new vehicle\n" <<
        "2. Delete vehicle\n" <<
        "3. Show\n" <<
        "4. Edit vehicle\n" <<
        "5. Save to file\n" <<
        "6. Exit" << std::endl;
    std::cout << "You select: ";
    try {
        std::cin >> choice;
        InvalidInput
            if (choice <= 0) throw "Invalid input";
    }
    catch (const char* txt) {
        std::cout << txt << std::endl;
    }

    switch (choice) {
    case 1:
        add_vehicle(interface);
        break;
    case 2:
        delete_vehicle(interface);
        break;
    case 3:
        show(interface);
        break;
    case 4:
        edit(interface);
        break;
    case 5:
        save(interface);
        break;
    default:
        return false;
    }
    return true;
}

void loop() {
    Keeper interface;
    upload(interface);

    bool working = true;
    do {
        try {
            working = switch_in_loop(interface);
        }
        catch (const char* txt) {
            std::cout << txt << std::endl;
        }
    } while (working);
}
