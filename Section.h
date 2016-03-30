//Just making it for now, also partially meant for me figuring out how Github works. 

#pragma once
#include <string>
#include "Seat.h" //To be determined if we need this header file included. 

using namespace std;

static const int MAX_SEATS_PER_SECTION = 1000;

// Forward declarations to prevent circular dependecny error
// http://stackoverflow.com/a/628079
class Seat;

class Section
{
private:
    string section_name; //TBD if we even want to use this, the diagram had no such variable
    const Seat* seats[MAX_SEATS_PER_SECTION];
    int number_of_seats;
  

public:
    Section(const string& section_name);
    void Add_Seat(const Seat* new_seat);
    void Display() const;
    
    int Number_of_Seats() const { return number_of_seats; }
    
    const Seat* Get_Seat(int idx) const { return seats[idx]; };
    
    string Get_Section_Name() const { return section_name; };
};
