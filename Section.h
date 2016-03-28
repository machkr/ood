//Just making it for now, also part of me figuring out how Github works. 

#pragma once
#include <string>
#include <seat.h> //To be determined if we need this header file included. 

using namespace std;

class Section
{
private:
    string section_name; //TBD if we even want to use this, the diagram had no such variable

public:
    Section(seat Seat);

    void Display() const;
};
