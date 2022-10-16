#ifndef GARAGE_H
#define GARAGE_H
#include <fstream>

class Garage {
public:

    virtual void show() = 0;
    virtual void edit() = 0;
    virtual void save_to_file(std::ofstream& out) = 0;

};

#endif GARAGE_H
