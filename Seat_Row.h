#pragma once
#include "Seat.h"
#include <string>

using namespace std;

// Forward declarations to prevent circular dependecny error
// http://stackoverflow.com/a/628079
class Seat;

class Seat_Row
{
public:
    static const int MAX_SEATS_PER_ROW = 1000;

private:
    string row_name;
    const Seat* seats[MAX_SEATS_PER_ROW];
    int  number_of_seats;

public:
    Seat_Row(const string& Row_Name);
    void Add_Seat(const Seat* new_seat);
    void Display() const;

    int Number_of_Seats() const { return number_of_seats; }

    const Seat* Get_Seat(int idx) const { return seats[idx]; };
    
    string Get_Seat_Row_Name() const { return row_name; };
};


