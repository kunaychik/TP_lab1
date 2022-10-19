#include "Keeper.h"
#include <iostream>

int main() {
    Keeper interface;
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

    bool working = true;

    do {
        std::cout << "Select action: \n" <<
            "1. Add new vehicle\n" <<
            "2. Delete vehicle\n" <<
            "3. Show all vehicles in garage\n" <<
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
            continue;
        }

        switch (choice) {
        case 1:
            try {
                interface.add_new_vehicle();
            }
            catch (const char* txt) {
                std::cout << txt << std::endl;
            }
            break;
        case 2:
            try {
                interface.delete_vehicle();
            }
            catch (const char* txt) {
                std::cout << txt << std::endl;
            }
            break;
        case 3:
            try {
                interface.show();
            }
            catch (const char* txt) {
                std::cout << txt << std::endl;
            }
            break;
        case 4:
            try {
                interface.edit();
            }
            catch (const char* txt) {
                std::cout << txt << std::endl;
            }
            break;
        case 5:
            try {
                interface.save();
            }
            catch (const char* txt) {
                std::cout << txt << std::endl;
            }
            break;
        default:
            working = false;
            break;
        }

    } while (working);


    return 0;
}
