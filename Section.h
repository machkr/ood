#pragma once
#include <string>
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <cassert>
#include "Seat_Row.h"
#include "Seat.h" 

using namespace std;

static const int MAX_SEATS_PER_SECTION = 1000;

// Forward declarations to prevent circular dependecny error
// http://stackoverflow.com/a/628079
class Seat;

class Section
{
private:
    string section_name; 
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
